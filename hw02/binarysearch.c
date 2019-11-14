#include <stdio.h>
#define N 10

int main(void){
    //test
    int arr[N];
    for (int i = 0; i < N; i++){
        arr[i] = N - i;
    }
    int num = 0;
    int pin = binaryRe(arr, num, 0, N-1);
    if(pin > -1){
        printf("the number %d is on the position of: %d", num, pin + 1);
    }else{
        printf("no fit number");
    }
    return 0;
}

int binaryRe(int array[], int num, int low, int high){
    int r;
    if(array[(low+high)/2] != num){
        if(high == low){;
            return -1;
        }else{
            int r1 = binaryRe(array, num, low, (low+high)/2);
            int r2 = binaryRe(array, num, (low+high)/2 + 1, high);
            if(r1 < r2){
                return r2;
            }else if(r2 < r1){
                return r1;
            }else{
                return -1;
            }
        }
    }else{
        return (low+high)/2;
    }
}

int binary(int array[], int num){

    return 0;
}
