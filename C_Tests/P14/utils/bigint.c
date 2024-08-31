#include "bigint.h"
#include <stdlib.h>

static void IncrementTerminatorMarker(int *digit);

extern void BigInt_New(BigInt *value)
{
	*value = malloc(1000 * sizeof(int));

	for (int i = 0; i < 1000; i++)
		(*value)[i] = 0;

	// 2^0
	(*value)[0] = 1;
	(*value)[1] = 't';
}

extern void BigInt_Operation(Operation op, BigInt lval, int rval)
{
	int carry = 0;

	for (int i = 0; i < 1000; i++)
	{
		// if not end of number
		if (lval[i] != 't')
		{
			switch (op)
			{
			case ADD:
				lval[i] += rval;
				break;

			case MULTIPLY:
				lval[i] *= rval;
				break;

			default:
				break;
			}

			lval[i] += carry;
			carry = 0;

			if (lval[i] > 9)
			{
				lval[i] %= 10;
				carry = 1;

				IncrementTerminatorMarker(&lval[i + 1]);
			}
		}
		else
		{
			break;
		}
	}
}

extern int BigInt_GetSumOfDigits(BigInt value)
{
	int sum = 0;

	for (int i = 1000 - 1; i >= 0; i--)
	{
		if (value[i] == 't')
		{
			for (int j = i - 1; j >= 0; j--)
			{
				sum += value[j];
			}

			break;
		}
	}

	return sum;
}

extern void BigInt_Free(BigInt value)
{
	free(value);
}

static void IncrementTerminatorMarker(int *digit)
{
	if (digit[0] == 't')
	{
		digit[0] = 0;
		digit[1] = 't';
	}
}
