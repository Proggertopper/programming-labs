#include <iostream>
#include <windows.h>s
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, m, k;

    cout << "Введіть рядки A: ";
    cin >> n;

    cout << "Введіть стовпці A = рядки B: ";
    cin >> m;

    cout << "Введіть стовпці B: ";
    cin >> k;

    int A[10][10], B[10][10], C[10][10];

    cout << "\nМатриця A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cout << "\nМатриця B:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> B[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {

            C[i][j] = 0;

            for (int t = 0; t < m; t++)
                C[i][j] += A[i][t] * B[t][j];
        }
    }

    cout << "\nРезультат:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            cout << C[i][j] << " ";

        cout << endl;
    }

    return 0;
}
