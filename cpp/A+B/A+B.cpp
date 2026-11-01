#include <iostream>
using namespace std;

int main(int args )
{
    int a, b;

    if (args < 2) {
        cout << "Введіть два числа : ";
    }
    cin >> a >> b;
    int sum = a + b;
    cout << sum;
}