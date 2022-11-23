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

void delElement(int **arr, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		if ((*(*(arr)+i) % 11) == 0)
		{
			for (int j = i; j < *size; j++)
			{
				(*(*(arr)+j)) = (*(*(arr)+j + 1));
			}
			(*size)--;
			i--;
			*arr = (int*)realloc(*arr, *size * sizeof(int));
		}
	}
}

void inputSize(int* length)
{
	printf("Input the size of array: ");

	while (scanf_s("%d", length) != 1 || length <= 0 || getchar() != '\n')
	{
		printf("Try again\n");
		printf("Input the size of array: ");
		rewind(stdin);
	}
}

void memoryAllocation(int** array, int length)
{
	*array = (int*)calloc(length, sizeof(int));
}

void printArray(int* array, int size)
{
	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%d ", *(array + i));
}