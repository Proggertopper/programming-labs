#include <iostream>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    cout << "Працює інформаційна система факультету прикладної математики:\n";
    cout << "1. Новини дня\n";
    cout << "2. Анекдот тижня\n";
    cout << "3. Автора !!!\n";
    cout << "Введіть відповідний номер і натисніть ENTER: ";
    cin >> choice;

    cout << endl;

    switch (choice) {
    case 1:
        cout << "Новини дня: Сьогодні день Хижі!" << endl;
        break;

    case 2:
        cout << "Анекдот тижня: Колобок повесился." << endl;
        break;

    case 3:
        cout << "Автор: Студент ФПМ." << endl;
        break;

    default:
        cout << "Невірний вибір. Ще раз." << endl;
        break;
    }

    return 0;
}
