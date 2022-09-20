#include <stdio.h>

int main()
{
	int num;
	printf("Input the number of month\n1.January\n2.February\n3.March\n4.April\n5.May\n6.June\n7.July\n8.August\n9.September\n10.October\n11.November\n12.December\n");
	scanf_s("%d", &num);
	
	switch (num)
	{
	case 1:
		printf("31");
		break;
	case 2:
		printf("28");
		break;
	case 3:
		printf("31");
		break;
	case 4:
		printf("30");
		break;
	case 5:
		printf("31");
		break;
	case 6:
		printf("30");
		break;
	case 7:
		printf("31");
		break;
	case 8:
		printf("31");
		break;
	case 9:
		printf("30");
		break;
	case 10:
		printf("31");
		break;
	case 11:
		printf("30");
		break;
	case 12:
		printf("31");
		break;
	}
}