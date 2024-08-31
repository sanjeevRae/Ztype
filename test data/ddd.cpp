#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 20;
cfi.dwFontSize.X = 0;
cfi.dwFontSize.Y = 24;
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
wcscpy(cfi.FaceName, L"Consolas");
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
cout << "Happy\n";

return 0;
}
