#include <stdio.h>
#define N 10

int *bubbleSort(int arr[])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = i + 1; (j > 0)&&(j < N); j--)
        {
            if(arr[j] < arr[j - 1])
            {
                int t = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = t;
            }
            else
            {
                break;
            }
        }
    }
    return arr;
}

int *straightSelectSort(int arr[])
{
    for(int i = 0; i < N; i++)
    {
        int smallest = i;
        for(int j = i + 1; j < N; j++)
        {
            if(arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }

        //printf("small: %d\n", arr[smallest]);
        int t = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = t;
    }

    //woc， 出bug居然是忘记return了。。。。
    return arr;
}

int *insertionSort(int arr[])
{
    for(int i = 1; i < N; i++)
    {
        int t = arr[i];
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[j] > t && j > 0)
            {
                arr[j + 1] = arr[j];
            }
            else if(arr[j] <= t)
            {
                arr[j + 1] = t;
                //开始的时候忘记break，这里不中止loop将造成bug，覆盖接下来的数据。
                break;
            }
            else if(arr[j] > t && j == 0)
            {
                arr[j + 1] = arr[j];
                arr[0] = t;
            }
        }
    }
    return arr;
}

int main(void)
{
    int arr[N] = {1, 43, 887, 3, 74, 11, -90, 323, 43, 0};
    int arr2[N] = {1, 43, 887, 3, 74, 11, -90, 323, 43, 0};
    int arr3[N] = {1, 43, 887, 3, 74, 11, -90, 323, 43, 0};

    int *a = bubbleSort(arr);
    for(int i = 0; i < N; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");

    int *b = straightSelectSort(arr2);
    for(int i = 0; i < N; i++)
    {
        printf("%d\t", b[i]);
    }
    printf("\n");

    int *c = insertionSort(arr3);
    for(int i = 0; i < N; i++)
    {
        printf("%d\t", c[i]);
    }
}
