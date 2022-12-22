#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include <time.h>

int main()
{
	int** matrix = NULL;
	int N, M, option;

	inputSize(&N, &M);
	memoryAllocation(&matrix, N, M);
	chooseTypeInput(&option);
	inputMatrix(matrix, N, M, option);
	printMatrix(matrix, N, M);
	mergeSort(matrix, N, 0, M - 1);
	printMatrix(matrix, N, M);
}