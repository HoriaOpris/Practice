/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 *
 *
 * */

#include "p16.h"
#include "malloc.h"

static void MultiplyNumberBy(int *bigInteger, int rval);
static int CalculateSum(int *bigInteger);
static void IncrementTerminatorMarker(int *digit);
static void InitBigInteger(int **bigInteger);

extern int P16_GetSumOfTwosPower(int power)
{
	int *bigInteger;
	InitBigInteger(&bigInteger);

	for (int i = 0; i < power; i++)
	{
		MultiplyNumberBy(bigInteger, 2);
	}

	return CalculateSum(bigInteger);
}

static void InitBigInteger(int **bigInteger)
{
	*bigInteger = malloc(1000 * sizeof(int));

	for (int i = 0; i < 1000; i++)
		(*bigInteger)[i] = 0;

	// 2^0
	(*bigInteger)[0] = 1;
	(*bigInteger)[1] = 't';
}

static int CalculateSum(int *bigInteger)
{
	int sum = 0;

	for (int i = 1000 - 1; i >= 0; i--)
	{
		if (bigInteger[i] == 't')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				sum += bigInteger[j];
			}

			break;
		}
	}

	return sum;
}

static void MultiplyNumberBy(int *bigInteger, int rval)
{
	int carry = 0;

	for (int i = 0; i < 1000; i++)
	{
		// if not end of number
		if (bigInteger[i] != 't')
		{
			bigInteger[i] *= rval;
			bigInteger[i] += carry;
			carry = 0;

			if (bigInteger[i] > 9)
			{
				bigInteger[i] %= 10;
				carry = 1;

				IncrementTerminatorMarker(&bigInteger[i + 1]);
			}
		}
		else
		{
			break;
		}
	}
}

static void IncrementTerminatorMarker(int *digit)
{
	if (digit[0] == 't')
	{
		digit[0] = 0;
		digit[1] = 't';
	}
}
