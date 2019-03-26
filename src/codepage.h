#pragma once

#include <string>

class CodePage {
public:
    static void setCodePage(const char *codepage);
    static const char *getCodePage(void);

private:
    CodePage(void);
    ~CodePage(void);

private:
    static std::string s_codepage;
};
