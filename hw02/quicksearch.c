#include <stdio.h>
#define N 100

int quick(int array[], int k, int low, int high){
    //use the lowest element as the base
    int base = low;
    int basevalue = array[low];
    printf("basevalue: %d\n", basevalue);
    int li = low + 1;
    int ri = high;
    while (li < ri){
    //玄学！玄学！之前在for（）里面又放了个li < ri,就一直segmentation fault！！！
    printf("base: %d", base);
        for(;ri >= base ; ri--){
            if(array[ri] < basevalue){
                array[base] = array[ri];
                base = ri;
                printf("%d there!", ri);
                break;
            }
        }
        for(;li <= base ; li++){
            if(array[li] > basevalue){
                array[base] = array[li];
                base = li;
                printf("%d here!\n", li);
                break;
            }
        }
    }
    array[base] = basevalue;
    for (int i = 0; i < N; i++){
        printf("%d\t", array[i]);
    }

    printf("base: %d round again\n", base);
    if (base == k-1){
        return basevalue;
    }else if (base > k-1){
        return quick(array, k, low, base);
    }else if (base < k-1){
        //最终反正也是k，因为k是与标号有关是跟全局的数组挂钩啊
        return quick(array, k, base + 1, high);
    }
}

int main(void){
    int arr[N];
    for (int i = 0; i < N; i++){
        arr[i] = N - i;
    }
    int k = 7;
    //printf("there!");
    int r = quick(arr, k, 0, N-1);
    printf("result: %d\n", r);
    return 0;
}
