/*
 * codepage.cpp
 *
 * copyright (c) 2019-2021 Xiongfei Shi
 *
 * author: Xiongfei Shi <xiongfei.shi(a)icloud.com>
 * license: Apache-2.0
 *
 * https://github.com/shixiongfei/emojitext
 */

#include "codepage.h"

std::string CodePage::s_codepage = "ASCII";

void CodePage::setCodePage(const char *codepage) {
  CodePage::s_codepage = codepage;
}

const char *CodePage::getCodePage(void) { return CodePage::s_codepage.c_str(); }

CodePage::CodePage(void) {}

CodePage::~CodePage(void) {}
