#include <iostream>

using namespace std;

int main()
{
    srand(time(0));

   double number; 
   /* cout << "Good day,\nyou are greeted by the \"Guess the number\" program." << endl << endl;
    cout << "The rules of the game are as simple as possible: you need to guess any number,\n" <<
        "and if the number you have guessed is greater than the number \"guessed\" by the computer,\n" <<
        "then you have won. If you are ready to play, please enter your number :" << endl << endl;
    cout << "Your number = ";*/
    //cin >> number;
    number = 3;
    //cout << endl;
    double computerNumber = number + rand() % 100;
    /*cout << "Now the computer number :" << endl << "Computer number = " << computerNumber << endl << endl;
    cout << "Oh, I\'m sorry, this time you lost, but you can try again, maybe next time you will be luckier.\n" << endl;
    cout << "If you want to try again, enter \"y\", else enter \"n\"" << endl;*/

    /*string answer;
    cout << "Answer : ";
    cin >> answer;
    while (answer != "y" && answer != "n")
    {
        cout << "The input was uncorrect, please try again :" << endl;
        cout << "Answer : ";
        cin >> answer;
    }

    while (answer == "y")
    {
        cout << endl;
        cout << "Please enter your number :" << endl << "Your number = ";
        cin >> number;
        cout << endl;
        double computerNumber = number + rand() % 100;
        cout << "Now the computer number :" << endl << "Computer number = " << computerNumber << endl << endl;
        cout << "Oh, I\'m sorry, this time you lost, but you can try again, maybe next time you will be luckier.\n" << endl;
        cout << "If you want to try again, enter \"y\", else enter \"n\"" << endl;
        cout << "Answer : ";
        cin >> answer;

        while (answer != "y" && answer != "n")
        {
            cout << "The input was uncorrect, please try again :" << endl;
            cout << "Answer : ";
            cin >> answer;
        }*/
    //}
}