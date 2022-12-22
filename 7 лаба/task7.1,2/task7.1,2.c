#include "string.h"
#include <stdio.h> 
#include <stdlib.h> 

void main() 
{
	int choice;
	void (*fun) (char**, char**);
	printf("Choose task 1 (flip K(th) word)\nor\n2 (before every character C inside S put S0)\n");
	while (scanf_s("%d", &choice) != 1 || (choice != 1 && choice != 2) || getchar() != '\n') 
	{
		printf("Try again\n");
		rewind(stdin);
	}
	char* line1, *line2;
	if (choice == 1) 
	{
		fun = task_one;
	}
	else 
	{
		fun = task_two;
	}
	fun(&line1, &line2);
}