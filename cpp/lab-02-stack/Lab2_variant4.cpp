#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    double data[MAX_SIZE];
    int top;

    Stack() {
        top = 0;
    }

    // ~Stack() {}

    bool Push(double value) {
        if (top == MAX_SIZE) return false;
        data[top] = value;
        top++;
        return true;
    }

    double Pop(bool& ok) {
        if (top == 0) {
            ok = false;
            return 0;
        }
        top--;
        ok = true;
        return data[top];
    }

    double Top(bool& ok) {
        if (top == 0) {
            ok = false;
            return 0;
        }
        ok = true;
        return data[top-1];
    }


    int SizeStack() {
        return top;
    }

    void ClearStack() {
        top = 0;
    }

    void StackScreen() {
        if (top == 0) {
            cout << "Стек порожній.\n";
            return;
        }

        cout << "Стек (знизу -> вгору): ";
        for (int i = 0; i < top; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};


bool IsNumber( string& token, double& number) {
    stringstream input(token);
    input >> number;
    return input && input.eof();
}

bool IsOperation(string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

void CalculatePostfixExpression() {
    cin.ignore(10000, '\n');
    cout << "Введіть вираз через пробіл (наприклад: 5 2 3 * +): ";

    string expression, token;
    getline(cin, expression);

    Stack calculationStack;
    stringstream input(expression);

    while (input >> token) {
        double number;

        if (IsNumber(token, number)) {
            if (!calculationStack.Push(number)) {
                cout << "Помилка: стек переповнений.\n";
                return;
            }
        }
        else if (IsOperation(token)) {
            bool okRight, okLeft;
            double right = calculationStack.Pop(okRight);
            double left = calculationStack.Pop(okLeft);

            if (!okRight || !okLeft) {
                cout << "Помилка: для операції недостатньо чисел.\n";
                return;
            }

            double result = 0.0;
            if (token == "+") result = left + right;
            if (token == "-") result = left - right;
            if (token == "*") result = left * right;
            if (token == "/") {
                if (right == 0) {
                    cout << "Помилка: ділення на нуль.\n";
                    return;
                }
                result = left / right;
            }

            calculationStack.Push(result);
        }
        else {
            cout << "Помилка: невідома операція \"" << token << "\".\n";
            return;
        }
    }

    if (calculationStack.SizeStack() != 1) {
        cout << calculationStack.SizeStack() << "\n";
        calculationStack.StackScreen();
        cout << "Помилка: вираз записано некоректно.\n";
        return;
    }

    bool ok;
    double answer = calculationStack.Pop(ok);
    cout << "Результат: " << answer << "\n";
}

int main() {
    Stack userStack;
    int menuChoice;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    do {
        cout << "\n1 - Додати елемент до стеку\n";
        cout << "2 - Видалити елемент зі стеку\n";
        cout << "3 - Вивести стек\n";
        cout << "4 - Вивести кількість елементів\n";
        cout << "5 - Очистити стек\n";
        cout << "6 - Обчислити постфіксний вираз\n";
        cout << "7 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> menuChoice;

        if (menuChoice == 1) {
            double value;
            cout << "Введіть число: ";
            cin >> value;

            if (userStack.Push(value)) cout << "Елемент додано.\n";
            else cout << "Помилка: стек переповнений.\n";
        }

        if (menuChoice == 2) {
            bool ok;
            double value = userStack.Pop(ok);

            if (ok) cout << "Видалено елемент: " << value << "\n";
            else cout << "Помилка: стек порожній.\n";
        }

        if (menuChoice == 3) userStack.StackScreen();

        if (menuChoice == 4) {
            cout << "Кількість елементів: " << userStack.SizeStack() << "\n";
        }

        if (menuChoice == 5) {
            userStack.ClearStack();
            cout << "Стек очищено.\n";
        }

        if (menuChoice == 6) CalculatePostfixExpression();

        if (menuChoice < 1 || menuChoice > 7) {
            cout << "Немає такого пункту меню.\n";
        }
    } while (menuChoice != 7);

    return 0;
}

