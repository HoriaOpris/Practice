/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define ELEMENTS_IN(arr) (sizeof(arr) / sizeof(arr[0]))

static unsigned digits[] = {0, 1, 2};

static unsigned PowerOfTen(unsigned power)
{
	const unsigned result[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

	if (power < (sizeof(result) / sizeof(result[0])))
	{
		return result[power];
	}
	else
	{
		printf("power error!\n");
		return 0;
	}
}

static unsigned Factorial(unsigned n)
{
	if (n == 1)
		return 1;
	else
		return n * Factorial(n - 1);
}

static void Switch(unsigned *buf, unsigned pos_from, unsigned pos_with)
{
	unsigned temp = buf[pos_from];

	buf[pos_from] = buf[pos_with];
	buf[pos_with] = temp;
}

static unsigned ArrayToNumber(unsigned *buf, unsigned size)
{
	unsigned converted = 0;

	for (unsigned i = 0; i < size; i++)
	{
		converted += buf[i] * PowerOfTen(i);
	}

	return converted;
}

int main(void)
{
	/* Create array that holds all possible combinations 1 digit per unsigned int (4 bytes) */
	unsigned(*a)[ELEMENTS_IN(digits)] = malloc(Factorial(ELEMENTS_IN(digits)) * sizeof(digits));

	memcpy(&a[0][0], digits, sizeof(digits));

	for (unsigned i = 0; i < Factorial(ELEMENTS_IN(digits)); i++)
	{
		memcpy(a[i + 1], a[i], 12);
		Switch(a[i + 1], i % 2, (i % 2) + 1);

		printf("%d ", ArrayToNumber(&a[i][0], ELEMENTS_IN(digits)));
	}

	return 0;
}