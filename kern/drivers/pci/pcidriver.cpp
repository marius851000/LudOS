/*
pcidriver.cpp

Copyright (c) 14 Yann BOUCHER (yann)

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

#include "pcidriver.hpp"

#include "pci.hpp"
#include "utils/logging.hpp"

#include <string.hpp>

extern "C" int start_pci_driver_ctors;
extern "C" int end_pci_driver_ctors;

namespace pci::detail
{
PciDriverEntry drivers[max_drivers];
PciDriverEntry* driver_list_ptr = drivers;
}

void PciDriver::interface_init()
{
    using namespace pci::detail;
    for (const auto& dev : pci::devices)
    {
        for (PciDriverEntry* ptr = drivers; ptr < driver_list_ptr; ++ptr)
        {
            (*ptr)(dev);
        }
    }
}

class TestDriver : public PciDriver
{
public:
    virtual void init() {}

    virtual std::string name() const { return "PCI Test driver"; }

    static bool accept(const pci::PciDevice& dev)
    {
        return false;
    }
};

ADD_PCI_DRIVER(TestDriver)