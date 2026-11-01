#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char s1[200], s2[200];

    cout << "Введіть перше речення: ";
    cin.getline(s1, 200);

    cout << "Введіть друге речення: ";
    cin.getline(s2, 200);

    char* words1[50];
    char* words2[50];

    int count1 = 0, count2 = 0;

    char* p = strtok(s1, " ");
    while (p != NULL) {
        words1[count1] = p;
        count1++;
        p = strtok(NULL, " ");
    }

    p = strtok(s2, " ");
    while (p != NULL) {
        words2[count2] = p;
        count2++;
        p = strtok(NULL, " ");
    }

    int minCount;
    if (count1 < count2)
        minCount = count1;
    else
        minCount = count2;


    for (int i = 1; i < minCount; i += 2) {
        char* temp = words1[i];
        words1[i] = words2[i];
        words2[i] = temp;
    }

    cout << "\nНове перше речення:\n";
    for (int i = 0; i < count1; i++) {
        cout << words1[i] << " ";
    }

    cout << "\n\nНове друге речення:\n";
    for (int i = 0; i < count2; i++) {
        cout << words2[i] << " ";
    }

    return 0;
}
