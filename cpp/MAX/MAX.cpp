#include <iostream>
#include <windows.h>
using namespace std;

int main() {


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    cout << "Введіть послідовність цілих чисел. Нуль – ознака кінця.\n";

    int x;
    int max = 0;
    int i = 1;

    while (true) {
        cout << "a[" << i << "]=";
        cin >> x;
        if (x == 0) break;

        else if (x > max) {
            max = x;
        }

        i++;
    }

    cout << "MAX=" << max << "\n";
    return 0;
}
