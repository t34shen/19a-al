#include <stdio.h>
#define N 20
/*估计要改造一下快速排序了 
*毕竟查找中位数目前不知道有啥更好的方法
*难道要用线性时间的排序排完了然后找中位数 
*/
int findmiddle(int arr[]){
	//
}

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
	int oily[N];
	randomArray(oily);
	printarray(oily);
	int middle = findmiddle(oily);
	printf("The Y coordinate of oil pipe is %d\n", middle);
} 
