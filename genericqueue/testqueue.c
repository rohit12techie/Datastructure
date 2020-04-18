#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define INPUTLEN 15
#define QUEUELEN 10

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

void showqueue(queue *Q, int type){
        int i = Q->f;
        if(Q->f == -1){
                i = 0;
        }
        for(; i<=Q->r; i++){
		if(type == INT){
	             printf("[%d] ",*(int*)Q->store[i]);
		}
		if(type == CHAR){
	             printf("[%c] ",*(char*)Q->store[i]);
		}
		if(type == STRING){
	             printf("[%s] ",(char*)Q->store[i]);
		}
		if(type == BTNODE){
		     btnode *node = (btnode*)Q->store[i];
	             printf("[%d|%p|%p] ",node->data, node->left, node->right);
		}
		if(type == LISTNODE){
		     listnode *node = (listnode*)Q->store[i];
	             printf("[%d|%p] ",node->data, node->next);
		}

        }
        printf("\n");
}

void testintdata(){
	queue *q = createqueue(QUEUELEN);
	int i;
	int data[]={1,2,3,4,5,6,7,8,9,10};
	for(i=0; i<INPUTLEN; i++){
		enqueue(&data[i], q);
		showqueue(q,INT);
	}
	for(i=0; i<INPUTLEN; i++){
		dequeue(q);
		showqueue(q,INT);
	}
	deletequeue(q);
}

void testchardata(){
	queue *q = createqueue(QUEUELEN);
	char i;
	char data[] ={'a','b','c','d','e','f','g','h','i','j'};
	for(i=0; i<=INPUTLEN; i++){
		enqueue(&data[i], q);
		showqueue(q, CHAR);
	}
	for(i=0; i<INPUTLEN; i++){
		dequeue(q);
		showqueue(q, CHAR);
	}
	deletequeue(q);
}

void teststringdata(){
	queue *q = createqueue(QUEUELEN);
	int i;
	char *data[] ={"Rohit","Kumar","Binay","Apurv","Abhi","Sanjog","Amresh","Kaushal","ravi","brahma"};
	for(i=0; i<INPUTLEN; i++){
		enqueue(data[i], q);
		showqueue(q,STRING);
	}
	for(i=0; i<INPUTLEN; i++){
		dequeue(q);
		showqueue(q,STRING);
	}
	deletequeue(q);

}

void testbtnodedata(){
	queue *q = createqueue(QUEUELEN);
	int i;
	for(i=0; i<INPUTLEN; i++){
		btnode *newnode = malloc(sizeof(btnode));
		newnode->data = i*10;
		newnode->left = NULL;
		newnode->right = NULL;

		enqueue(newnode, q);
		showqueue(q, BTNODE);
	}
	for(i=0; i<INPUTLEN; i++){
		dequeue(q);
		showqueue(q, BTNODE);
	}
	deletequeue(q);
}

void testlistnodedata(){
	queue *q = createqueue(QUEUELEN);
	int i;
	for(i=0; i<INPUTLEN; i++){
		listnode *newnode = malloc(sizeof(listnode));
		newnode->data = i*5;
		newnode->next = NULL;
		enqueue(newnode, q);
		showqueue(q, LISTNODE);
	}
	for(i=0; i<INPUTLEN; i++){
		dequeue(q);
		showqueue(q, LISTNODE);
	}
	deletequeue(q);
}

int main(){	
	testintdata();
	testchardata();
	teststringdata();
	testbtnodedata();
	testlistnodedata();
	return 0;
}
