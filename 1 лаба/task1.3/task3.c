#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c;
	int count = 0;
	printf("Input 3 numbers\n");
	scanf_s("%f %f %f", &a, &b, &c);
	if (a == round(a))
		count += 1;
	if (b == round(b))
		count += 1;
	if (c == round(c))
		count += 1;
	printf("Number of integers: %d", count);
}