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