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

void PrintQueue(LinkQueue q){
	QueuePtr m = q->front->next;
	while(m != q->rear && m  != NULL){
		printf("%d\t", m->data);
		m = m->next;
	}
	if(m == q->rear){
    	printf("%d\n", q->rear->data);	
	}
}

/*sort of radix sort,but not purely radix sort
 *there's only one radix operate
 */
void radixsort(int arr[]){
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
		PrintQueue(q[i]);
	}
	/*to concatenate data in the queues*/
	for(int i = 1; i < N; i++){
		Concatenate(q[0], q[i]);
	}
	printf("the result: ");
	PrintQueue(q[0]);
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
	radixsort(array);
	//printarray(array);
}

////////////////////////////////////////////other code

/*using countsort to sort every array in the queue
 *add some small trick so that it won't iterate everytime
 */
//void countsort(queue* q){
//	/*si is the size
//	 *and give different way to sort according to the size 
//	 */
//	int si = q->size;
//	if(si > 2){
//		/*initial t as a transfer array*/
//		int t[N];
//		for(int i=0; i < N; i++){
//		    t[i] = 0;
//		}
//		/*seperate data in 0 ~ n-1 value's array*/
//		for(int j=0; j < si; j++){
//		    t[q->data[j] % N]++;
//		}
//		/*get the final count of data*/
//		for(int k=1; k < N; k++){
//			t[k] = t[k] + t[k-1];
//		}
//		/*initial a final array s
//		 *assign every data into s according t
//		 */
//		int s[q->size];
//		for(int n = si; n > 0; n--){
//			s[t[q->data[n] % N] - 1] = q->data[n];
//			t[q->data[n] % N]--;
//		}
//		/*pass the value of s to p->data*/
//		for(int i = 0; i < si; i++){
//			q->data[i] = s[i];
//		}
//	/*if there's only two elements, check if it need exchage*/
//	}else if(si == 2){
//		if(q->data[0] > q->data[1]){
//			int tem = q->data[1];
//			q->data[1] = q->data[0];
//			q->data[0] = tem;
//		}
//	}
//}
