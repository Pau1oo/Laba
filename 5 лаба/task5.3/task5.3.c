/* 3.В двумерной матрице размером NxM удалить все строки содержащие более 2х нулей подряд.*/

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main()
{
	int** matrix = NULL;
	int N, M;

	printf("Input the size of matrix (N,M):\n");
	while (scanf_s("%d", &N) != 1 || N < 1)
	{
		printf("Try again!\n");
		rewind(stdin);
	}
	while (scanf_s("%d", &M) != 1 || M <= 1)
	{
		printf("Try again!\n");
		rewind(stdin);
	}

	matrix = (int**)calloc(N, sizeof(int*));

	for (int i = 0; i < N; i++)
	{
		matrix[i] = (int*)calloc(M, sizeof(int));
	}

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

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	delRow(&matrix, &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}