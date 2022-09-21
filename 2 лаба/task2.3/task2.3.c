#include <stdio.h>

int main()
{
    int N, K, temp, count, quotient, rest;
    temp = 0;
    count = 0;
    printf("Input N and K (N>K)\n");
    if (scanf_s("%d %d", &N, &K) != 2)
    {
        printf("Invalid input");
        exit();
    }
    if (N < K)
    {
        printf("Invalid input");
        exit();
    }
    if ((N <= 0) || (K <= 0))
    {
        printf("Invalid input");
        exit();
    }   
    while (temp <= N)
    {
        temp = temp + K;
        count += 1;
    }
    quotient = count - 1;
    rest = N - (temp - K);
    printf("Quotient = %u\nRest = %u", quotient, rest);
}