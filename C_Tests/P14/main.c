/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 21000?
 *
 *
 * */
#include<stdio.h>
#include<math.h>

static void printToFindPattern(void);
static unsigned int getTwoToThePow(unsigned int power);

int main(void)
{
	printToFindPattern();

	return 0;
}

static void printToFindPattern(void)
{
	for (int i = 1; i < 20; i++)
	{
		printf("%d\n", getTwoToThePow(i));
	}
}

static unsigned int getTwoToThePow(unsigned int power)
{
	return pow(2, power);
}
