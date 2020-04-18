#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define INPUTLEN 15
#define STACKLEN 10

enum {INT, CHAR, STRING, BTNODE, LISTNODE};

typedef struct _btnode{
	int data;
	struct _node *left;
	struct _node *right;
}btnode;

typedef struct _listnode{
	int data;
	struct _node *next;
}listnode;

void showstack(stack *S, int type){
        int i = 0;
	for(; i<=(S->top-1); i++){
		if(type == INT){
	             printf("[%d] ",*(int*)S->store[i]);
		}
		if(type == CHAR){
	             printf("[%c] ",*(char*)S->store[i]);
		}
		if(type == STRING){
	             printf("[%s] ",(char*)S->store[i]);
		}
		if(type == BTNODE){
		     btnode *node = (btnode*)S->store[i];
	             printf("[%d|%p|%p] ",node->data, node->left, node->right);
		}
		if(type == LISTNODE){
		     listnode *node = (listnode*)S->store[i];
	             printf("[%d|%p] ",node->data, node->next);
		}

        }
        printf("\n");
}

void testintdata(){
	stack *s = createstack(STACKLEN);
	int i;
	int data[]={1,2,3,4,5,6,7,8,9,10,11,12};
	for(i=0; i<INPUTLEN; i++){
		push(s,&data[i]);
		showstack(s,INT);
	}
	for(i=0; i<INPUTLEN; i++){
		pop(s);
		showstack(s,INT);
	}
	deletestack(s);
}

void testchardata(){
	stack *s = createstack(STACKLEN);
	char i;
	char data[] ={'a','b','c','d','e','f','g','h','i','j'};
	for(i=0; i<=INPUTLEN; i++){
		push(s,&data[i]);
		showstack(s, CHAR);
	}
	for(i=0; i<INPUTLEN; i++){
		pop(s);
		showstack(s, CHAR);
	}
	deletestack(s);
}

void teststringdata(){
	stack *s = createstack(STACKLEN);
	int i;
	char *data[] ={"Rohit","Kumar","Binay","Apurv","Abhi","Sanjog","Amresh","Kaushal","ravi","brahma"};
	for(i=0; i<INPUTLEN; i++){
		push(s,data[i]);
		showstack(s,STRING);
	}
	for(i=0; i<INPUTLEN; i++){
		pop(s);
		showstack(s,STRING);
	}
	deletestack(s);

}

void testbtnodedata(){
	stack *s = createstack(STACKLEN);
	int i;
	for(i=0; i<INPUTLEN; i++){
		btnode *newnode = malloc(sizeof(btnode));
		newnode->data = i*10;
		newnode->left = NULL;
		newnode->right = NULL;

		push(s,newnode);
		showstack(s, BTNODE);
	}
	for(i=0; i<INPUTLEN; i++){
		pop(s);
		showstack(s, BTNODE);
	}
	deletestack(s);
}

void testlistnodedata(){
	stack *s = createstack(STACKLEN);
	int i;
	for(i=0; i<INPUTLEN; i++){
		listnode *newnode = malloc(sizeof(listnode));
		newnode->data = i*5;
		newnode->next = NULL;
		push(s,newnode);
		showstack(s, LISTNODE);
	}
	for(i=0; i<INPUTLEN; i++){
		pop(s);
		showstack(s, LISTNODE);
	}
	deletestack(s);
}

int main(){	
	testintdata();
	testchardata();
	teststringdata();
	testbtnodedata();
	testlistnodedata();
	return 0;
}
