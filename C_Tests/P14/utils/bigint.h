typedef int * BigInt;

typedef enum
{
	ADD,
	MULTIPLY
} Operation;

extern void BigInt_New(BigInt *value);
extern void BigInt_Operation(Operation op, BigInt lval, int rval);
extern int BigInt_GetSumOfDigits(BigInt value);
extern void BigInt_Free(BigInt value);
