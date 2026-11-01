#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "N = ";
    cin >> N;//7

    if (N == 0) {
        cout << "F(0) = 0\n";
        return 0;
    }
    else if (N == 1) {
        cout << "F(1) = 1\n";
        return 0;
    }

     long f0 = 0, f1 = 1, fN = 0;

    for (int i = 2; i <= N; i++) {
		fN = f0 + f1;// 8 13 21
        f0 = f1;//3 5 8
        f1 = fN;//5 8 13
    }

    cout << "F(" << N << ") = " << fN << "\n";
    return 0;
}

