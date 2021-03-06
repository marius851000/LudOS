/*
smbios.cpp

Copyright (c) 28 Yann BOUCHER (yann)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "smbios.hpp"

#include "i686/pc/external/dmidecode.hpp"

#include "i686/pc/serial/serialdebug.hpp"

#include "utils/bitops.hpp"
#include "utils/virt_machine_detect.hpp"
#include "panic.hpp"

#include "mem/memmap.hpp"

#include <string.h>

SMBIOSEntryPoint *SMBIOS::locate()
{
    const size_t len = 0x10000;
    uint8_t *addr = (uint8_t*)Memory::mmap(0x0F0000, len, Memory::Read);
    uint8_t* mem = addr;
    int length, i;
    uint8_t checksum;
    while (mem < addr + len)
    {
        if (mem[0] == '_' && mem[1] == 'S' && mem[2] == 'M' && mem[3] == '_')
        {
            length = mem[5];
            checksum = 0;
            for(i = 0; i < length; i++)
            {
                checksum += mem[i];
            }
            if (checksum == 0) break;
        }
        mem += 16;
    }
    if (mem >= addr + len)
    {
        log(Debug, "no SMBIOS found\n");

        Memory::unmap(addr, len);
        return nullptr;
    }
    else
    {
        log(Debug, "SMBIOS found at : %p\n", mem);
        entry_point = reinterpret_cast<SMBIOSEntryPoint*>(mem);
        log(Debug, " SMBIOS version : %d.%d\n", entry_point->MajorVersion, entry_point->MinorVersion);
        log(Debug, " SMBIOS entries : %d\n", entry_point->NumberOfStructures);

        return entry_point;
    }
}

SMBIOSBIOSInfo* SMBIOS::bios_info()
{
    if (entry_point)
    {
        uintptr_t addr = (uintptr_t)Memory::mmap(entry_point->TableAddress, entry_point->TableLength, Memory::Read);
        uintptr_t mem = addr;
        while (mem < entry_point->TableAddress + entry_point->TableLength)
        {
            auto* tag = reinterpret_cast<SMBIOSTag*>(mem);
            if (tag->type == 127)
            {
                break;
            }
            if (tag->type == 0)
            {
                SMBIOSBIOSInfo* info = reinterpret_cast<SMBIOSBIOSInfo*>(mem);

                uint8_t* tag_end = reinterpret_cast<uint8_t*>(mem + tag->length - 1);

                log(Debug, " BIOS Vendor : %s\n", get_string(tag_end, info->vendor));
                log(Debug, " BIOS Version : %s\n",get_string(tag_end, info->version));
                log(Debug, " BIOS Release date : %s\n", get_string(tag_end, info->release_date));

                return info;
            }

            mem += tag->length - 1;
            mem = find_strings_end(reinterpret_cast<uint8_t*>(mem));
        }

        return nullptr;
    }
    else
    {
        warn("Tried to access inexistent SMBIOS !");
        return nullptr;
    }
}

SMBIOSCPUInfo *SMBIOS::cpu_info()
{
    if (entry_point)
    {
        uintptr_t addr = (uintptr_t)Memory::mmap(entry_point->TableAddress, entry_point->TableLength, Memory::Read);
        uintptr_t mem = addr;
        while (mem < entry_point->TableAddress + entry_point->TableLength)
        {
            auto* tag = reinterpret_cast<SMBIOSTag*>(mem);
            if (tag->type == 127)
            {
                break;
            }
            if (tag->type == 4)
            {
                SMBIOSCPUInfo* info = reinterpret_cast<SMBIOSCPUInfo*>(mem);

                uint8_t* tag_end = reinterpret_cast<uint8_t*>(mem + tag->length - 1);

                log(Debug, " Processor Type : ");
                switch (info->cpu_type)
                {
                case 0:
                case 1:
                case 2:
                default:
                    log(Debug, "Unknown\n");
                    break;
                case 3:
                    log(Debug, "CPU\n");
                    break;
                case 4:
                    log(Debug, "Math processor\n");
                    break;
                case 5:
                    log(Debug, "DSP processor\n");
                    break;
                case 6:
                    log(Debug, "Video processor\n");
                    break;
                }

                log(Debug, " Processor family : %s\n", dmi_processor_family(info->family));
                log(Debug, " Processor socket : %s\n", get_string(tag_end, info->socket+1));
                log(Debug, " Processor manufacturer : %s\n", get_string(tag_end, info->manufacturer+1));
                if (strncmp(get_string(tag_end, info->manufacturer+1), "QEMU", 4) == 0)
                {
                    running_qemu = true;
                }
                log(Debug, " Processor version : %s\n", get_string(tag_end, info->version+1));
                log(Debug, " Processor voltage : ");
                if (bit_check(info->voltage, 7))
                {
                    log(Debug, "%.1fv\n", (info->voltage & 0b1111111)/10.0);
                }
                else
                {
                    log(Debug, "%.1fv\n", info->voltage == 0 ? 5 : info->voltage == 1 ? 3.3 : info->voltage == 2 ? 2.9 : -1);
                }

                log(Debug, " Processor speed : %dMHz\n", info->curr_speed);

                return info;
            }

            mem += tag->length - 1;
            mem = find_strings_end(reinterpret_cast<uint8_t*>(mem));
        }

        return nullptr;
    }
    else
    {
        warn("Tried to access inexistent SMBIOS !");
        return nullptr;
    }
}

const char *SMBIOS::get_string(uint8_t *offset, uint8_t number)
{
    uint8_t idx = 1;
    while (offset[0] != '\0' || offset[1] != '\0')
    {
        if (idx == number) { return reinterpret_cast<const char*>(offset); }

        if (offset[0] == '\0') ++idx;
        ++offset;
    }

    return nullptr;
}

uintptr_t SMBIOS::find_strings_end(uint8_t* offset)
{
    while (offset[0] != '\0' || offset[1] != '\0')
    {
        ++offset;
    }
    return (reinterpret_cast<uintptr_t>(offset)) + 2;
}
