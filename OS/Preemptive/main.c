/* Goals are:
 * - understand preemptive scheduling
 * - understand locking, mutex, ...
 *
 * */

#include <stdio.h>

static inline volatile unsigned long long RDTSC(void);
static void Task_one(void);
static void Task_two(void);

void main(void)
{
	unsigned long long current= 0, previous = 0;

	for(unsigned i = 0; i< 1000; i++)
	{
		Task_one();
		Task_two();

		current = RDTSC();

		printf("Time difference time: %lld \n ", current - previous);

		previous = current;
	}
}

static inline volatile unsigned long long RDTSC(void) {
   register unsigned long long TSC asm("eax");
   asm volatile (".byte 15, 49" : : : "eax", "edx");
   return TSC;
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
