#include <iostream>

using namespace std;

int main()
{
    int countOfSecondsInOneDay = 60 * 60 * 24;
    int countOfSecondsInOneYear = countOfSecondsInOneDay * 365;
   
    int countOfYears;
    
    countOfYears = 73;
    int countOfSeconds_int;
    long long countOfSeconds_longlong;
    if (countOfYears > 3)
    {
        countOfSeconds_longlong = countOfYears * (long long)countOfSecondsInOneYear + ((countOfYears - countOfYears % 4)/4 * countOfSecondsInOneDay);
        countOfSeconds_int = countOfYears * countOfSecondsInOneYear + ((countOfYears - countOfYears % 4) / 4 * countOfSecondsInOneDay);
    }
    else
    {
        countOfSeconds_longlong = countOfYears * (long long)countOfSecondsInOneYear;
        countOfSeconds_int = countOfYears * countOfSecondsInOneYear;
    }
}