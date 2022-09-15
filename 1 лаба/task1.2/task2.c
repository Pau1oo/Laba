#include <stdio.h>
#include <math.h>

int main()
{
	float R, B;
	printf("Input radius and the length of the side\n");
	scanf_s("%f %f", &R, &B);
	if(B <= R * sqrt(2))
		printf("Possible");
	else
		printf("Impossible");

}