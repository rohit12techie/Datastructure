#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/*
 * This is generic queue implementation of queue. 
 * createqueue is funtion to create the queue of user given size and return pointer of queue 
 * 
 * */

queue* createqueue(int qsize){
        queue *Q = malloc(sizeof(queue));
	
        Q->f = -1;
        Q->r = -1;
        Q->maxlen = qsize;
        Q->store = malloc(sizeof(void**)*qsize);
       
        return Q;
}

/*
 * deletequeue is function to delete the queue and free all the allocated memory. 
 * 
 * */

void deletequeue(queue *Q){
	free(Q->store);
	free(Q);
	Q=NULL;	
}

/*
 * enqueue function does the enqueue operation in the qeueue. 
 * 
 * */

int enqueue(void *data, queue *Q){
        if(Q->r == (Q->maxlen-1)){
                printf("\nQueue is full\n");
                return -1;
        }

	Q->store[++(Q->r)] = data;;
        return 0;
}

/*
 * dequeue fucntion does the pop operation in queue and return the value it's going to pop.
 * 
 * */

void* dequeue(queue *Q){
        if(Q->r == -1 || Q->f == Q->r){
                printf("\nQueue is empty\n");
		Q->f = -1;
		Q->r = -1;
                return NULL;
        }
	return Q->store[++(Q->f)];
}

/*
 * isqueueempty fucntion checks whether queue is empty of not.
 * if queue is empty it returns 1 else 0 
 * 
 * */
int isqueueempty(queue *Q){
	if(Q->r == -1 || Q->r == Q->f){
		return 1;
	}
	return 0;
}

