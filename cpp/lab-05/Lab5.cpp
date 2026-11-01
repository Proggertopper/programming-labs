#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    long long n;
    cout << "Enter n: ";
    cin >> n;

    for (long long q = 1; q <= n; q++) {
        long long q2 = q * q;
        long long q3 = q2 * q;

        if (n % q2 == 0) { 
            if (n % q3 != 0) {      
                cout << q << " ";
            }
        }
    }

    return 0;
}

//int main() {
//
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//    char numChars[110]; 
//    int len = 0;
//
//    char c;
//	cout << "Введіть число: ";
//    while (cin.get(c)) {
//        if (c == '\n' || c == '\r') break; 
//        numChars[len++] = c;
//    }
//
//    for (int i = 0; i < len; i++) {
//        if (numChars[i] != '0' && numChars[i] != '5') {
//            cout << numChars[i];
//        }
//    }
//
//    return 0;
//}
