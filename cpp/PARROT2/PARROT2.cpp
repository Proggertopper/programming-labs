#include <iostream>
#include <windows.h>
using namespace std;

int main() {


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть рядок :\n";

    while (true) {
        cout << "> ";
        char ch;
		cin.get(ch);

        if (ch == '\n') break;   

        cout << ch;              

        while (true) {           
            cin.get(ch);
            if (ch == '\n') break;
            cout << ch;
        }
        cout << "\n";
    }

    return 0;
}
