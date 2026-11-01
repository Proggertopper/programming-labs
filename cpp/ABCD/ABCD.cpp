#include <iostream>
#include <windows.h>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int A, B, C, D, t;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;
    cout << "C = ";
    cin >> C;
    cout << "D = ";
    cin >> D;

    cout << "A = " << A << "  B = " << B << "  C = " << C << "  D = " << D << endl;

    if (A > B) {
        t = A;
        A = B;
        B = t;
    }
    else if (B > C) {
        t = B;
        B = C;
        C = t;
    }
    else if (C > D) {
        t = C;
        C = D;
        D = t; 
    }
    else  if (A > B) { 
        t = A;
        A = B;
        B = t; 
    }
    else if (B > C) { 
        t = B;
        B = C;
        C = t; 
    }
    else if (A > B) {
        t = A;
        A = B; 
        B = t;
    }

    cout << "Після зміни: A = " << A << "  B = " << B << "  C = " << C << "  D = " << D << endl;
    return 0;
}