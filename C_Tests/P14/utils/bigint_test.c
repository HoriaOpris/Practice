#include"bigint_test.h"
#include"bigint.h"
#include"../test.h"

static TestInfo Test_0(void);

extern void BigInt_Test(void)
{
	AddTest(testF, Test_0);
}

static TestInfo Test_0(void)
{
	TestInfo test = { .number = 3 };
	BigInt bigInt;

	BigInt_New(&bigInt);

	BigInt_Operation(MULTIPLY, bigInt, 6);
	BigInt_Operation(MULTIPLY, bigInt, 3);

	test.expected = 9;
	test.actual = BigInt_GetSumOfDigits(bigInt);

	BigInt_Free(bigInt);

	return test;
}
