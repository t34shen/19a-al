#include <stdio.h>
#include <stdlib.h>
#define N 20
#define NN 399

/*先利用桶排序，每个kn ~ kn+k是一个桶 
*然后在桶内正用计数排序，
*如果是比较插入的话最差情况下恐怕不能做到 O(n) 
*/ 

/*realize queue
 *QUEUE + creatQueue + addQ + deleteQ
 */
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
	/*another way to sort
	*make compare everytime you add data in the queue
	*/
	if(q->size = 0){
		q->data[0] = item; 
	}
	for(int i = q->size; i > 0; i--){
		if(item < q->data[i]){
			q->data[i+1] = q->data[i];
		}else{
			q->data[i] = item;
		}
	}
	q->size++;
	q->rear++;
}
int deleteQ(queue* q){
	q->front++;
	q->size--;
	return q->data[q->front];
}

/*using countsort to sort every array in the queue
 *add some small trick so that it won't iterate everytime
 */
void countsort(queue* q){
	/*si is the size
	 *and give different way to sort according to the size 
	 */
	int si = q->size;
	if(si > 2){
		/*initial t as a transfer array*/
		int t[N];
		for(int i=0; i < N; i++){
		    t[i] = 0;
		}
		/*seperate data in 0 ~ n-1 value's array*/
		for(int j=0; j < si; j++){
		    t[q->data[j] % N]++;
		}
		/*get the final count of data*/
		for(int k=1; k < N; k++){
			t[k] = t[k] + t[k-1];
		}
		/*initial a final array s
		 *assign every data into s according t
		 */
		int s[q->size];
		for(int n = si; n > 0; n--){
			s[t[q->data[n] % N] - 1] = q->data[n];
			t[q->data[n] % N]--;
		}
		/*pass the value of s to p->data*/
		for(int i = 0; i < si; i++){
			q->data[i] = s[i];
		}
	/*if there's only two elements, check if it need exchage*/
	}else if(si == 2){
		if(q->data[0] > q->data[1]){
			int tem = q->data[1];
			q->data[1] = q->data[0];
			q->data[0] = tem;
		}
	}
}

/*sort of radix sort,but not purely radix sort
 *there's only one radix operate
 */
void radixsort(int arr[]){
	/*make a queue* array to give N queue to carry the data*/
	queue* q[N];
	for(int k=0; k < N; k++){
		q[k] = creatQueue();
	}
	/*add the data into different queue depends on value*/
	for(int i=0; i < N; i++){
		int tem = arr[i] / N;
		addQ(q[tem], arr[i]);
	}
//	/*sort every seperate queue*/
//	for(int i = 0; i< N; i++){
//		countsort(q[i]);
//	}
	/*init a new array as a middleman to transfer data*/
	int whole[N];
	int k = 0;
	for(int i=0; i < N; i++){
		for(int j = 0; j < q[i]->size; j++){
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
