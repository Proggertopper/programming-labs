#include <iostream>
#include <windows.h>
using namespace std;

void myStrcat(char s1[], char s2[]);
int myStrcspn( char s1[], char s2[]);

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1 - strcat\n";
        cout << "2 - strcspn\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            char s1[400], s2[200];

            cout << "Введіть перший рядок: ";
            cin.getline(s1, 200);

            cout << "Введіть другий рядок: ";
            cin.getline(s2, 200);

             myStrcat(s1, s2);

            cout << "Результат: " << s1 << endl;
        }

        else if (choice == 2) {
            char s1[200], s2[200];

            cout << "Введіть перший рядок: ";
            cin.getline(s1, 200);

            cout << "Введіть другий рядок: ";
            cin.getline(s2, 200);

            int result = myStrcspn(s1, s2);

            cout << "Результат: " << result << endl;
        }

    } while (choice != 0);

    return 0;
}
