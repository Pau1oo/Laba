//1.	Заполнить массив с клавиатуры. Удалить все элементы, кратные 11.
#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int main()
{
	int* array;
	int length;
	
	inputSize(&length);
	memoryAllocation(&array, length);
	inputArray(array, length);
	printArray(array, length);
	delElement(&array, &length);
	printArray(array, length);
	free(array);
}
