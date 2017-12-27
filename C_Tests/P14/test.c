#include "p16.h"
#include "test.h"
#include "utils/bigint_test.h"
#include <stdio.h>
#include <malloc.h>

static const char *testVerdict[] = { "Passed", "Failed" };

struct TestFunctions
{
	Test_FunctionPointer pointToTest;
	struct TestFunctions *link;
};

static TestInfo test_p16_0(void);
static TestInfo test_p16_1(void);
static TestInfo test_p16_2(void);

static void InitLinkedList(struct TestFunctions **f, Test_FunctionPointer fp);
static void AddTest(struct TestFunctions *f, Test_FunctionPointer fp);

static Test_FunctionPointer fp[] = { test_p16_0, test_p16_1, test_p16_2 };

int main(void)
{
	struct TestFunctions *testF;
	TestInfo test;

	InitLinkedList(&testF, test_p16_0);
	AddTest(testF, test_p16_1);
	AddTest(testF, test_p16_2);

	for (int i = 0; i < 4; i++)
	{
		if (testF != 0)
		{
			test = testF->pointToTest();
			testF = testF->link;

			printf("Test[%d]: %s", test.number, testVerdict[test.verdict]);

			if (test.verdict == FAILED)
			{
				printf(", Expected: %d \t Actual: %d \n", test.expected,
						test.actual);
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

static void InitLinkedList(struct TestFunctions **f, Test_FunctionPointer fp)
{
	*f = malloc(sizeof(struct TestFunctions));

	(*f)->link = 0;
	(*f)->pointToTest = fp;
}

static void AddTest(struct TestFunctions *f, Test_FunctionPointer fp)
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
