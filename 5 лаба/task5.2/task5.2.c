/* 2. ƒвумерный массив заполнить числами. оличество чисел в строке может быть различным,
последнее число - 0. ¬ каждой строке удалить все максимальные элементы */

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main()
{
	int **matrix, numR;

	printf("Input the number of rows: ");
	while (scanf_s("%d", &numR) != 1)
	{
		printf("Try again!\n");
		printf("Input the number of rows: ");
		rewind(stdin);
	}
	matrix = (int**)malloc(numR * sizeof(int*));

	for (int i = 0; i < numR; i++)
	{
		matrix[i] = (int*)malloc(1 * sizeof(int));
		int j = 0;
		printf("Input the elements of row [%d]:\n", i + 1);

		while (scanf_s("%d", &matrix[i][j]) && matrix[i][j] != 0)
		{
			j++;
			matrix[i] = (int*)realloc(matrix[i], (j + 1) * sizeof(int));
		}
	}

	for (int i = 0; i < numR; i++)
	{
		int j = 0;

		while (matrix[i][j] != 0)
		{
			printf("%5d", matrix[i][j]);
			j++;
		}

		printf("%5d", matrix[i][j]);
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < numR; i++)
	{
		int j = 0;

		while (matrix[i][j] != 0)
		{
			if (matrix[i][j] == maxElement(matrix, i))
				j++;
			else
			{
				printf("%5d", matrix[i][j]);
				j++;
			}
		}
		printf("    0    ");
		printf("\n");
	}

	for (int i = 0; i < numR; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}