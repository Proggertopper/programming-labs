#include <iostream>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, m;

    cout << "Рядки A: ";
    cin >> n;

    cout << "Стовпці A: ";
    cin >> m;

    int A[10][10], AT[10][10], B[10][10], C[10][10];

    cout << "\nМатриця A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cout << "\nМатриця B (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> B[i][j];

  
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            AT[j][i] = A[i][j];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            C[i][j] = 0;

            for (int t = 0; t < m; t++)
                C[i][j] += B[i][t] * AT[t][j];
        }
    }

    cout << "\nРезультат:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";

        cout << endl;
    }

    return 0;
}
