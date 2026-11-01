#include <iostream>
#include <windows.h>
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    

    int x1, x2, y1, y2;

    cout << "Введіть першу цифру числа X: ";
    cin >> x1;
    cout << "Введіть другу цифру числа X: ";
    cin >> x2;

    cout << "Введіть першу цифру числа Y: ";
    cin >> y1;
    cout << "Введіть другу цифру числа Y: ";
    cin >> y2;

    cout << "Сума чисел X + Y = " << (x1 * 10 + x2) + (y1 * 10 + y2) << endl;

    return 0;
}