#include <iostream>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    cout << "Введіть послідовність цілих чисел. Нуль – ознака кінця.\n";
    

    int x;
    long long prod = 1;
    bool found = false;
    int i = 1;

    while (true) {
        cout << "a[" << i << "]=";
        cin >> x;
        if (x == 0) break;

        if (x % 2 == 0) {
            prod *= x;
            found = true;
        }
        i++;
    }

    if (!found) prod = 0;
    cout << "ДОБУТОК=" << prod << "\n";



    return 0;
}