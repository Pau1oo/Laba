void inputArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Input the element [%d]: ", i + 1);
		while (scanf_s("%d", &arr[i]) != 1)
		{
			printf("Try again\n");
			printf("Input the element [%d]: ", i + 1);
			rewind(stdin);
		}
	}
}

void delElement(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 11 == 0)
		{
			for (int j = i; j < size; j++)
			{
				arr[j] = arr[j + 1];
			}
			size--;
			i--;
		}
	}

	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}