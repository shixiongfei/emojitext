#pragma once

#include <utf8.h>
#include <string>

class VarChar {
public:
    VarChar(ucs4_t ch);
    virtual ~VarChar(void);

    std::string toUTF8(void);
    std::wstring toUTF16(void);

    bool isEmoji(void);

private:
    ucs4_t m_ucs4ch;
};
