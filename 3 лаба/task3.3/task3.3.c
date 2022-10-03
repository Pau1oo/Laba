#include <stdio.h>

int mdl(int a)
{
	if (a < 0)
		a = -a;
	return a;
}

int main()
{
	int array1[20], array2[20], array3[20], i, flag = 0, option;

	printf("Choose an option:\n1) Keyboard input\n2) Initializing an array with random elements\n");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		printf("Input the elements of the first array:\n");

		for (i = 0; i < 20; i++)
		{
			scanf_s("%d", &array1[i]);
		}

		for (i = 1; i < 20; i++)
		{
			if (array1[i] < 0)
			{
				printf("Invalid input");
				return 0;
			}
		}

		printf("Input the elements of the second array:\n");

		for (i = 0; i < 20; i++)
		{
			scanf_s("%d", &array2[i]);
		}

		for (i = 1; i < 20; i++)
		{
			if (array2[i] < 0)
			{
				printf("Invalid input");
				return 0;
			}
		}
		break;

	case 2:
		srand(time(NULL));
		for (i = 0; i < 20; i++)
		{
			array1[i] = rand() % 10;
			printf("%d ", array1[i]);
		}
		printf("\n");
		for (i = 0; i < 20; i++)
		{
			array2[i] = rand() % 10;
			printf("%d ", array2[i]);
		}
		printf("\n");
		break;

	default:
		printf("Error");
		return 0;
	}

	if (array1[0] < 0)
	{
		for (i = 1; i < 20; i++)
		{
			array1[i] = -array1[i];
		}
		flag = 1;
	}

	if (array2[0] < 0)
	{
		for (i = 1; i < 20; i++)
		{
			array2[i] = -array2[i];
		}
		flag = 1;
	}

	int temp = 0;

	for (i = 19; i >= 0; i--)
	{
		if (array1[i] + array2[i] + temp >= 10)
		{
			array3[i] = (array1[i] + array2[i] + temp) % 10;
			temp = 1;
		}
		else
		{
			array3[i] = array1[i] + array2[i] + temp;
			temp = 0;
		}
	}

	if (flag == 1)
	{
		for (i = 1; i < 20; i++)
		{
			array3[i] = mdl(array3[i]);
		}
	}

	printf("Answer:\n");

	if ((array1[0] + array2[0] + temp) >= 10)
		printf("1");

	for (i = 0; i <= 19; i++)
		printf("%d", array3[i]);
}