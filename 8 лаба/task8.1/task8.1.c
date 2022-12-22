#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char** argv) 
{
	if (argc < 2) 
	{
		printf("No arguments, restart");
		return;
	}
	char** str = copy(argc, argv);
	printf("Your arguments, sorted by amount of words of even number of characters:\n");
	sort_insert(argc, str);
	type(argc, str);
}