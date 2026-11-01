#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int n, m;

    cout << "Кількість рядків: ";
    cin >> n;

    cout << "Кількість стовпців: ";
    cin >> m;

    int A[10][10];

    cout << "\nВведіть матрицю:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cout << "\nТранспонована матриця:\n";

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++)
            cout << A[i][j] << " ";

        cout << endl;
    }

    return 0;
}
