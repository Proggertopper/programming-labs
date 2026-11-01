#include <iostream>
using namespace std;

int main() {
    double X;
    cout << "X = ";
    cin >> X;

    if (X < 0) {
        X = -X;
        cout << "| " << -X << " | = " << X << endl;
    }
    else 
    cout << "| " << X << " | = " << X << endl;
    return 0;
}
