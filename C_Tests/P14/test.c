#include "p16.h"
#include "test.h"
#include "utils/bigint_test.h"
#include <stdio.h>

static const char *testVerdict[] = { "Passed", "Failed" };

static TestInfo test_p16_0(void);
static TestInfo test_p16_1(void);
static TestInfo test_p16_2(void);

Test_FunctionPointer fp[] = { test_p16_0, test_p16_1, test_p16_2 };

int main(void)
{
	TestInfo test;

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

static TestInfo test_p16_0(void)
{
	TestInfo test = { .number = 0 };

	if (P16_GetSumOfTwosPower(1000) == 1366)
		test.verdict = PASSED;
	else
		test.verdict = FAILED;

	return test;
}

static TestInfo test_p16_1(void)
{
	TestInfo test = { .number = 1 };

	test.expected = 1198;
	test.actual = P16_GetSumOfTwosPower(900);

	if (test.expected == test.actual)
		test.verdict = PASSED;
	else
		test.verdict = FAILED;

	return test;
}

static TestInfo test_p16_2(void)
{
	TestInfo test = { .number = 2 };

	test.expected = 11;
	test.actual = P16_GetSumOfTwosPower(7);

	if (test.expected == test.actual)
		test.verdict = PASSED;
	else
		test.verdict = FAILED;

	return test;
}
