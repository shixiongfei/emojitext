#include "codepage.h"
#include "varstring.h"

int main(int argc, char *argv[]) {
    // ����ϵͳ����(��ASCII��Ҫ)
    CodePage::setCodePage("GBK");

    VarString varstr(L"HelloWorld, ������磡");

    for (int i = 0; i < varstr.length(); ++i) {
        std::string utf8 = varstr[i].toUTF8();
        printf("%s, %i\n", utf8.c_str(), varstr[i].isEmoji());
    }

    return 0;
}
