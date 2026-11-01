#include <iostream>
#include <windows.h>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

double F(double x)
{
    if (x > 2 && x < 3)
        return exp(sqrt(x + 2)) * (1.0 / 7.0 + log(sqrt(x))) / (3.5 + x);
    else if (x > -2 && x <= 2)
        return x * x;
    else
        return x;
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
            return value;

        cout << "Некоректне значення. Введіть число ще раз." << endl;
    }
}

bool parseDouble(const string& str, double& value)
{
    stringstream ss(str);
    char extra;
    return (ss >> value) && !(ss >> extra);
}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, b, h;

    cout << "Лабораторна робота №6, завдання 1" << endl;
    cout << "_________________________________" << endl;

    if (argc >= 4)
    {
        if (!parseDouble(argv[1], a) || !parseDouble(argv[2], b) || !parseDouble(argv[3], h))
        {
            cout << "Помилка: параметри командного рядка мають бути числами." << endl;
            return 1;
        }

        if (h < 1e-6)
        {
            cout << "Крок h не може бути меншим за 1e-6." << endl;
            return 1;
        }

        if ((b - a) * h < 0)
        {
            cout << "Неправильно задано напрямок кроку h." << endl;
            return 1;
        }
    }
    else
    {
        cout << endl;
        cout << "Введіть інтервал [a;b] і крок h змінювання x:" << endl;

        while (true)
        {
            a = readDouble("a=");
            b = readDouble("b=");
            h = readDouble("h=");

            if (h == 0)
            {
                cout << "Крок h не може дорівнювати 0. Введіть дані ще раз." << endl;
                continue;
            }

            if ((b - a) * h < 0)
            {
                cout << "Неправильно задано напрямок кроку h. Введіть дані ще раз." << endl;
                continue;
            }

            break;
        }
    }

    cout << endl;
    cout << "Результати обчислень:" << endl;
    cout << "_____________________" << endl;

    cout << fixed << setprecision(6);

    if (h > 0)
    {
        for (double x = a; x <= b + 1e-9; x += h)
        {
            cout << "x=" << x << "\ty=" << F(x) << endl;
        }
    }
    else
    {
        for (double x = a; x >= b - 1e-9; x += h)
        {
            cout << "x=" << x << "\ty=" << F(x) << endl;
        }
    }

    return 0;
}
