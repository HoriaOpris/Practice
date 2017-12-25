/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 21000?
 *
 *
 * */
#include <stdio.h>
#include <math.h>

static void printToFindPattern(void);
static unsigned int getSumOfDigits(unsigned int number);
static unsigned int getTwoToThePow(unsigned int power);
static void itoa(long i, char* s);

int main(void)
{
	printToFindPattern();

	getSumOfDigits(4421);

	return 0;
}

static void printToFindPattern(void)
{
	for (int i = 1; i < 20; i++)
	{
		printf("%d\n", getTwoToThePow(i));
	}
}

static unsigned int getSumOfDigits(unsigned int number)
{
	char stringNo[20];

	itoa(number, stringNo);

	printf("\n string: %s\n", stringNo);

	return 0;
}

static void itoa(long i, char* s)
{
	sprintf(s, "%ld", i);
}

static unsigned int getTwoToThePow(unsigned int power)
{
	return pow(2, power);
}
