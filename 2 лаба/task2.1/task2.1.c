#include <stdio.h>

int main()
{
	unsigned int count = 0;
	float R, M;
	printf("Input R and M (M>R)\n");
	if(scanf_s("%f %f", &R, &M) != 2)
	{
		printf("Invalid input");
		exit();
	}
	if (R > M)
	{
		printf("Invalid input");
		exit();
	}
	if ((R <= 0) || (M <= 0))
	{
		printf("Invalid input");
		exit();
	}
	while (R < M)
	{
		R += R * 0.04;
		count++;
	}
	printf("%u years", count);
}