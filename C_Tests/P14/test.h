typedef struct
{
	int number;
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
