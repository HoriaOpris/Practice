#include "p16.h"
#include "test.h"
#include "utils/bigint_test.h"
#include <stdio.h>
#include <malloc.h>

enum testVerdict
{
	PASSED,
	FAILED
};

static const char *testVerdict[] = { "Passed", "Failed" };

static TestInfo test_p16_0(void);
static TestInfo test_p16_1(void);
static TestInfo test_p16_2(void);
static void InitLinkedList(struct TestFunctions **f, Test_FunctionPointer fp);
static enum testVerdict CalcTestVerdict(TestInfo info);

struct TestFunctions *testF;

int main(void)
{
	TestInfo testInfo;

	InitLinkedList(&testF, test_p16_0);
	AddTest(testF, test_p16_1);
	AddTest(testF, test_p16_2);

	BigInt_Test();

	while (1)
	{
		if (testF != 0)
		{
			testInfo = testF->pointToTest();
			testF = testF->link;

			enum testVerdict verdict = CalcTestVerdict(testInfo);

			printf("Test[%d]: %s", testInfo.id, testVerdict[verdict]);

			if (verdict == FAILED)
			{
				printf(", Expected: %d \t Actual: %d", testInfo.expected,
						testInfo.actual);
			}

			printf("\n");
		}
		else
		{
			break;
		}
	}

	return 0;
}

static enum testVerdict CalcTestVerdict(TestInfo info)
{
	enum testVerdict verdict;

	if (info.expected == info.actual)
		verdict = PASSED;
	else
		verdict = FAILED;

	return verdict;
}
extern void AddTest(struct TestFunctions *f, Test_FunctionPointer fp)
{
	struct TestFunctions *newF = malloc(sizeof(struct TestFunctions));

	newF->link = 0;
	newF->pointToTest = fp;

	for (int i = 0; i < 10; i++)
	{
		if (f->link == 0)
		{
			f->link = newF;
			break;
		}

		f = f->link;
	}
}

static void InitLinkedList(struct TestFunctions **f, Test_FunctionPointer fp)
{
	*f = malloc(sizeof(struct TestFunctions));

	(*f)->link = 0;
	(*f)->pointToTest = fp;
}

static TestInfo test_p16_0(void)
{
	TestInfo test = { .id = 0 };

	test.expected = 1366;
	test.actual = P16_GetSumOfTwosPower(1000);

	return test;
}

static TestInfo test_p16_1(void)
{
	TestInfo test = { .id = 1 };

	test.expected = 1198;
	test.actual = P16_GetSumOfTwosPower(900);

	return test;
}

static TestInfo test_p16_2(void)
{
	TestInfo test = { .id = 2 };

	test.expected = 11;
	test.actual = P16_GetSumOfTwosPower(7);

	return test;
}
