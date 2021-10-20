#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <windows.h>

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    short n;
    double x, y;
    short h;
    for (n = 0; n < 4; n++)
    {

        printf("|   x   |      y     |\n");
        printf("|-------|------------|\n");

        for (x = 0; x < 8; x += 0.25)
        {
            if (x < 2)
            {
                y = sqrt(1 - (x - 1) * (x - 1));
            }
            else if (x < 4)
            {
                y = sqrt(1 - (x - 3) * (x - 3));
            }
            else if(x < 6)
            {
                y = sqrt(1 - (x - 5) * (x - 5));
            }
            else
            {
                y = 0;
            }

            printf("| %5.2lf | %10.7lf |", x + n * 4, y);

            h = (y + 1) * 10 + 0.5;

            for (; h > 0; h--)
            {
                printf(" ");
            }
            printf("*\n");
        }
        printf("Нажмите клавишу Enter...");
        getchar();
    }
    return 0;
}