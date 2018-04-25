#ifndef INCOMPLETE_H_
#define INCOMPLETE_H_

typedef struct Calculator *CALC;

extern void Init(CALC *c);
extern void Push(CALC c, unsigned data);
extern void PrintSum(CALC c);

#endif /* INCOMPLETE_H_ */
