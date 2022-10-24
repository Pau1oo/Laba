#include <stdio.h>
#include <stdlib.h>

int main()
{
	int matrix[100][100], i, j, row, col, option, max, countLine, countMax, flag = 0;
	printf("Input the size of the matrix (i, j)\n");

	while (scanf_s("%d", &row) != 1 || row < 1 || row > 100)
	{
		printf("Try again\n");
		rewind(stdin);
	}

	while (scanf_s("%d", &col) != 1 || col < 1 || col > 100)
	{
		printf("Try again\n");
		rewind(stdin);
	}

	printf("Choose an option:\n1) Keyboard input\n2) Initializing a matrix with random elements\n");
	scanf_s("%d", &option);

	while (option != 1 && option != 2)
	{
		printf("Try again\n");
		scanf_s("%d", &option);
		rewind(stdin);
	}

	switch (option)
	{
	case 1:
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				printf("Input the element [%d][%d]: ", i + 1, j + 1);
				while (scanf_s("%d", &matrix[i][j]) != 1)
				{
					printf("Try again\nInput the element [%d][%d]: ", i + 1, j + 1);
					rewind(stdin);
				}	
			}
		}
		printf("\n");

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				printf("%d ", matrix[i][j]);
				if (j == col - 1)
					printf("\n");
			}
		}
		break;

	case 2:
		printf("\n");
		srand(time(NULL));
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				matrix[i][j] = rand() % 10;
				printf("%d ", matrix[i][j]);
				if (j == col-1)
					printf("\n");
			}
		}
		printf("\n");
		break;
	}

	countLine = row;
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				countLine--;
				break;
			}
		}
	}
	printf("Number of lines that don't contain any null element: %d\n", countLine);

	while (flag == 0)
	{
		max = matrix[0][0];
		countMax = 0;

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (matrix[i][j] > max)
					max = matrix[i][j];
			}
		}

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (matrix[i][j] == max)
					countMax++;
			}
		}

		if (countMax > 1)
			flag = 1;
		else
		{
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
				{
					if (matrix[i][j] == max)
						matrix[i][j] = INT_MIN;
				}
			}
		}
	}

	if (countMax > 1 && max != INT_MIN)
		printf("The maximum of numbers that occur more than once in a given matrix: %d\n", max);
	if (max == INT_MIN)
		printf("There are no identical elements\n");
}