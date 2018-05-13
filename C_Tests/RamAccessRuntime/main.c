#include <stdio.h>
#include <time.h>
#include <stdlib.h>

static unsigned algorithm_holder;
static unsigned char *garbage;

static void FillWithGarbage(unsigned char **fromAddress, unsigned size)
{
	unsigned i;

	*fromAddress = (unsigned char *) malloc(size);

	for (i = 0; i < size; i++)
		(*fromAddress)[i] = (i + 3) * (size / (i + 1));
}

static void PerformFakeHashing(unsigned char *fromAddress, unsigned size)
{
	unsigned i;

	for (i = 0; i < size; i++)
		algorithm_holder *= fromAddress[i];
}

int main(void)
{
	clock_t begin;

	FillWithGarbage(&garbage, 1000 * 1000);

	begin = clock();
	PerformFakeHashing(garbage, 1000 * 1000);

	clock_t end = clock();
	double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;

	printf("Time spent: %f \n", time_spent);

	return 0;
}
