#include <iostream>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x0, y0, R, x, y;

    cout << "Введіть центр кола (x0 y0): ";
    cin >> x0 >> y0;

    cout << "Введіть радіус R: ";
    cin >> R;

    cout << "Введіть координати точки (x y): ";
    cin >> x >> y;

    if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= R * R)
        cout << "Точка (" << x << ", " << y << ") потрапляє в коло з центром ("
        << x0 << ", " << y0 << ") радіуса " << R << endl;
    else
        cout << "Точка (" << x << ", " << y << ") не потрапляє в коло з центром ("
        << x0 << ", " << y0 << ") радіуса " << R << endl;

    return 0;
}
