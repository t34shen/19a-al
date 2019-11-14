#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define times 20000000

/*�õ���orderΪ�ݴε�����*/
//�����ŷ�
void randomArray(int arr[], int t){
    srand((unsigned)time(0));
    for(int i = 0; i < times; i++){
        arr[i] = (rand() % 1000);
        //printf("%d ", i);
    }
}
//˳���ŷ�
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
//�����ŷ�
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

//�ڲ�����merge
void merge(int a[], int b[], int low, int mid, int high){
    //b��k����ʼ�Ŷ���
    int i = low;
    int k = low;
    int j = mid + 1;
    //printf("�ϲ���%d %d %d\n", i, j, k);
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
        //printf("�ֽ⣺ %d %d %d\n", low, (low+high)/2, high);

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
    //printf("����%d\n", hei);
    for(int i = 1; i < hei ; i++){
        //printf("�ⶼ�� %d ���ˣ�\n", hei - i);
        //����buf��buf * 2��Ϊ�ò�ÿ��sort����s
        int buf = (int)pow(2, i);
        //printf("buf: %d\n", buf);
        for(int j = 0; j < length / buf; j++){
            //printf("%d %d %d\n", j * buf, middle(j * buf, (j+1) * buf - 1), (j+1) * buf - 1);
            merge(a, b, j * buf, middle(j * buf, (j+1) * buf - 1), (j+1) * buf - 1);
            //������ݵ���ĩβ����mergeʣ��s����
            if(((length % buf) > (buf / 2)) && (j == length / buf - 1)){
                //printf("surprise!\n");
                merge(a, b, buf * (j + 1), (j + 1) * buf + buf / 2 - 1, length - 1);
                //printf("%d %d %d\n", j * length / buf, (j+1/2) * length / buf, length - 1);
            }
        }
        //������һ�鸴���ˣ�bug���ϡ�����
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
    //���й鲢����
//    start = clock();
//    mergeSortRe(arr, result, 0, times - 1);
////    for(int j = 0; j < times; j++){
////        printf("%d\t", result[j]);
////    }
//    finish = clock();
//    duration = (double)(finish - start) / CLOCKS_PER_SEC;
//    printf("\n %f seconds\n", duration);

	double run_time;
	LARGE_INTEGER time_start;	//��ʼʱ��
	LARGE_INTEGER time_over;	//����ʱ��
	double dqFreq;		//��ʱ��Ƶ��
	LARGE_INTEGER f;	//��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	//��ʱ��ʼ

	//mergeSortRe(arr, result, 0, times - 1);
	mergeSort(arr, result, times);

	QueryPerformanceCounter(&time_over);	//��ʱ����
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	//����1000000�ѵ�λ���뻯Ϊ΢�룬����Ϊ1000 000/��cpu��Ƶ��΢��
	printf("\nrun_time��%fus\n",run_time);

//    for(int j = 0; j < times; j++){
//        printf("%d\t", arr[j]);
//    }
}
