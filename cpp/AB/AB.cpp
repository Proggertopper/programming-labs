#include <iostream>
#include <windows.h>
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    int A, B, temp;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;

    cout << "A = " << A << "  B = " << B << endl;

    if (A > B) {
        temp = A;
        A = B;
        B = temp;
    }

    cout << "Після зміни : A = " << A << "  B = " << B << endl;
    return 0;
}
