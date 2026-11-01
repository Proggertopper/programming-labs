#include <iostream>
#include <windows.h>
#include <climits>
#include <fstream>
using namespace std;



static int** createArray(int rows , int cols) {
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    return arr;
}

static void deleteArray(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

static void printArray(int** arr , int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", arr[i][j]);
        }
        cout << "\n";
    }
}

static int findMax(int** arr, int size) {
    int maxNum = INT_MIN;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                if (arr[i][j] > maxNum) {
                    maxNum = arr[i][j];
                }
            }
        }
    }
    return maxNum;
}

static int findMinHeadDiagonal(int** arr, int size) {
    int minNumForDiagonal = INT_MAX;
    for (int i = 0; i < size; i++) {
            if (arr[i][i] < minNumForDiagonal) {
                minNumForDiagonal = arr[i][i];
               }
            }
    return minNumForDiagonal;
}

static int findRowWithMinNum(int** arr, int size) {
    int numOfRow = 0;
    int minNum = INT_MAX;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
               if (arr[i][j] < minNum) {
                  minNum = arr[i][j];
                  numOfRow = i;
               }
        }
    }
    return numOfRow;
}

static void mySort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

static void fillArrayFromConsole(int** arr, int size) {
    cout << "Введіть елементи матриці " << size << "x" << size << ":\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }
}

static bool fillArrayFromFile(int** arr, int size, char* fileName) {
    ifstream fileStream(fileName);

    if (!fileStream.is_open()) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (!(fileStream >> arr[i][j])) {
                fileStream.close();
                return false;
            }
        }
    }

    fileStream.close();
    return true;
}



int main()
{
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int choice;
    int n;

    cout << "Оберіть спосіб вводу:\n";
    cout << "1 - з консолі\n";
    cout << "2 - з файлу\n";
    cout << "Ваш вибір: ";
    cin >> choice;

    cout << "Введіть розмір матриці (7 <= n <= 100): ";
    cin >> n;

    if (n < 7 || n > 100) {
        cout << "Помилка! n має бути в межах від 7 до 100.\n";
        return 1;
    }

    int** Matrix = createArray(n, n);

    if (choice == 1) {
        fillArrayFromConsole(Matrix, n);
    }
    else if (choice == 2) {
        char fileName[256];
        cout << "Введіть ім'я файлу: ";
        cin >> fileName;

        if (!fillArrayFromFile(Matrix, n, fileName)) {
            cout << "Помилка ! Не вдалося відкрити файл.\n";
            deleteArray(Matrix, n);
            return 1;
        }
    }
    else {
        cout << "Помилка ! Невірний ввід.\n";
        deleteArray(Matrix, n);
        return 1;
    }

    cout << "\nПочаткова матриця:\n";
    printArray(Matrix, n);

    cout << "\n1. Максимальний елемент серед тих, у яких обидва індекси парні: " << findMax(Matrix , n) << "\n";
    cout << "2. Мінімальний елемент головної діагоналі: " << findMinHeadDiagonal(Matrix, n) << "\n";
    int minRow = findRowWithMinNum(Matrix, n);
    cout << "3. Номер рядка з мінімальним елементом матриці: " << minRow << "\n";
    
    mySort(Matrix[minRow], n);

    cout << "\n Матриця після сортування потрібного рядка: \n ";
    printArray(Matrix, n);


    deleteArray(Matrix, n);

    return 0;
    
}
