#include <iostream>
#include <windows.h>
using namespace std;

bool Is_Prime(int n) {
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int A, B;
    int count = 0;


    cout << "Програма рахує кількість простих чисел на проміжку [A, B].\n";

    cout << "Введіть число A (менше або рівне B): ";
    cin >> A;

    cout << "Введіть число B (більше або рівне A): ";
    cin >> B;

    if (A > B) {
        cout << "Помилка: A повинно бути менше або рівне B!\n";
        return 1; 
    }

    for (int i = A; i <= B; i++) {
        if (Is_Prime(i)) {
            count++;
        }
    }

    cout << "На проміжку від " << A << " до " << B << " знайдено "<< count
        << " простих чисел.\n";

    return 0;
}
