#include <stdio.h>

int main()
{
	unsigned int count = 0;
	float R, M;
	printf("Input R and M (M>R)\n");
	scanf_s("%f %f", &R, &M);
	while (R < M)
	{
		R += R * 0.04;
		count++;
	}
	printf("%u years", count);
}