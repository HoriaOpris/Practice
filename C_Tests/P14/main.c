#include "p16.h"
#include <stdio.h>
#include "P138/isosceles.h"

int main(void)
{
	printf("Sum = %d \n", P16_GetSumOfTwosPower(1000));
	printf("Isoscel valid: %d\n", Iso_Init());

	return 0;
}
