/* Goals are:
 * - understand preemptive scheduling
 * - understand locking, mutex, ...
 *
 * */

#include <stdio.h>

static void Task_one(void);
static void Task_two(void);

void main(void)
{
	for(unsigned i = 0; i< 10; i++)
	{
		Task_one();
		Task_two();
	}
}

static void Task_one(void)
{
	for(unsigned i = 0; i < 3; i++)
		printf("%d ", i);

	printf("\n");
}

static void Task_two(void)
{
	for(unsigned i = 0; i < 11; i++)
		printf("%c ", i + 97);

	printf("\n");
}
