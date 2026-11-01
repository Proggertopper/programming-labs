#include <iostream>
#include <fstream>
using namespace std;


bool fillArrayFromFile(int* arr, int size, char* fileName) {
    ifstream fileStream(fileName);

    if (!fileStream.is_open()) {
        return false;
    }

    for (int i = 0; i < size; i++) {

        if (!(fileStream >> arr[i])) {
            fileStream.close();
            return false;
        }

    }

    fileStream.close();
    return true;
}

int main()
{
    /*char fileName[256];
    cout << "Введіть ім'я файлу: ";
    cin >> fileName;

    int arr[5];

    ifstream fileStream(fileName);
    fillArrayFromFile(arr, 5, fileName);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << "\n";
    }*/

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
