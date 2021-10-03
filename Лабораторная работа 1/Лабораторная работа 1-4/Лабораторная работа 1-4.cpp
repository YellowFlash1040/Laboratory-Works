#include <iostream>

using namespace std;

void Task4_2()
{
	double a, b;
	/*cout << "Enter first number :" << endl << "a = ";
	cin >> a;
	cout << "Enter second number :" << endl << "b = ";
	cin >> b;*/
	a = 3;
	b = 4;
	swap(a, b);
	//cout << "The result of the program work :" << endl << "a = " << a << endl << "b = " << b;
}

void Task4_1()
{
	double a, b;
	/*cout << "Enter first number :" << endl << "a = ";
	cin >> a;
	cout << "Enter second number :" << endl << "b = ";
	cin >> b;*/
	a = 3;
	b = 4;
	double temp = a;
	a = b;
	b = temp;
	/*cout << "This is the result of the program work :" << endl;
	cout << "\"a\" = " << a << endl;
	cout << "\"b\" = " << b;*/
}

int main()
{
	Task4_2();
}