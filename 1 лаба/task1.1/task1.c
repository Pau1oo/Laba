#include <stdio.h>
#include <math.h>
int main()
{
	float num1, num2, geom;
	printf("Input 2 numbers\n");
	scanf_s("%f %f", &num1, &num2);
	float arith = (num1 + num2) / 2;
	if ((num1 == 0) || (num2 == 0))
		geom = 0;
	if (num1 < 0)
		num1 = -num1;
	if (num2 < 0)
		num2 = -num2;
	geom = sqrt(num1 * num2);
	printf("Arithmetic mean: %.3f \nGeometric mean: %.3f", arith, geom);
}







