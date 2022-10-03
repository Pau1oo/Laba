#include <stdio.h>

int main()
{
	int array[100], n, i, option;
	printf("Input the length of the array\n");
	scanf_s("%d", &n);

	printf("Choose an option:\n1) Keyboard input\n2) Initializing an array with random elements\n");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		printf("Input the elements of the array\n");
		for (i = 0; i < n; i++)
		{
			scanf_s("%d", &array[i]);
		}
		break;

	case 2:
		srand(time(NULL));
		for (i = 0; i < n; i++)
		{
			array[i] = rand() % 30-15;
			printf("%d ", array[i]);
		}
		printf("\n");
		break;

	default:
		printf("Error");
		return 0;
	}

	if (n <= 0)
	{
		printf("Invalid input");
		return 0;
	}

	for (i = 1; i < n + 1; i++)
	{
		if (array[i] % 2 == 0)
			printf("%d ", array[i - 1]);
	}
}