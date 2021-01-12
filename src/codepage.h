/*
 * codepage.h
 *
 * copyright (c) 2019-2021 Xiongfei Shi
 *
 * author: Xiongfei Shi <xiongfei.shi(a)icloud.com>
 * license: Apache-2.0
 *
 * https://github.com/shixiongfei/emojitext
 */

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
