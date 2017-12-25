/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 21000?
 *
 *
 * */

#include<stdio.h>
#include<math.h>

unsigned int getTwoToThePow(unsigned int power);

int main(void)
{
	printf("Test:%d \n", getTwoToThePow(15));

	return 0;
}

unsigned int getTwoToThePow(unsigned int power)
{
	return pow(2,power);
}
