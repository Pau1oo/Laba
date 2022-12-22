// 1. ¬ одномерном массиве выполнить сортировку нечетных элементов до последнего положительного методом Ўелла

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "arrays.h"

int main()
{
	int* array;
	int* array2;
	int* activeArray = NULL; 
	int* activeArray2 = NULL;
	int size, sizeActiveArray = 1, sizeActiveArray2 = 1, option;

	inputSize(&size);
	memoryAllocation(&array, &array2, size);
	chooseTypeInput(&option);
	inputArray(array, size, option);
	arrayCopy(array, array2, size);
	extractArray(array, &activeArray, size, &sizeActiveArray);
	extractArray(array, &activeArray2, size, &sizeActiveArray2);
	//printArray(array, size);
	//printf("\n");

	ShellSort(activeArray, sizeActiveArray);
	extractArray2(array, &activeArray, size, &sizeActiveArray);
	//printArray(array, size);
	//printf("\n");

	bubbleSort(activeArray2, sizeActiveArray2);
	//printArray(array, size);
	//printf("\n");

	ShellSort2(array, size);
	extractArray2(array2, &activeArray, size, &sizeActiveArray);
	//printArray(array2, size);
}