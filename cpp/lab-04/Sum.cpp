#include <iostream>
#include <windows.h>
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    cout << "Введіть послідовність цілих чисел. Нуль – ознака кінця.\n";

    int x;
    long long sum = 0;
    int i = 1;

    while (true) {
        cout << "a[" << i << "]= ";
        cin >> x;
        if (x == 0) break;
        sum += x;
        i++;
    }

    cout << "SUM=" << sum << "\n";
    return 0;
}

