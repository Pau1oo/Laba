/* 3.В двумерной матрице размером NxM удалить все строки содержащие более 2х нулей подряд.*/

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main()
{
	int** matrix = NULL;
	int N, M;

	inputSize(&N, &M);
	memoryAllocation(&matrix, N, M);
	inputMatrix(matrix, N, M);
	printMatrix(matrix, N, M);
	delRow(&matrix, &N, &M);
	printMatrix(matrix, N, M);
}