/*
font.cpp

Copyright (c) 19 Yann BOUCHER (yann)

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

#include "font.hpp"

namespace graphics
{

const Glyph &Font::get(char32_t c) const
{
#if 1
    if (c < m_font_cache.size() && m_font_cache[c])
    {
        return *m_font_cache[c];
    }
    else
    {
        if (c < m_font_cache.size())
        {
            m_font_cache[c] = std::make_unique<Glyph>(read_glyph(c));
            return *m_font_cache[c];
        }
        else
        {
            log_serial("Character 0x%x (%c) isn't in cache\n", c, c);
            assert(false && "fix this");
            static Glyph g = read_glyph(c);
            return g;
        }
    }
#else
    static Glyph g = read_glyph(c);
    return g;
#endif
}

}
