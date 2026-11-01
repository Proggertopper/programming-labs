#include <iostream>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        cout << "Працює інформаційна система ФПМ:\n";
        cout << "1. Новини дня\n";
        cout << "2. Анекдот тижня\n";
        cout << "3. Автора!\n";
        cout << "0. Вихід\n";
        cout << "Введіть відповідний номер та натисніть ENTER.\n";

        cin >> choice;

        if (choice == 1)
            cout << "Новини дня: Крута олімпіада від Хижі !\n";
        if (choice == 2)
            cout << "Анекдот тижня: У прогера працює програма як треба\n";
        if (choice == 3)
            cout << "Автор: студент групи ФПМ.\n";

    } while (choice);

    return 0;
}
