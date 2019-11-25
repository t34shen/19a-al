#include <stdio.h>
#define N 20
#define NN 399

/*先利用桶排序，每个kn ~ kn+k是一个桶 
*然后在桶内正用计数排序，
*如果是比较插入的话最差情况下恐怕不能做到 O(n) 
*/ 
//sort function
void radixsort(int arr[]){
	
}

//get random value array
void randomArray(int arr[]){
    for(int i = 0; i < N; i++){
        arr[i] = rand() % 100;
    }
}

void printarray(int arr[]){
	printf("The array is: ");
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
