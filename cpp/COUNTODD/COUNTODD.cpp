#include <iostream>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int x;
    int count = 0;

    while (true) {
        cout << "Введіть число = ";
        cin >> x;
        if (x == 0) break;
        if (x % 2 != 0) count++;
    }

    cout << "Зустрілося " << count << " непарних числа.\n";
    return 0;
}
