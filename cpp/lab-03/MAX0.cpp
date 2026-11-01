#include <iostream>
using namespace std;

int main() {
    int A, B, Max;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;

    cout << "A = " << A << "  B = " << B << endl;

    if (A > B)
        Max = A;
    else
        Max = B;

    cout << "Max(" << A << ", " << B << ") = " << Max << endl;
    return 0;
}