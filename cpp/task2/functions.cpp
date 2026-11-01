#include <iostream>
using namespace std;

void myStrcat(char s1[], char s2[]) {
    int i = 0;

    while (s1[i] != '\0') {
        i++;
    }

    int j = 0;

    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';
}

int myStrcspn(char s1[], char s2[]) {
    int count = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        bool found = false;

        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                found = true;
                break;
            }
        }

        if (found)
            break;

        count++;
    }

    return count;
}