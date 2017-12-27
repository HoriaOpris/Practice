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
