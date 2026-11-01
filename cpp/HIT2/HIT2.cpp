#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <windows.h>

using namespace std;

int main() {


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0)); 

    int R = rand() % 11 + 50; // 50 60
    int x0 = rand() % (1001-2 * R) + R; // -10  10 R до 1000-R
    int y0 = rand() % (1001 - 2 * R) + R;
	

    cout << "Програма задумала коло з випадковим центром і радіусом!\n";
    //cout << " x0=" << x0 << " y0=" << y0 << " R=" << R << "\n";

    double x, y;
    double prevDist = -1;

    while (true) {
        cout << "Введіть x y: ";
        cin >> x >> y;

        
        double dist = (x - x0) * (x - x0) + (y - y0) * (y - y0);
        double R2 = R * R;

        if (dist <= R2) {
            cout << "Точка (" << x << ", " << y << ") потрапила в коло з центром "
                << "(" << x0 << ", " << y0 << ") радіуса " << R << "\n";
            break;
        }

        if (prevDist >= 0) {
            if (dist < prevDist)
                cout << "Тепліше\n";
            else
                cout << "Холодніше\n";
        }

        prevDist = dist;
    }


    return 0;
}
