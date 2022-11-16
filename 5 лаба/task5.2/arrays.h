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
