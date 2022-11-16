//1.	Заполнить массив с клавиатуры. Удалить все элементы, кратные 11.
#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main()
{
	int length;
	printf("Input the size of array: ");

	while (scanf_s("%d", &length) != 1 || length <= 0 || length % 1 != 0)
	{
		printf("Try again\n");
		printf("Input the size of array: ");
		rewind(stdin);
	}

	int *array = (int*) calloc(length, sizeof(int));

	inputArray(array, length);
	delElement(array, length);
	free(array);
}
