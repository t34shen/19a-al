#include <stdio.h>
#define N 20
/*����Ҫ����һ�¿��������� 
*�Ͼ�������λ��Ŀǰ��֪����ɶ���õķ���
*�ѵ�Ҫ������ʱ�������������Ȼ������λ�� 
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
