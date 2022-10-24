#include <stdio.h>
#include <stdlib.h>

int main()
{
	int matrix[100][100], reverseMatrix[1][100], i, j, row, col, option, count, temp, position = -1;
	printf("Input the size of the matrix (i, j)\n");

	while (scanf_s("%d", &row) != 1 || row < 1 || row > 100 || getchar() != '\n')
	{
		printf("Try again\n");
		rewind(stdin);
	}

	while (scanf_s("%d", &col) != 1 || col < 1 || col > 100 || getchar() != '\n')
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
				if (j == col - 1)
					printf("\n");
			}
		}
		printf("\n");
		break;
	}

	for (i = 0, count = 0; i < row; i++)
	{
		for (j = col - 1; j >= 1; j--)
		{
			if (matrix[i][j] < matrix[i][j - 1])
			{
				count++;
			}
			else
			{
				count = 0;
				break;
			}
		}
		if (count == col - 1)
		{
			position = i;
			break;
		}
	}

	printf("\n");

	if (position == -1)
	{
		printf("There are no such lines\n");
		return 0;
	}
		
	for (i = 0; i < row; i++)
	{
		for (j = 0, temp = col - 1; j < col; j++, temp--)
		{
			if (i == position)
			{
				printf("%d ", matrix[i][temp]);
			}
			else
				printf("%d ", matrix[i][j]);
			if (j == col - 1)
				printf("\n");
		}
	}
}