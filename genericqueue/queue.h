#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct _queue{
        int f;
        int r;
        int maxlen;
	int datalen;
        void **store;
}queue;

queue* createqueue(int qsize);
int enqueue(void *data, queue *Q);
void* dequeue(queue *Q);
int isqueueempty(queue *Q);
void deletequeue(queue *Q);

#endif

