#include <iostream>
#include <windows.h>

using namespace std;

char Compare(int a, int b)
{
    if (a > b)
    {
        return '>';
    }
    else if (a < b)
    {
        return '<';
    }
    return '=';
}

int main()
{
    SetConsoleOutputCP(1251);

    char answer = 'y';
    int a, b;
    char result;
    do
    {
        cout << "Введите два числа через пробел > ";
        cin >> a >> b;
        cout << endl;
        cout << "Результат : " << a << " " << Compare(a, b) << " " << b << endl << endl;
        cout << "Хотите повторить ввод(y/n) > ";
        cin >> answer;
        cout << "\n";
    } while (answer == 'y');
}