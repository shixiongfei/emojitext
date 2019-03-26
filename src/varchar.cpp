#include "varchar.h"

#ifndef __WCHAR_MAX__
#define __WCHAR_MAX__ WCHAR_MAX
#endif /* WCHAR_MAX */

VarChar::VarChar(ucs4_t ch)
    : m_ucs4ch(ch)
{
}

VarChar::~VarChar(void)
{
}

std::string VarChar::toUTF8(void)
{
    char utf8[8] = { 0 };
    utf8_fromunicode(utf8, m_ucs4ch);
    return std::string(utf8);
}

std::wstring VarChar::toUTF16(void)
{
    wchar_t utf16[3] = { 0 };

    if (0x10000 <= m_ucs4ch && m_ucs4ch <= 0x10FFFF) {
        int i = 0;
        ucs4_t code = m_ucs4ch - 0x10000;
        utf16[i++] = 0xD800 | (code >> 10);
        utf16[i++] = 0xDC00 | (code & 0x3FF);
    }
    else {
        utf16[0] = m_ucs4ch & __WCHAR_MAX__;
    }
    return std::wstring(utf16);
}

bool VarChar::isEmoji(void)
{
    return false;
}
