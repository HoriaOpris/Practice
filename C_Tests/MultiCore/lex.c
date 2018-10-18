/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <stdio.h>
#include <string.h>

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
/*
static unsigned Factorial(unsigned n)
{
if (n == 1)
return 1;
else
return n * Factorial(n - 1);
}*/

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
	unsigned a[3], b[3], c[3];

	memcpy(a, digits, sizeof(a));
	memcpy(b, a, sizeof(a));
	Switch(b, 2, 1);

	memcpy(c, b, sizeof(a));
	Switch(c, 1, 2);

	printf("%d ", ArrayToNumber(b, sizeof(b) / sizeof(b[0])));
	printf("%d ", ArrayToNumber(c, sizeof(c) / sizeof(c[0])));

	return 0;
}