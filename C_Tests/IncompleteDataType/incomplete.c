#include "incomplete.h"
#include <malloc.h>
#include <stdio.h>

/* Because this is used as an incomplete type by other modules it does
 * not matter whether you change the field or add other fields. Only this
 * C file will recompile in any changes done to this structure */
struct Calculator
{
	unsigned byte[20];
};

extern void Init(CALC *c)
{
	*c = malloc(sizeof(struct Calculator));

	for (unsigned i = 0; i < sizeof(struct Calculator); i++)
		(*c)->byte[i] = 0;


	for (unsigned i = 0; i < 20; i++)
		printf("%d ", (*c)->byte[i]);
}
