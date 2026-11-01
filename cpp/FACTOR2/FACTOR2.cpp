#include <iostream>
using namespace std;
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {

        cout << "N = ";

        double temp;
        cin >> temp;

        
        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: N must be a number, not a string!\n";
            continue;
        }

        
        char extra = cin.peek();
        if (extra != '\n' && extra != ' ') {
            cin.ignore(1000, '\n');
            cout << "Error: Wrong format! Extra characters after number.\n";
            continue;
        }

        cin.ignore(1000, '\n'); 

        if (temp != (int)temp) {
            cout << "Error: N must be natural, not real!\n";
            continue;
        }

        int N = (int)temp;

        if (N <= 0) {
            cout << "Error: N мусить бути додатнім, не negative!\n";
            continue;
        }

        long long result = 1;
        for (int i = 1; i <= N; i++)
            result *= i;

        cout << N << "! = " << result << "\n";
        break;
    }

    return 0;
}
