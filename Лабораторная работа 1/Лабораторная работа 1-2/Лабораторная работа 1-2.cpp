#include <iostream>

using namespace std;

int main()
{
    double S;
    double a;
    double b;
    double c;

    /*cout << "Enter \"a\" :" << endl << "a = ";
    cin >> a;
    cout << "Enter \"b\" :" << endl << "b = ";
    cin >> b;
    cout << "Enter \"c\" :" << endl << "c = ";
    cin >> c;*/
    a = 25;
    b = 8;
    c = 4;

    double p = (a + b + c) / 2.0;
    S = sqrt(p * (p - a) * (p - b) * (p - c));

    /*cout << "The area of a triangle with given sides equals :" << endl << "S = " << S;*/
}