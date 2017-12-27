#include "p16.h"
#include <stdio.h>

enum testVerdict
{
	PASSED, FAILED
};

struct testData
{
	int number;
	enum testVerdict verdict;
	int expected;
	int actual;
};

static const char *testVerdict[] =
{ "Passed", "Failed" };

static struct testData test_p16_0(void);
static struct testData test_p16_1(void);

struct testData (*fp[])(void) =
{
	test_p16_0,
	test_p16_1
};

int main(void)
{
	struct testData test;

	for (int i = 0; i < sizeof(fp) / sizeof(fp[0]); i++)
	{
		test = fp[i]();

		printf("Test[%d]: %s", test.number, testVerdict[test.verdict]);

		if (test.verdict == FAILED)
		{
			printf(", Expected: %d \t Actual: %d \n", test.expected,
					test.actual);
		}

		printf("\n");
	}

	return 0;
}

static struct testData test_p16_0(void)
{
	struct testData test =
	{ .number = 0 };

	if (P16_GetSumOfTwosPower(1000) == 1366)
		test.verdict = PASSED;
	else
		test.verdict = FAILED;

	return test;
}

static struct testData test_p16_1(void)
{
	struct testData test =
	{ .number = 1 };

	test.expected = 980;
	test.actual = P16_GetSumOfTwosPower(900);

	if (test.expected == test.actual)
		test.verdict = PASSED;
	else
		test.verdict = FAILED;

	return test;
}
