#include <iostream>
using namespace std;

int main()
{
    const int max = 100;
    int a[max];
    int N;
    int sum=0;

    cout << "N = ? ";
    cin >> N;

    if (N < 1 || N > max)
    {
        cout << "Error N must be from 1 to " << max << endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        cout << "a[" << i + 1 << "] = ? ";
        cin >> a[i];
    }

    cout << "a[1.." << N << "] = ";
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
		sum += a[i];
    }
    cout << "\nsum = " << sum << endl;
    return 0;
}
