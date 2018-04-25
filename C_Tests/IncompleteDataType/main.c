#include "incomplete.h"

int main(void)
{
	CALC c;

	Init(&c);
	Push(c, 20);
	Push(c, 30);
	PrintSum(c);
}
