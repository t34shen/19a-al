#include <stdio.h>
#define N 20
/*����Ҫ����һ�¿��������� 
 *�Ͼ�������λ��Ŀǰ��֪����ɶ���õķ���
 *�ѵ�Ҫ������ʱ�������������Ȼ������λ�� 
 *Ȼ�췢�ֲ�û��ʲô�ø���ġ����� 
*/
int findmiddle(int array[], int k, int low, int high){
    //use the lowest element as the base
    int base = low;
    int basevalue = array[low];
    int li = low + 1;
    int ri = high;
    //quicksearch loop
    while (li < ri){
        for(;ri >= base ; ri--){
            if(array[ri] < basevalue){
                array[base] = array[ri];
                base = ri;
                break;
            }
        }
        for(;li <= base ; li++){
            if(array[li] > basevalue){
                array[base] = array[li];
                base = li;
                break;
            }
        }
    }
    array[base] = basevalue;
//    
//    for (int i = 0; i < N; i++){
//        printf("%d\t", array[i]);
//    }

    if (base == k){
        return basevalue;
    }else if (base > k){
        return findmiddle(array, k, low, base);
    }else if (base < k){
	    return findmiddle(array, k, base + 1, high); 
    }
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
	int middle = findmiddle(oily, N/2, 0, N-1);
	printf("The Y coordinate of oil pipe is %d\n", middle);
} 
