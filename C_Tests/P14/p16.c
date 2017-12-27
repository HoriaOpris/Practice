/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 *
 *
 * */

#include "p16.h"
#include "utils/bigint.h"

extern int P16_GetSumOfTwosPower(int power)
{
	int sum;
	BigInt bigInteger;

	BigInt_New(&bigInteger);

	for (int i = 0; i < power; i++)
		BigInt_Operation(MULTIPLY, bigInteger, 2);

	sum = BigInt_GetSumOfDigits(bigInteger);
	BigInt_Free(bigInteger);

	return sum;
}
