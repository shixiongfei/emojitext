#include <locale.h>
#include "codepage.h"
#include "varstring.h"
#include "emoji.h"

int main(int argc, char *argv[]) {
    // ����ϵͳ����(��ASCII��Ҫ)
    CodePage::setCodePage("GBK");

    // wprintf��ʾ������Ҫ
    setlocale(LC_CTYPE, "");

    const wchar_t testString[] = { 
        L'H', L'e', L'l', L'l', L'o', 
        L'W', L'o', L'r', L'l', L'd', L',', 
        L'��', L'��', L'��', L'��', L'��', 
        0xD83D, 0xDE00, 0x00 };

    VarString varstr(testString);

    for (int i = 0; i < varstr.length(); ++i) {
        if (varstr[i].isEmoji()) {
            Emoji emoji(varstr[i]);

            printf("Emoji: %s\n", emoji.data().name.c_str());
        }
        else {
            std::wstring utf16 = varstr[i].toUTF16();
            wprintf(L"%ls\n", utf16.c_str());
        }
    }

    return 0;
}
