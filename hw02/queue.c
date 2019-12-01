#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100

/*the first is link queue*/
/*initial the node of queue*/
typedef struct QNode{
	int data;
	struct QNode* next;
}QNode, *QueuePtr;

/*main struct of queue*/
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/*initialize a queue*/
void InitQueue(LinkQueue Q){
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

/*free a queue*/
void DestroyQueue(LinkQueue Q){
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

/*add an element to the queue*/
void EnQueue(LinkQueue Q, int e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

/*the next is a sequence queue*/
typedef struct{
	int* base;
	int front;
	int rear;
}SqQueue;

void InitSqQueue(SqQueue Q){
	Q.base = (int*)malloc(MAXQSIZE * sizeof(int));
	Q.front = Q.rear = 0;
}

void EnSqQueue(SqQueue Q, int e){
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}
