#include <stdio.h>
#include <stdlib.h>
#define N 20
#define NN 399

/*先利用桶排序，每个kn ~ kn+k是一个桶 
*然后在桶内正用计数排序，
*如果是比较插入的话最差情况下恐怕不能做到 O(n) 
*/ 

//realize queue
typedef struct QUEUE{
	int data[N];
	int front;
	int rear;
	int size;
}queue;

queue* creatQueue(){
	queue* q = (queue*)malloc(sizeof(queue));
	q->front = -1;
	q->rear = -1;
	q->size = 0;
	return q;
}
void addQ(queue* q, int item){
	q->rear++;
	q->size++;
	q->data[q->rear] = item;
}
int deleteQ(queue* q){
	q->front++;
	q->size--;
	return q->data[q->front];
}

void countsort(queue* q){
	int si = q->size;
	if(si > 1){
		int t[N];
		for(int i=0; i < N; i++){
		    t[i] = 0;
		}
		for(int j=0; j < si; j++){
		    t[q->data[j] % N]++;
		}
		for(int k=1; k < N; k++){
			t[k] = t[k] + t[k-1];
		}
		int s[q->size];
		for(int n = si; n > 0; n--){
			s[t[q->data[n] % N] - 1] = q->data[n];
			t[q->data[n] % N]--;
		}
		for(int i = 0; i < si; i++){
			q->data[i] = s[i];
		}
	}else if(si == 1){
		if(q->data[0] > q->data[1]){
			int tem = q->data[1];
			q->data[1] = q->data[0];
			q->data[0] = tem;
		}
	}
}

//sort function
void radixsort(int arr[]){
	queue* q[N];
	for(int k=0; k < N; k++){
		q[k] = creatQueue();
	}
	for(int i=0; i < N; i++){
		int tem = arr[i] / N;
		addQ(q[tem], arr[i]);
	}
	for(int i = 0; i< N; i++){
		countsort(q[i]);
	}
	int whole[N];
	int k = 0;
	for(int i=0; i < N; i++){
		for(int j = 0; i < q[i]->size; j++){s
		    whole[k] = q[i]->data[j];
			k++; 
		} 
	}
	for(int i = 0; i < N; i++){
	    arr[i] = whole[i]; 
	} 
}

//get random value array
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
	//test
	int array[N];
	randomArray(array);
	printarray(array);
	//sort
	radixsort(array);
	printarray(array);
}
