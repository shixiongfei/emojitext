#pragma once

#include <utf8.h>
#include <string>

class VarChar {
public:
    VarChar(ucs4_t ch);
    VarChar(const VarChar &ch);
    virtual ~VarChar(void);

    std::string toUTF8(void) const;
    std::wstring toUTF16(void) const;
    ucs4_t toUCS4() const;

    bool isEmoji(void) const;

private:
    ucs4_t m_ucs4ch;
};
