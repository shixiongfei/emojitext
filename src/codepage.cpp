#include "codepage.h"

std::string CodePage::s_codepage;

void CodePage::setCodePage(const char * codepage)
{
    CodePage::s_codepage = codepage;
}

const char * CodePage::getCodePage(void)
{
    return CodePage::s_codepage.c_str();
}

CodePage::CodePage(void)
{
}

CodePage::~CodePage(void)
{
}
