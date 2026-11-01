#include <iostream>
#include <windows.h>
#include <io.h>
using namespace std;


//void changeVariable(int arr[], int i , int j) {
//	int help = arr[i];
//	arr[i] = arr[j];
//	arr[j] = help;
//}

void changeVariable(int& a, int& b) {
	int help = a;
	a = b;
	b = help;
}

void sortArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				/*int help = arr[i];
				arr[i] = arr[j];
				arr[j] = help;*/
				changeVariable(arr[i] , arr[j]);
			}
		}
	}
}



bool isNonIncreasing(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		if (arr[i] > arr[i - 1]) {
			return false;
		}
	}
	return true;
}

void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool input = _isatty(_fileno(stdin));

	const int max_size = 100;

	int n;
	int m;
	int cSize =0;
	int dSize = 0;

	if(input)
		cout << "Введіть розмір массиву А(n):" ;
	cin >> n;

	if (input)
		cout << "Введіть розмір массиву B(m):" ;
	cin >> m;

	if (n < 1 || n > max_size || m < 1 || m > max_size) {
		cout << "Розмір массиву повинен бути в межах від 1 до " << max_size << endl;
		return 1;
	}

	int A[max_size] = {};

	int B[max_size] = {};


	int C[max_size * 2] = {};

	int D[max_size * 2] = {};

	


	if (input)
	cout << "\nВведіть елементи вектору А :" ;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	if (input)
	cout << "\nВведіть елементи вектору B :";

	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < n; i++) {
		if (A[i] % 2 == 0 ) {
			C[cSize] = A[i];
			cSize++;
		}
		else {
			D[dSize] = A[i];
			dSize++;
		}
	}
	int min_B = B[0];
	
	for (int i = 0; i < m; i++) {

		if (B[i] % 2 == 0) {
			C[cSize] = B[i];
			cSize++;
		}
		else {
			D[dSize] = B[i];
			dSize++;
		}
		if (B[i] < min_B) {
			min_B = B[i];
		}
	}

	cout << "min B:";
	cout << min_B << endl;

	int scalar_a = min_B;
	int d[max_size] = {};
	bool canExpress = true;

	if (scalar_a == 0) {
		canExpress = false;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (A[i] % scalar_a == 0) {
				d[i] = A[i] * scalar_a;
			}
			else {
				canExpress = false;
				break;
			}
		}
	}

	if (canExpress) {
		cout << "d:";
		printArr(d, n);
	}
	else {
		cout << "Виразити точно через цілочисельний вектор d не можна" << endl;
	}

	sortArr(C, cSize);
	sortArr(D, dSize);


	cout << "C:";
	printArr(C, cSize);

	cout << "D:";
	printArr(D, dSize);


	if (isNonIncreasing(A, n)) {
		cout << "Послідовність A є впорядкованою за незростанням" << endl;
	}
	else {
		cout << "Послідовність A не є впорядкованою за незростанням" << endl;
	}

	if (isNonIncreasing(B, m)) {
		cout << "Послідовність B є впорядкованою за незростанням" << endl;
	}
	else {
		cout << "Послідовність B не є впорядкованою за незростанням" << endl;
	}

}

//void outputResult(bool *func(int arr[], int size)) {
//
//}

