enum testVerdict
{
	PASSED,
	FAILED
};

typedef struct
{
	int number;
	enum testVerdict verdict;
	int expected;
	int actual;
} TestInfo;

typedef TestInfo (*Test_FunctionPointer)(void);

struct TestFunctions
{
	Test_FunctionPointer pointToTest;
	struct TestFunctions *link;
};

extern void AddTest(struct TestFunctions *f, Test_FunctionPointer fp);

extern struct TestFunctions *testF;
