/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <stdio.h>

static unsigned digits[] = {3, 1, 2};

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

void main(void)
{
	unsigned res[6] = {0};

	for (unsigned j = 0; j < Factorial(3); j++)
		for (unsigned i = 0; i < 3; i++)
		{
			res[j] += digits[i] * PowerOfTen(i);
		}

	printf("%d %d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4], res[5]);
}