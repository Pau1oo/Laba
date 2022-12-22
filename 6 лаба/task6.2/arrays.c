#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include <time.h>

void inputSize(int* N, int* M)
{
	printf("Input the size of matrix (N,M):\n");
	while (scanf_s("%d", N) != 1 || N < 1)
	{
		printf("Try again!\n");
		rewind(stdin);
	}
	while (scanf_s("%d", M) != 1 || M <= 1)
	{
		printf("Try again!\n");
		rewind(stdin);
	}
}

void memoryAllocation(int*** matrix, int N, int M)
{
	*matrix = (int**)calloc(M, sizeof(int*));

	for (int i = 0; i < N; i++)
	{
		*(*(matrix) + i) = (int*)calloc(M, sizeof(int));
	}
}

void inputMatrix(int** matrix, int N, int M, int option)
{
	switch (option)
	{
	case 1:
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("Input the element [%d][%d]: ", i + 1, j + 1);
				while (scanf_s("%d", &matrix[i][j]) != 1)
				{
					printf("Try again!\n");
					printf("Input the element [%d][%d]: ", i + 1, j + 1);
					rewind(stdin);
				}
			}
		}
		printf("\n");
	case 2:
		srand(time(NULL));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				*(*(matrix + i) + j) = rand() % 21;
			}
		}
	}
}

int sum(int** array, int size, int column)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(*(array + i) + column) % 2 == 0)
			sum += *(*(array + i) + column);
	}
	return sum;
}

void swap(int** array, int size, int column1, int column2)
{
	int temp;
	for (int i = 0; i < size; i++)
	{
		temp = *(*(array + i) + column2);
		for (int j = column2; j > column1; j--)
			*(*(array + i) + j) = *(*(array + i) + j - 1);
		*(*(array + i) + column1) = temp;
	}
}

int findMin(int** array, int size, int first, int last)
{
	int min = sum(array, size, first), n_col = first;
	for (int i = first + 1; i < last + 1; i++)
		if (sum(array, size, i) < min)
		{
			min = sum(array, size, i);
			n_col = i;
		}
	return n_col;
}

void mergeSort(int** array, int size, int first, int last)
{
	int col_change;
	if (first < last)
	{
		mergeSort(array, size, first, (first + last) / 2);
		mergeSort(array, size, ((first + last) / 2) + 1, last);
		for (int i = first; i < last; i++)
		{
			col_change = findMin(array, size, i, last);
			swap(array, size, i, col_change);
		}
	}
}

void printMatrix(int** matrix, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("%4d", *(*(matrix + i) + j));
		}
		printf("\n");
	}
	printf("\n");
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