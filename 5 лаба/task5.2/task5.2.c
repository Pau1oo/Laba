/* 2. ��������� ������ ��������� �������.���������� ����� � ������ ����� ���� ���������,
��������� ����� - 0. � ������ ������ ������� ��� ������������ �������� */

#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main()
{
	int** matrix;
	int numR;

	inputSize(&numR);
	memoryAllocation(&matrix, numR);
	inputMatrix(matrix, numR);
	printMatrix(matrix, numR);
	delElement(matrix, numR);

	for (int i = 0; i < numR; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}