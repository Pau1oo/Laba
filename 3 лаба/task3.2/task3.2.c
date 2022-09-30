#include <stdio.h>

int main()
{
	int array[100], n, i;
	printf("Input the length of the array\n");
	scanf_s("%d", &n);

	if (n <= 0)
	{
		printf("Invalid input");
		return 0;
	}

	printf("Input the elements of the array\n");

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &array[i]);
	}

	for (i = 1; i < n + 1; i++)
	{
		if (array[i] % 2 == 0)
			printf("%d ", array[i - 1]);
	}
}