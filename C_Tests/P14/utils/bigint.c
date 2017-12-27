#include "bigint.h"
#include <malloc.h>

extern void BigInt_New(BigInt *value)
{
	*value = malloc(1000 * sizeof(int));

	for (int i = 0; i < 1000; i++)
		(*value)[i] = 0;

	// 2^0
	(*value)[0] = 1;
	(*value)[1] = 't';
}
