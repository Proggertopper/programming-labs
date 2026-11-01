#include <iostream>
#include <windows.h>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

double task2(int n, double x)
{
    return pow(-1, n) * pow(x, n + 1) / (n + 1);
}

double readDouble(const string& str)
{
    string line;
    double value;
    char extra;

    while (true)
    {
        cout << str;
        getline(cin, line);

        if (line.empty())
        {
            cout << "Ви нічого не ввели. Спробуйте ще раз." << endl;
            continue;
        }

        stringstream ss(line);

        if ((ss >> value) && !(ss >> extra))
        {
            return value;
        }

        cout << "Некоректне значення. Введіть число ще раз." << endl;
    }
}

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    double x, E;
    double S5 = 0.0;
    double S = 0.0;
    double a;
    int n = 0;
    int k = 0;

    cout << "Лабораторна робота №6, завдання 2" << endl;
    cout << "_________________________________" << endl;

    cout << endl;
    cout << "Введіть значення x у діапазоні -1<x<=1:" << endl;

    do
    {
        x = readDouble("x=");
        if (x <= -1 || x > 1)
            cout << "Помилка: x має належати діапазону -1 < x <= 1. Спробуйте ще раз." << endl;
    } while (x <= -1 || x > 1);

    cout << "Введіть потрібну точність обчислення суми ряду:" << endl;

    do
    {
        E = readDouble("E=");
        if (E <= 0)
            cout << "Помилка: E має бути більше 0. Спробуйте ще раз." << endl;
    } while (E <= 0);

    for (int i = 0; i < 5; i++)
    {
        S5 += task2(i, x);
    }

    do
    {
        a = task2(n, x);
        S += a;
        n++;
        k++;
    } while (fabs(a) >= E);

    cout << endl;
    cout << "Результати обчислень:" << endl;
    cout << "_____________________" << endl;
    cout << endl;

    cout << setprecision(6);

    cout << "Сума перших п'яти членів ряду становить:" << endl;
    cout << "S5=" << S5 << endl;

    cout << "Сума ряду з точністю " << E << " становить:" << endl;
    cout << "S=" << S << endl;

    cout << "Кількість виконаних ітерацій: " << k << endl;

    cout << "Результат обчислень за допомогою стандартних математичних функцій:" << endl;
    cout << "ln(" << 1 + x << ")=" << log(1 + x) << endl;

    return 0;
}