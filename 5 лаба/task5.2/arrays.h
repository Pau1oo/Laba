int maxElement(int** matrix, int numOfRow)
{
    int max = 0;
    int j = 0;
    while (matrix[numOfRow][j] != 0)
    {
       if (matrix[numOfRow][j] > max)
           max = matrix[numOfRow][j];
       j++;
    }
    return max;
}

void inputSize(int* numR)
{
    printf("Input the number of rows: ");
    while (scanf_s("%d", numR) != 1)
    {
        printf("Try again!\n");
        printf("Input the number of rows: ");
        rewind(stdin);
    }
}

void memoryAllocation(int*** matrix, int numR)
{
    *matrix = (int**)malloc(numR * sizeof(int*));
}

void inputMatrix(int** matrix, int numR)
{
    for (int i = 0; i < numR; i++)
    {
        matrix[i] = (int*)malloc(1 * sizeof(int));
        int j = 0;
        printf("Input the elements of row [%d]:\n", i + 1);

        while (scanf_s("%d", &matrix[i][j]) && matrix[i][j] != 0)
        {
            j++;
            matrix[i] = (int*)realloc(matrix[i], (j + 1) * sizeof(int));
        }
    }
}

void printMatrix(int** matrix, int numR)
{
    for (int i = 0; i < numR; i++)
    {
        int j = 0;

        while (matrix[i][j] != 0)
        {
            printf("%5d", matrix[i][j]);
            j++;
        }

        printf("%5d", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void delElement(int** matrix, int numR)
{
    for (int i = 0; i < numR; i++)
    {
        int j = 0;

        while (matrix[i][j] != 0)
        {
            if (matrix[i][j] == maxElement(matrix, i))
                j++;
            else
            {
                printf("%5d", matrix[i][j]);
                j++;
            }
        }
        printf("    0    ");
        printf("\n");
    }
}