#include <stdio.h>
#include <stdlib.h>
#define N 20
#define NN 399

/*先利用桶排序，每个kn ~ kn+k是一个桶 
*然后在桶内正用计数排序，
*如果是比较插入的话最差情况下恐怕不能做到 O(n) 
*/ 

/*link queue*/
/*initial the node of queue*/
typedef struct QNode{
	int data;
	struct QNode* next;
}QNode, *QueuePtr;

/*main struct of queue*/
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}queue, *LinkQueue;

/*initialize a queue*/
/*首先认识到了一点就是结构体不能用来传参，
 *因为结构体传参时会读入整个而不是一个指针，
 *但是nmba为什么数组就是指针，真的qunimd
 */
void InitQueue(LinkQueue Q){
	Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->front = Q->rear;
	Q->front->next = NULL;
}

/*free a queue*/
void DestroyQueue(LinkQueue Q){
	while(Q->rear){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}

/*add an element to the queue*/
void EnQueue(LinkQueue Q, int e){
	printf("here\n");
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

/*add elements depends on their sequence*/
void AddQueue(LinkQueue Q, int e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	QueuePtr s = Q->front->next;
	if(s->data <= e && s != NULL){
		s = s->next;
	}else{
		s = p->next;
		s = p;
	}
}

void Concatenate(LinkQueue q1, LinkQueue q2){
	if(q2->front->next != NULL){
		q1->rear->next = q2->front->next;
		q1->rear = q2->rear;
	}
}

void PrintQueue(LinkQueue q, int arr[]){
	QueuePtr m = q->front->next;
	/*count the number of array elements*/
	int count = 0;
	while(m != q->rear && m != NULL){
		printf("%d\t", m->data);
		arr[count] = m->data;
		count++;
		m = m->next;
	}
	if(m == q->rear){
    	printf("%d\n", q->rear->data);
		arr[count] = m->data;
		count++;
	}
}

/*sort of radix sort,but not purely radix sort
 *there's only one radix operate
 *the second radix sort the sequence of 1n to nn
 */
void radixsort2(int arr[]){
	/*make a queue* array to give N queue to carry the data*/
	LinkQueue q[N];
	for(int k=0; k < N; k++){
		/*另外一点血的教训就是tmd分配之后的指针必然会变成一个新的，
		 *所以下面这条语句一定要放在外面，就是数组后面
		 */ 
		q[k] = (LinkQueue)malloc(sizeof(queue));
		InitQueue(q[k]);
	}
	/*add the data into different queue depends on value*/
	for(int i=0; i < N; i++){
		//printf("wow %d\n", i);
		int tem = arr[i] / N;
		EnQueue(q[tem], arr[i]);
	}
	for(int i = 0; i < N; i++){
		PrintQueue(q[i], arr);
	}
	/*to concatenate data in the queues*/
	for(int i = 1; i < N; i++){
		Concatenate(q[0], q[i]);
	}
	printf("the result: ");
	PrintQueue(q[0], arr);
}

/*the first radix sort the lower sequence*/
void radixsort1(int arr[]){
	/*make a queue* array to give N queue to carry the data*/
	LinkQueue q[N];
	for(int k=0; k < N; k++){
		q[k] = (LinkQueue)malloc(sizeof(queue));
		InitQueue(q[k]);
	}
	/*add the data into different queue depends on value*/
	for(int i=0; i < N; i++){
		//printf("wow %d\n", i);
		int tem = arr[i] % N;
		EnQueue(q[tem], arr[i]);
	}
	for(int i = 0; i < N; i++){
		PrintQueue(q[i], arr);
	}
	/*to concatenate data in the queues*/
	for(int i = 1; i < N; i++){
		Concatenate(q[0], q[i]);
	}
	printf("the result: ");
	PrintQueue(q[0], arr);
}

/*get random value array
 *as well as the function to print the array
 */ 
void randomArray(int arr[]){
    for(int i = 0; i < N; i++){
        arr[i] = rand() % 399;
    }
}

void printarray(int arr[]){
	printf("The array is:  ");
	for (int i = 0; i < N; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int main(void){
	/*initialize an array*/
	int array[N];
	randomArray(array);
	printarray(array);
	//sort
	radixsort1(array);
	radixsort2(array);
	//printarray(array);
}


