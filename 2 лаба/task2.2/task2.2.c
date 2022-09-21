#include <stdio.h>

int main()
{
    float C1, C2;
    printf("Input C1 and C2\n");
    if (scanf_s("%f %f", &C1, &C2) != 2)
    {
        printf("Invalid input");
        exit();
    }
    if ((C1 < 0) || (C2 < 0))
    {
        printf("Invalid input");
        exit();
    }
    for (int i = 0; i < 6; i++)
    {
        C2 = C2 + C1 / 2;
        C1 = C1 / 2;

        C1 = C1 + C2 / 2;
        C2 = C2 / 2;
    }
    printf("First vessel: %.2f\nSecond vessel: %.2f", C1, C2);
}