/* 3.� ��������� ������� �������� NxM ������� ��� ������ ���������� ����� 2� ����� ������.*/

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