/*
 * varstring.h
 *
 * copyright (c) 2019-2021 Xiongfei Shi
 *
 * author: Xiongfei Shi <xiongfei.shi(a)icloud.com>
 * license: Apache-2.0
 *
 * https://github.com/shixiongfei/emojitext
 */

#pragma once

#include "varchar.h"
#include <vector>

class VarString {
public:
  VarString(void);
  VarString(const char *text);
  VarString(const wchar_t *text);
  VarString(const std::string &text);
  VarString(const std::wstring &text);
  virtual ~VarString(void);

  VarChar &operator[](int index);
  VarChar operator[](int index) const;

  int length(void) const;

private:
  std::vector<VarChar> m_varchar;
};
