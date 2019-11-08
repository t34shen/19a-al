#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define times 1000000


/*�õ���orderΪ�ݴε�����*/
//�����ŷ�
void randomArray(char arr[], int t){
    srand((unsigned)time(0));
    for(int i = 0; i < times; i++){
        arr[i] = (rand() % 250);
        //printf("%d ", i);
    }
}
//˳���ŷ�
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
//�����ŷ�
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

//�ڲ�����merge
void merge(char a[], char b[], int low, int mid, int high){
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
    }
}
//recursion sort
void mergeSortRe(char a1[], char b1[], int low, int high){
    if(high - low > 0){
        //printf("�ֽ⣺ %d %d %d\n", low, (low+high)/2, high);

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
//    //�õ��ж��ٲ��mergesort
//    int hei = log2(length) + 1;
//
//    //����һ����ŷ���ؼ��ֵ�����
//    int nodecount = pow(2, hei + 1) - 1;
//    int node[nodecount];
//
//    //��ÿһ���ֵ��Ӧ�ؼ��ַŽ��������
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
//    //���ùؼ��ִӵײ㿪ʼ���ң�merge
//
//    //�õ���������
//
//}

int middle(int i, int j){
    return (i + j) / 2;
}

void mergeSort(char a[], char b[], int length){
    //�����ж��ٲ㣬�ǵ���һ������
    int hei = log2(length) + 1;
    //printf("����%d\n", hei);
    for(int i = 1; i < hei ; i++){
        printf("�ⶼ�� %d ���ˣ�\n", i);
        //����buf��buf * 2��Ϊ�ò�ÿ��sort����
        int buf = (int)pow(2, i);
        //printf("buf: %d\n", buf);
        for(int j = 0; j <= length / buf - 1; j++){
            //printf("%d %d %d\n", j * buf, middle(j * buf, (j+1) * buf - 1), (j+1) * buf - 1);
            merge(a, b, j * buf, middle(j * buf, (j+1) * buf - 1), (j+1) * buf - 1);
            //������ݵ���ĩβ����mergeʣ�����
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
