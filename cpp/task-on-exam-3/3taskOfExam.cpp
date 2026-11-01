#include <iostream>
#include <windows.h>
using namespace std;

void transposeMatrix(int** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[n - 1 - j][n - 1 - i];
            a[n - 1 - j][n - 1 - i] = temp;
        }
    }
}

int main()
{
    int N;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введіть розмір матриці N*N від 1 до 100: ";
    cin >> N;
    while (N < 1 || N > 100)
    {
        cout << "N має бути в діапазоні від 1 до 100. Введіть ще раз: ";
        cin >> N;
    }

    int** a = new int* [N];
    for (int i = 0; i < N; i++)
    {
        a[i] = new int[N];
    }

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    }

    transposeMatrix(a, N);

    cout << "\nМатриця після транспонування:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < N; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}


