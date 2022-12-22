#include <stdio.h>
#include <stdlib.h>

int is_letter(char line) 
{
	if ((line >= 'a' && line <= 'z') || (line >= 'A' && line <= 'Z'))
		return 1;
	return 0;
}

int len(char* line) 
{
	int i = 0;
	for (; line[i] != '\0'; i++);
	return i;
}

char** copy(int argc, char** argv) 
{
	char** str = malloc(argc * sizeof(char*));
	for (int i = 0; i < argc; i++) 
	{
		str[i] = calloc(len(argv[i]), sizeof(char));
		for (int j = 0; j <= len(argv[i]); j++) 
		{
			str[i][j] = argv[i][j];
		}
	}
	return str;
}

int get_min_len(char* line) 
{
	int min = 0, start = 0;
	for (int i = len(line); i != 0; i--) 
	{
		if (is_letter(line[i - 1]) && !is_letter(line[i])) 
		{
			start = i;
		}
		if (!is_letter(line[i - 1]) && is_letter(line[i])) 
		{
			if (min == 0 || min > start - i) 
			{
				min = start - i;
			}
			start = 0;
		}
	}
	if (start != 0)
		if (min == 0 || min > start) 
		{
			min = start;
		}
	return min;
}

void swap(char** line1, char** line2) 
{
	char* temp = *line1;
	*line1 = *line2;
	*line2 = temp;
}

void sort_insert(int argc, char** argv) 
{
	if (argc == 2)
		return;
	for (int i = 1; i < argc - 1; i++)
		if (get_min_len(argv[i]) > get_min_len(argv[i + 1])) 
		{
			for (int j = i; get_min_len(argv[j]) > get_min_len(argv[j + 1]) && j > 0; j--) 
			{
				swap(argv + j, argv + j + 1);
			}
		}
}

void type(int argc, char** argv) 
{
	for (int i = 1; i < argc; i++)
		printf("%s %d\n", argv[i], get_min_len(argv[i]));
}