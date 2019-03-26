#include "varstring.h"
#include "codepage.h"

VarString::VarString(void)
{
}

VarString::VarString(const char * text)
{
    int n, len = (int)strlen(text);
    const char *ptr = nullptr;
    char *buffer = nullptr;
    ucs4_t ch;

    if (utf8_isutf8(text, len)) {
        ptr = text;
    }
    else {
        buffer = new char[len * 2];
        ptr = buffer;
        len = utf8_frommultibyte(CodePage::getCodePage(), text, buffer);
        buffer[len] = 0;
    }

    while (len > 0) {
        n = utf8_tounicode(ptr, &ch);

        if (n <= 0)
            break;

        m_varchar.push_back(ch);

        ptr += n;
        len -= n;
    }

    if (buffer)
        delete[] buffer;
}

VarString::VarString(const wchar_t * text)
{
    int i = 0, len = (int)wcslen(text);
    ucs4_t ch;

    while (i < len) {
        if ((0xD800 <= text[i] && text[i] <= 0xDBFF) &&
            (0xDC00 <= text[i + 1] && text[i + 1] <= 0xDFFF)) {
            ch = 0x10000;
            ch += (text[i++] & 0x03FF) << 10;
            ch += (text[i++] & 0x03FF);
        }
        else {
            ch = text[i++];
        }

        m_varchar.push_back(ch);
    }
}

VarString::VarString(const std::string & text)
    : VarString(text.c_str())
{
}

VarString::VarString(const std::wstring & text)
    : VarString(text.c_str())
{
}

VarString::~VarString(void)
{
}

VarChar & VarString::operator[](int index)
{
    return m_varchar[index];
}

VarChar VarString::operator[](int index) const
{
    return m_varchar[index];
}

int VarString::length(void) const
{
    return (int)m_varchar.size();
}


