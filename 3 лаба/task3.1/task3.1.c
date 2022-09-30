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

	int max = array[0];

	for (i = 0; i < n; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	for (i = 0; i < n; i++)
	{
		if (max == array[i])
		{
			printf("%d ", i + 1);
		}
	}

	int first_null, second_null, count = 0;

	for (i = 0; (i < n) || (count != 1); i++)
	{
		if (array[i] == 0)
		{
			first_null = i;
			count++;
			break;
		}
	}

	for (i = first_null + 1; (i < n) || (count != 2); i++)
	{
		if (array[i] == 0)
		{
			second_null = i;
			count++;
			break;
		}
	}

	count = 0;

	for (i = 0; (i < n); i++)
	{
		if (array[i] == 0)
			count++;
	}

	if (count == 0)
	{
		printf("\nNo null elements in the array");
		return 0;
	}

	if (count == 1)
	{
		printf("\nOnly one null element in the array");
		return 0;
	}

	if (first_null == second_null - 1)
	{
		printf("\nNo elements between first and second null elements");
		return 0;
	}

	int comp = array[first_null + 1];

	for (i = first_null + 2; array[i] != 0; i++)
	{
		comp = comp * array[i];
	}

	printf("\n%d", comp);
}