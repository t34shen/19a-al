#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define times 1000000


/*得到以order为幂次的数据*/
//乱序排法
void randomArray(char arr[], int t){
    srand((unsigned)time(0));
    for(int i = 0; i < times; i++){
        arr[i] = (rand() % 250);
        //printf("%d ", i);
    }
}
//顺序排法
void orderArray(char arr[], int t){
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
void reverseArray(char arr[], int t){
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
void merge(char a[], char b[], int low, int mid, int high){
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
    }
}
//recursion sort
void mergeSortRe(char a1[], char b1[], int low, int high){
    if(high - low > 0){
        //printf("分解： %d %d %d\n", low, (low+high)/2, high);

        mergeSortRe(a1, b1, low, (low+high)/2);
        mergeSortRe(a1, b1, (low+high)/2 + 1, high);

        merge(a1, b1, low, (low+high)/2, high);
    }
}

////loop-version
//int middle(int i, int j){
//    return (i + j) / 2;
//}
//
//void mergeSort(char a[], char b[], int length){
//    //得到有多少层的mergesort
//    int hei = log2(length) + 1;
//
//    //构造一个存放分组关键字的数组
//    int nodecount = pow(2, hei + 1) - 1;
//    int node[nodecount];
//
//    //将每一层的值对应关键字放进这个数组
//    int count = 0;
//    node[0] = middle(0, length - 1);
//    count += 1;
//    for(int i = 0; i < hei; i++){
//        for(int j = 0; j < (int)pow(2, i); j++){
//            if(j = 0){
//                node[(int)pow(2, i + 1) - 1 + j] =
//                middle(0, node[(int)pow(2, i) - 1]);
//            }else if(j = pow(2, i) - 1){
//                node[(int)pow(2, i + 1) - 1 + j] =
//                middle(node[(int)pow(2, i + 1) - 2], length);
//            }else if(j % 2 == 1){
//                node[(int)pow(2, i + 1) - 1 + j] =
//                middle(node[(int)pow(2, i) - 1 + j / 2], node[(int)pow(2, i - 1) - 1 + j / 4]);
//            }
//        }
//    }
//    for(int i = 0; i < nodecount; i++){
//        printf(node[i]);
//    }
//    //利用关键字从底层开始查找，merge
//
//    //得到结果，输出
//
//}

int middle(int i, int j){
    return (i + j) / 2;
}

void mergeSort(char a[], char b[], int length){
    //计算有多少层，记得有一共是有
    int hei = log2(length) + 1;
    //printf("层数%d\n", hei);
    for(int i = 1; i < hei ; i++){
        printf("这都第 %d 层了！\n", i);
        //计算buf，buf * 2即为该层每次sort的量
        int buf = (int)pow(2, i);
        //printf("buf: %d\n", buf);
        for(int j = 0; j <= length / buf - 1; j++){
            //printf("%d %d %d\n", j * buf, middle(j * buf, (j+1) * buf - 1), (j+1) * buf - 1);
            merge(a, b, j * buf, middle(j * buf, (j+1) * buf - 1), (j+1) * buf - 1);
            //如果传递到了末尾，则merge剩余的量
            if((length % buf > buf / 2) && (j == length / buf - 1)){
                merge(a, b, j * length / buf, (j+1/2) * length / buf, length - 1);
                //printf("%d %d %d\n", j * length / buf, (j+1/2) * length / buf, length - 1);
            }else if(i == hei - 1){
                merge(a, b , 0, length - (length % buf) - 1, length - 1);
                //printf("%d %d %d\n", 0, length - (length % buf) - 1, length - 1);
            }
        }
    }
}

//const int order = 6;
//const int times = pow(10, order);
//times = times * 2;
//printf("times: %d\n", times);
//int times = 100000000;
char arr[times];
char result[times];

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
