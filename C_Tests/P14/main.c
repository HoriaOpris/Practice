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
static char removeAsciiComponent(char asciiNo);

int main(void)
{
	printToFindPattern();

	getSumOfDigits(4421);

	return 0;
}

static void printToFindPattern(void)
{
	for (int i = 1; i < 20; i++)
		printf("Number:%d \t Sum of digits:%d \n", getTwoToThePow(i),
				getSumOfDigits(getTwoToThePow(i)));
}

static unsigned int getSumOfDigits(unsigned int number)
{
	char stringNo[20];
	unsigned int sumOfDigits = 0;

	itoa(number, stringNo);

	for (int i = 0; i < 20; i++)
		if (stringNo[i] != 0)
			sumOfDigits += removeAsciiComponent(stringNo[i]);
		else
			break;

	return sumOfDigits;
}

static char removeAsciiComponent(char asciiNo)
{
	const char asciiComponent = 48;

	if (asciiNo >= asciiComponent)
		asciiNo -= asciiComponent;
	else
		/* Todo @Horia: Error handling necessary? */

		return asciiNo;
}

static void itoa(long i, char* s)
{
	sprintf(s, "%ld", i);
}

static unsigned int getTwoToThePow(unsigned int power)
{
	return pow(2, power);
}
