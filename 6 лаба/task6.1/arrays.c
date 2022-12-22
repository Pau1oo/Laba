#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "arrays.h"

void inputSize(int* size)
{
	printf("Input the size of array: ");

	while (scanf_s("%d", size) != 1 || size <= 0 || getchar() != '\n')
	{
		printf("Try again\n");
		printf("Input the size of array: ");
		rewind(stdin);
	}
}

void memoryAllocation(int** array, int** array2, int size)
{
	*array = (int*)calloc(size, sizeof(int));
	*array2 = (int*)calloc(size, sizeof(int));
}

void chooseTypeInput(int* option)
{
	printf("Choose an option:\n1) Keyboard input\n2) Initializing an array with random elements\n");
	while (scanf_s("%d", option) != 1 || getchar() != '\n' || *option > 2 || *option <= 0)
	{
		rewind(stdin);
		printf("Wrong input. Try again:\n");
	}
}

void inputArray(int* array, int size, int option)
{
	switch (option)
	{
	case 1:
		for (int i = 0; i < size; i++)
		{
			printf("Input the element [%d]: ", i + 1);
			scanf_s("%d", &array[i]);
		}
		break;

	case 2:
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			*(array + i) = rand() % 201-100;
		}
	}
}

void extractArray(int* array, int** activeArray, int size, int* sizeActiveArray)
{
	int k = 0, flag = 0;
	for (int i = size - 1; flag != 1; i--)
	{
		if (*(array + i) > 0)
		{
			flag = 1;
			k = i;
		}
	}
	for (int i = 0, j = 0; i <= k; i++, j++, (*sizeActiveArray)++)
	{
		if (*(array + i) % 2 != 0)
		{
			*activeArray = (int*)realloc(*activeArray, *sizeActiveArray * sizeof(int));
			*(*(activeArray) + j) = (*(array + i));
		}
		else
		{
			j--;
			(*sizeActiveArray)--;
		}
	}
	(*sizeActiveArray)--;
}

void extractArray2(int* array, int** activeArray, int size, int* sizeActiveArray)
{
	int k = 0, flag = 0;
	for (int i = size - 1; flag != 1; i--)
	{
		if (*(array + i) > 0)
		{
			flag = 1;
			k = i;
		}
	}
	for (int i = 0, j = 0; i <= k; i++, j++, (*sizeActiveArray)++)
	{
		if (*(array + i) % 2 != 0)
		{
			*activeArray = (int*)realloc(*activeArray, *sizeActiveArray * sizeof(int));
			(*(array + i)) = *(*(activeArray)+j);
		}
		else
		{
			j--;
			(*sizeActiveArray)--;
		}
	}
	(*sizeActiveArray)--;
}

void printArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

void bubbleSort(int* array, int size)
{
	clock_t start1 = clock();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	clock_t end1 = clock();
	float time1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("\nTime of bubbleSort: %.3f sec.\n", time1);
}

void ShellSort(int* array, int size)
{
	clock_t start2 = clock();
	int j;
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = step; i < size; i++)
		{
			int temp = array[i];
			for (j = i; j >= step; j -= step)
			{
				if (temp < array[j - step])
					array[j] = array[j - step];
				else
					break;
			}
			array[j] = temp;
		}
	}
	clock_t end2 = clock();
	float time2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
	printf("\nTime of ShellSort: %.3f sec.\n", time2);
}

void worstShellSort(int* array, int size)
{
	int j;
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = step; i < size; i++)
		{
			int temp = *(array+i);
			for (j = i; j >= step; j -= step)
			{
				if (temp > *(array+j-step))
					*(array+j) = *(array+j-step);
				else
					break;
			}
			*(array+j) = temp;
		}
	}
}

void ShellSort2(int* array, int size)
{
	clock_t start3 = clock();
	int j;
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = step; i < size; i++)
		{
			int temp = array[i];
			for (j = i; j >= step; j -= step)
			{
				if (temp < array[j - step])
					array[j] = array[j - step];
				else
					break;
			}
			array[j] = temp;
		}
	}
	clock_t end3 = clock();
	float time3 = (float)(end3 - start3) / CLOCKS_PER_SEC;
	printf("\nTime of worst case: %.3f sec.\n", time3);
}

void arrayCopy(int* array, int* array2, int size)
{
	for (int i = 0; i < size; i++)
	{
		array2[i] = array[i];
	}
}