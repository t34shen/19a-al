#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 20

void initSeq(int arr[]){
	for(int i = 0; i < N; i++){
		arr[i] = rand() % 10;
	}
}

void printSeq(int arr[]){
	printf("sequence: ");
	for(int i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void printSub(int arr[]){
	printf("subsequence: ");
	for(int i = 0; i < N; i++){
		if(arr[i] < 0){
			return;
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void maxSub(int a[], int b[], int sub[]){
	/* compare textstr with cmpstr
	 * if there's any diffrent,
	 * 	 calculate how many bit is same,
	 *   store in the pattern array
	 *   loop-continue
	 * return max as well a tem array
	 */
	 
}

int main(void){
	/*initiate two sequence*/
	int arr1[N];
	int arr2[N];
	initSeq(arr1);
	initSeq(arr2);
	printSeq(arr1);
	printSeq(arr2);
	/*initiate subsequence*/
	int result[N];
	for(int i = 0; i < N; i++){
		result[i] = -1;
	}
	/*init pattern array*/
	int pattern[N];
	for(int i = 0; i < N; i++){
		pattern[i] = -1;
	}
}
