/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 *
 *
 * */

#include "p16.h"

#define ARR_SIZE(arr) sizeof(arr) / sizeof(arr[0])

static void store(void);
static int CalculateSum(void);

// storing result digits one byte at a time by doubling
static int storedDigits[1000];

extern int P16_GetSumOfTwosPower(int power)
{
	// 2^0
	storedDigits[0] = 1;
	storedDigits[1] = 't';

	for (int i = 0; i < power; i++)
	{
		store();
	}

	return CalculateSum();
}

static int CalculateSum(void)
{
	int sum = 0;

	for (int i = ARR_SIZE(storedDigits) - 1; i >= 0; i--)
	{
		if (storedDigits[i] == 't')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				sum += storedDigits[j];
			}
			break;
		}
	}

	return sum;
}

static void store(void)
{
	int carry = 0;

	for (int i = 0; i < ARR_SIZE(storedDigits); i++)
	{
		// if not end of
		if (storedDigits[i] != 't')
		{
			storedDigits[i] *= 2;
			storedDigits[i] += carry;
			carry = 0;

			if (storedDigits[i] > 9)
			{
				storedDigits[i] %= 10;
				carry = 1;

				if (storedDigits[i + 1] == 't')
				{
					storedDigits[i + 1] = 0;
					storedDigits[i + 2] = 't';
				}
			}
			else
			{
				//break;
			}
		}
		else
		{
			break;
		}
	}
}
