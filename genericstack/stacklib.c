#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack* createstack(int size)
{
	stack *S = malloc(sizeof(stack));
	S->top = -1;
	S->maxsize = size;
	S->store = malloc(sizeof(void**)*size);
}

int push(stack *S, void *data)
{
	if(isstackfull(S))
	{
		printf("Stack is full\n");
		return -1;	
	}
	else
	{
		S->store[++S->top] = data; 	
	}
	return 0;
}

void* pop(stack *S)
{
	if(isstackempty(S))
	{
		printf("Stack is empty\n");
		return NULL;
	}
	else
	{
		return S->store[S->top--];
	}
}

void deletestack(stack *S)
{
	if(S != NULL)
	{
		free(S->store);	
		free(S);
		S=NULL;
	}
}

int isstackempty(stack *S)
{
	if( S!= NULL )
	{
		if(S->top == -1){
			return 1;
		}
	}
	return 0;
}

int isstackfull(stack *S)
{
	if(S!=NULL)
	{
		if(S->top == S->maxsize){
			return 1;
		}
	}
	return 0;
}

