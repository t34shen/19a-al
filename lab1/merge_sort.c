#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define times 20000000

/*得到以order为幂次的数据*/
//乱序排法
void randomArray(int arr[], int t){
    srand((unsigned)time(0));
    for(int i = 0; i < times; i++){
        arr[i] = (rand() % 1000);
        //printf("%d ", i);
    }
}
//顺序排法
void orderArray(int arr[], int t){
    arr[0] = -127;
    for(int i = 1; i < times; i++){
        if(arr[i-1] >= 124){
            arr[i] = 127;
        }else{
            arr[i] = arr[i - 1] + rand() % 2;
        }
    }
    return arr;
}
//逆序排法
void reverseArray(int arr[], int t){
    arr[0] = 127;
    for(int i = 1; i < times; i++){
        if(arr[i-1] <= -124){
            arr[i] = -127;
        }else{
            arr[i] = arr[i-1] - rand() % 2;
        }
    }
    return arr;
}

//内部函数merge
void merge(int a[], int b[], int low, int mid, int high){
    //b从k个开始放东西
    int i = low;
    int k = low;
    int j = mid + 1;
    //printf("合并：%d %d %d\n", i, j, k);
    while((i <= mid) && (j <= high)){
        if(a[i] < a[j]){
            b[k] = a[i];
            k++;
            i++;
        }else{
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while(j <= high){
        b[k] = a[j];
        k++;
        j++;
    }
    while(i <= mid){
        b[k] = a[i];
        k++;
        i++;
    }

    for(int i = low; i < high + 1; i++){
        a[i] = b[i];
//        printf("%d\t", a[i]);
    }
//    printf("\n\n");
//    for(int j = 0; j < times; j++){
//        printf("%d\t", a[j]);
//    }
//    printf("\n\n");
}
//recursion sort
void mergeSortRe(int a1[], int b1[], int low, int high){
    if(high - low > 0){
        //printf("分解： %d %d %d\n", low, (low+high)/2, high);

        mergeSortRe(a1, b1, low, (low+high)/2);
        mergeSortRe(a1, b1, (low+high)/2 + 1, high);

        merge(a1, b1, low, (low+high)/2, high);
    }
}

int middle(int i, int j){
    return (i + j) / 2;
}

void mergeSort(int a[], int b[], int length){
    int hei = log2(length) + 1;
    //printf("层数%d\n", hei);
    for(int i = 1; i < hei ; i++){
        //printf("这都第 %d 层了！\n", hei - i);
        //计算buf，buf * 2即为该层每次sort的量s
        int buf = (int)pow(2, i);
        //printf("buf: %d\n", buf);
        for(int j = 0; j < length / buf; j++){
            //printf("%d %d %d\n", j * buf, middle(j * buf, (j+1) * buf - 1), (j+1) * buf - 1);
            merge(a, b, j * buf, middle(j * buf, (j+1) * buf - 1), (j+1) * buf - 1);
            //如果传递到了末尾，则merge剩余s的量
            if(((length % buf) > (buf / 2)) && (j == length / buf - 1)){
                //printf("surprise!\n");
                merge(a, b, buf * (j + 1), (j + 1) * buf + buf / 2 - 1, length - 1);
                //printf("%d %d %d\n", j * length / buf, (j+1/2) * length / buf, length - 1);
            }
        }
        //靠，这一块复杂了，bug不断。。。
        if(i == hei - 1){
            merge(a, b , 0, buf-1, length - 1);
        }
    }
}

int arr[times];
int result[times];

int main(void){
    clock_t start, finish;
    double duration;

    //printf("get there");
    reverseArray(arr, times);
    //orderArray(arr, times);
    //reverseArray(arr, times);

//    for(int i = 0; i < times; i++){
//        printf("%d\t", arr[i]);
//    }
//    printf("\n\n");
    //进行归并排序
//    start = clock();
//    mergeSortRe(arr, result, 0, times - 1);
////    for(int j = 0; j < times; j++){
////        printf("%d\t", result[j]);
////    }
//    finish = clock();
//    duration = (double)(finish - start) / CLOCKS_PER_SEC;
//    printf("\n %f seconds\n", duration);

	double run_time;
	LARGE_INTEGER time_start;	//开始时间
	LARGE_INTEGER time_over;	//结束时间
	double dqFreq;		//计时器频率
	LARGE_INTEGER f;	//计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//计时开始

	//mergeSortRe(arr, result, 0, times - 1);
	mergeSort(arr, result, times);

	QueryPerformanceCounter(&time_over);	//计时结束
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	//乘以1000000把单位由秒化为微秒，精度为1000 000/（cpu主频）微秒
	printf("\nrun_time：%fus\n",run_time);

//    for(int j = 0; j < times; j++){
//        printf("%d\t", arr[j]);
//    }
}
