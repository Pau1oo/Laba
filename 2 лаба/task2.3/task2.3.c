#include <stdio.h>

int main()
{
    unsigned int N, K, temp, count, quotient, rest;
    temp = 0;
    count = 0;
    printf("Input N and K (N>K)\n");
    scanf_s("%u %u", &N, &K);
    while (temp <= N)
    {
        temp = temp + K;
        count += 1;
    }
    quotient = count - 1;
    rest = N - (temp - K);
    printf("Quotient = %u\nRest = %u", quotient, rest);
}