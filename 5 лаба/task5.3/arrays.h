void delRow(int*** matrix, int* row, int* col)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < (*col); j++)
		{
			if ((*(*(*(matrix) + i) + j) == 0) && (*(*(*(matrix) + i) + (j + 1)) == 0))
			{
				for (int k = i; k < (*row) - 1; k++)
				{
					for (int n = 0; n < *col; n++)
					{
						*(*(matrix)+ k) = *(*(matrix)+ k + 1);
					}
				}
				i--;
				(*row)--;
				break;
			}
		}
	}

	*(matrix) = (int**)realloc(*(matrix), *row * sizeof(int*));
}

void inputSize(int* N, int* M)
{
	printf("Input the size of matrix (N,M):\n");
	while (scanf_s("%d", N) != 1 || N < 1 || getchar() != '\n')
	{
		printf("Try again!\n");
		rewind(stdin);
	}
	while (scanf_s("%d", M) != 1 || M <= 1 || getchar() != '\n')
	{
		printf("Try again!\n");
		rewind(stdin);
	}
}

void memoryAllocation(int*** matrix, int N, int M)
{
	*matrix = (int**)calloc(N, sizeof(int*));

	for (int i = 0; i < N; i++)
	{
		*(*(matrix)+i) = (int*)calloc(M, sizeof(int));
	}
}

void inputMatrix(int** matrix, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("Input the element [%d][%d]: ", i + 1, j + 1);
			while (scanf_s("%d", &matrix[i][j]) != 1)
			{
				printf("Try again!\n");
				printf("Input the element [%d][%d]: ", i + 1, j + 1);
				rewind(stdin);
			}
		}
	}
	printf("\n");
}

void printMatrix(int** matrix, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}