#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstring>
using namespace std;

void showFile( char fileName[]);
void analyzeFile( char inputFile[], char outputFile[]);

int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char inputFile[100];


    if (argc > 1) {
        strncpy(inputFile, argv[1], 99);
        inputFile[99] = '\0';
        cout << "Ім'я вхідного файлу (з командного рядка): " << inputFile << endl;
    }
    else {
        cout << "Введіть ім'я вхідного файлу: ";
        cin.getline(inputFile, 100);
    }

    char outputFile[100];

    strncpy(outputFile, inputFile, 3);
    outputFile[3] = '\0';
    strcat(outputFile, "_out.dat");

    int choice;

    bool isAnalyzed = false;

    do {
        cout << "\nМеню:\n";
        cout << "1 - Показати вхідний файл\n";
        cout << "2 - Виконати обробку файлу\n";
        cout << "3 - Показати вихідний файл\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            showFile(inputFile);
        }

        else if (choice == 2) {
            analyzeFile(inputFile, outputFile);
            isAnalyzed = true; 
            cout << "Дані записані у файл " << outputFile << endl;
        }
        else if (choice == 3) {
            if (isAnalyzed) {
                showFile(outputFile);
            }
            else {
                cout << "Помилка: Вихідний файл ще не створено! Спочатку виконайте обробку (пункт 2)." << endl;
            }
        }

    } while (choice != 0);

    return 0;
}
