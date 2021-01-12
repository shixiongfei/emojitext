/*
 * varchar.h
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
#include <utf8.h>

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
