#include "codepage.h"
#include "varstring.h"

int main(int argc, char *argv[]) {
    // 设置系统编码(仅ASCII需要)
    CodePage::setCodePage("GBK");

    VarString varstr(L"HelloWorld, 你好世界！");

    for (int i = 0; i < varstr.length(); ++i) {
        std::string utf8 = varstr[i].toUTF8();
        printf("%s, %i\n", utf8.c_str(), varstr[i].isEmoji());
    }

    return 0;
}
