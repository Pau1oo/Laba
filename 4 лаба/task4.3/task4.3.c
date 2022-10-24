#include <stdio.h>
#include <stdlib.h>

int main()
{
	int matrix[100][100], i, j, N, option, jTemp = 2, SUM = 0, iTemp = 0;
	printf("Input the size of the matrix (N)\n");

	while (scanf_s("%d", &N) != 1 || N < 3 || N > 100)
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
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
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

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				printf("%d ", matrix[i][j]);
				if (j == N - 1)
					printf("\n");
			}
		}
		break;

	case 2:
		printf("\n");
		srand(time(NULL));
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				matrix[i][j] = rand() % 10;
				printf("%d ", matrix[i][j]);
				if (j == N - 1)
					printf("\n");
			}
		}
		printf("\n");
		break;
	}

	for (j = 0; j <= N; j++, jTemp += 2, iTemp++)
	{
		for (i = 1 + iTemp; i - iTemp <= N - jTemp; i++)
		{
			SUM += matrix[i][j];
		}
	}
	printf("Sum of elements in 4th region: %d\n", SUM);
}