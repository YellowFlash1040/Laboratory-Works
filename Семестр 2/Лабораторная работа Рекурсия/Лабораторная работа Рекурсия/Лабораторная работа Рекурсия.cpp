#include <iostream>
#include <windows.h>

using namespace std;

int result;
int ten;
void ConvertToFifthNumberSystem(int number)
{
    int temp = number % 5;
    result += temp * ten;
    ten *= 10;

    if (number/5 != 0)
    {
        ConvertToFifthNumberSystem(number / 5);
    }
}

void UserInput()
{
    cout << "Введите число в десятичной системе счисления:\nВвод > ";
    int answer;
    cin >> answer;
    cout << "\n";

    ten = 1;
    result = 0;
    ConvertToFifthNumberSystem(answer);

    cout << "Введенное вами число в пятиричной системе счисления имеет вид: " << result << "\n\n";
    UserInput();
}

int main()
{
    SetConsoleOutputCP(1251);
    UserInput();
}