#include <iostream>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int A, B, C, temp;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;
    cout << "C = ";
    cin >> C;

    cout << "A = " << A << "  B = " << B << "  C = " << C << endl;

    if (A > B) {
        temp = A;
        A = B;
        B = temp;
    }
    else if (B > C) {
        temp = B;
        B = C;
        C = temp;
    }
    else if (A > B) { 
        temp = A;
        A = B;
        B = temp;
    }

    cout << "Після зміни: A = " << A << "  B = " << B << "  C = " << C << endl;
    return 0;
}
