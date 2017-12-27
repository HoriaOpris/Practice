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
};

static const char *testVerdict[] =
{ "Passed", "Failed" };

static struct testData test_p16_0(void);

int main(void)
{
	struct testData test = test_p16_0();
	printf("Test[%d]: %s\n", test.number, testVerdict[test.verdict]);

	return 0;
}

static struct testData test_p16_0(void)
{
	struct testData test;
	test.number = 0;

	if (P16_GetSumOfTwosPower(1000) == 1366)
		test.verdict = PASSED;
	else
		test.verdict = FAILED;

	return test;
}
