#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

void showFile(char fileName[]) {
    ifstream fin(fileName);

    if (!fin) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    char line[200];

    while (fin.getline(line, 200)) {
        cout << line << endl;
    }

    fin.close();
}

void analyzeFile(char inputFile[], char outputFile[]) {

    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (!fin || !fout) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    char line[200];
    while (fin.getline(line, 200)) {
        fout << line << endl; 
    }

    fin.close(); 

    fin.open(inputFile); 

    if (!fin) {
        cout << "Помилка повторного відкриття файлу!" << endl;
        return;
    }

    char word[100];
    int countWords = 0;
    int maxLen = 0;
    int minLen = 10000;

    while (fin >> word) {

        int len = strlen(word);

        countWords++;

        if (len > maxLen)
            maxLen = len;
        if (len < minLen)
            minLen = len;
    }

    if (countWords == 0)
        minLen = 0;

    fout << "\n---------------------------------\n";
    fout << left << setw(30) << "Кількість слів" << ": " << countWords << endl;
    fout << left << setw(30) << "Максимальна довжина слова" << ": " << maxLen << endl;
    fout << left << setw(30) << "Мінімальна довжина слова" << ": " << minLen << endl;

    fin.close();
    fout.close();
}
