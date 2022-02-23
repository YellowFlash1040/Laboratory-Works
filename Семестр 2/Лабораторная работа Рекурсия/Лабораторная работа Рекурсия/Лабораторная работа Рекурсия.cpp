#include <iostream>
#include <windows.h>

using namespace std;

int ConvertToFifthNumberSystem(int number, int ten, int result)
{
    int temp = number % 5;
    result += temp * ten;
    ten *= 10;

    if (number/5 != 0)
    {
        result = ConvertToFifthNumberSystem(number / 5, ten, result);
    }

    return result;
}

void UserInput()
{
    cout << "Введите число в десятичной системе счисления:\nВвод > ";
    int answer;
    cin >> answer;
    cout << "\n";

    int ten = 1;
    int result = 0;
    int output = ConvertToFifthNumberSystem(answer, ten, result);

    cout << "Введенное вами число в пятиричной системе счисления имеет вид: " << output << "\n\n";
    UserInput();
}

int main()
{
    SetConsoleOutputCP(1251);
    UserInput();
}