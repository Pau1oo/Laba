#include <stdio.h> 
#include <stdlib.h>

int is_letter(char* line, int i) 
{
	if ((*(line + i) >= 'a' && *(line + i) <= 'z') || (*(line + i) >= 'A' && *(line + i) <= 'Z'))
		return 1;
	return 0;
}

void flip(char* str, int st, int end) 
{
	for (int i = st; 2 * i < end + st; i++) 
	{
		char tmp = str[i];
		str[i] = str[end + st - i];
		str[end + st - i] = tmp;
	}
}

int get_words(char* str) 
{
	int wrd = 0;
	for (int i = 0; str[i] != '\0'; i++) 
	{
		if (is_letter(str, i) && !is_letter(str, i + 1))
			wrd++;
	}
	return wrd;
}

void print(char* ptr) 
{
	for (int i = 0; ptr[i] != '\0'; i++)
		printf("%c", ptr[i]);
}

char* reall(char* ptr, int size, int sizenew) 
{
	char* ptr1 = (char*)calloc(sizenew, sizeof(char));
	for (int i = 0; (i < size && i < sizenew); i++)
		*(ptr1 + i) = *(ptr + i);
	*(ptr1 + sizenew) = '\0';
	return ptr1;
}

void insert(char* line, int len1, int start, char* lineput, int len2) 
{
	for (int i = len1; i >= start; i--) 
	{
		line[i + len2] = line[i];
	}
	for (int i = start; i < start + len2; i++) 
	{
		line[i] = lineput[i - start];
	}
}

void task_one(char** line, char** line2) 
{
	int k, len = 16;
	printf("Enter string \n");
	*line = (char*)calloc(len, sizeof(char));
	for (int i = 0;; i++) 
	{
		*(*line + i) = getchar();
		if (*(*line + i) == '\n') 
		{
			*line = reall(*line, len, i);
			len = i;
			break;
		}
		else 
		{
			if (i == len - 2) 
			{
				len *= 2;
				*line = reall(*line, len / 2, len);
			}
		}
	}
	printf("Enter k\n");
	while (scanf_s("%d", &k) != 1 || k<1 || k > get_words(*line) || getchar() != '\n') 
	{
		printf("Try again\n");
		rewind(stdin);
	}
	int end = 0, start = 0;
	for (int i = len, n = get_words(*line); i >= 0; i--) 
	{
		if (!is_letter(*line, i) && is_letter(*line, i - 1))
			end = i - 1;
		if (is_letter(*line, i) && !is_letter(*line, i - 1)) 
		{
			start = i;
			if (n == k) 
			{
				flip(*line, start, end);
			}
			n--;
		}
	}
	print(*line);
}

void task_two(char** line1, char** line2) 
{
	int len1 = 16, len2 = 16;
	printf("Enter string S\n");
	*line1 = (char*)calloc(len1, sizeof(char));
	for (int i = 0;; i++) {
		*(*line1 + i) = getchar();
		if (*(*line1 + i) == '\n') 
		{
			*line1 = reall(*line1, len1, i);
			len1 = i;
			break;
		}
		else 
		{
			if (i == len1 - 2) 
			{
				len1 *= 2;
				*line1 = reall(*line1, len1 / 2, len1);
			}
		}
	}
	printf("Enter string S0\n");
	*line2 = (char*)calloc(len2, sizeof(char));
	for (int i = 0;; i++) 
	{
		*(*line2 + i) = getchar();
		if (*(*line2 + i) == '\n') 
		{
			*line2 = reall(*line2, len2, i);
			len2 = i;
			break;
		}
		else 
		{
			if (i == len2 - 2) 
			{
				len2 *= 2;
				*line2 = reall(*line2, len2 / 2, len2);
			}
		}
	}
	printf("Enter the character C: ");
	char symb = getchar();
	for (int i = len1; i >= 0; i--) 
	{
		if (line1[0][i] == symb) 
		{
			*line1 = reall(*line1, len1, len1 + len2);
			insert(*line1, len1, i, *line2, len2);
			len1 += len2;
		}
	}
	print(*line1);
}