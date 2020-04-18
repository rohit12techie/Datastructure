#ifndef __STACK_H__
#define __STACK_H__

typedef struct _stack{
	int top;
	int maxsize;
	void **store;
}stack;

stack* createstack(int size);
int push(stack *S, void *data);
void* pop(stack *S);
void deletestack(stack *S);
int isstackempty(stack *s);
int isstackfull(stack *s);

#endif 
