#include <stdio.h>
#define N 20
#define NN 399

/*������Ͱ����ÿ��kn ~ kn+k��һ��Ͱ 
*Ȼ����Ͱ�����ü�������
*����ǱȽϲ���Ļ��������¿��²������� O(n) 
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
