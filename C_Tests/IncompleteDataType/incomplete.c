#include "incomplete.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 20

/* Because this is used as an incomplete type by other modules it does
 * not matter whether you change the field or add other fields. Only this
 * C file will recompile in any changes done to this structure. */
struct Calculator
{
	unsigned byte[MAX_SIZE];
	unsigned length;
};

extern void Init(CALC *c)
{
	*c = malloc(sizeof(struct Calculator));
	(*c)->length = 0;

	for (unsigned i = 0; i < MAX_SIZE; i++)
		(*c)->byte[i] = 0;
}

extern void Push(CALC c, unsigned data)
{
	c->byte[c->length++] = data;
}

extern void PrintSum(CALC c)
{
	unsigned sum = 0;

	for (unsigned i = 0; i < c->length; i++)
		sum += c->byte[i];

	printf("Sum is:%d\n", sum);
}
