#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_CAPACITY = 100;

static void printArray(int arrayOfNumbers[], int currentSize) {
    for (int i = 0; i < currentSize; i++) {
        cout << arrayOfNumbers[i] << " ";
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arrayOfNumbers[MAX_CAPACITY]{}, currentSize = 0, minRange, maxRange, menuChoice;
    srand(time(0));

    do {
        cout << "\n1 - Заповнити масив\n2 - Вивести масив\n";
        cout << "3 - Завдання 1\n4 - Завдання 2\n5 - Вихід\n";
        cout << "\n";
        cin >> menuChoice;

        if (menuChoice == 1) {
            cout << "Введіть n (1..100): ";
            cin >> currentSize;
            if (currentSize < 1 || currentSize > MAX_CAPACITY) {
                cout << "Помилка: n має бути від 1 до 100.\n";
                currentSize = 0;
            }
            else {
                cout << "Введіть межі A і B: ";
                cin >> minRange >> maxRange;
                if (minRange > maxRange) {
                    cout << "Помилка: A не може бути більшим за B.\n";
                    currentSize = 0;
                }
                else {
                    for (int i = 0; i < currentSize; i++)
                        arrayOfNumbers[i] = minRange + rand() % (maxRange - minRange + 1);
                    cout << "Масив заповнено.\n";
                }
            }
        }

        if (menuChoice == 2) {
            if (currentSize == 0) cout << "Масив ще не заповнений.\n";
            else printArray(arrayOfNumbers, currentSize);
        }

        if (menuChoice == 3) {
            if (currentSize == 0) cout << "Масив ще не заповнений.\n";
            else {
                int sumEvenSquares = 0, sumOdd = 0;
                for (int i = 0; i < currentSize; i++) {
                    if (arrayOfNumbers[i] % 2 == 0) sumEvenSquares += arrayOfNumbers[i] * arrayOfNumbers[i];
                    else sumOdd += arrayOfNumbers[i];
                }
                cout << "Сума квадратів парних: " << sumEvenSquares << endl;
                cout << "Сума непарних: " << sumOdd << endl;
            }
        }
        
        if (menuChoice == 4) {
            if (currentSize == 0) cout << "Масив ще не заповнений.\n";
            else if (currentSize == MAX_CAPACITY) cout << "Масив повний. Додавання неможливе.\n";
            else {
                int newElement, position = currentSize / 2;
                cout << "Масив до: ";
                printArray(arrayOfNumbers, currentSize);
                cout << "Введіть новий елемент: ";
                cin >> newElement;

                for (int i = currentSize; i > position; i--) {
                    arrayOfNumbers[i] = arrayOfNumbers[i - 1];
                }
                arrayOfNumbers[position] = newElement;
                currentSize++;

                cout << "Масив після: ";
                printArray(arrayOfNumbers, currentSize);
            }
        }

        if (menuChoice < 1 || menuChoice > 5) cout << "Немає такого пункту меню.\n";
    } while (menuChoice != 5);

    return 0;
}


