#include <stdio.h>
#define N 10

int main(void){
    //test
    /*give a reverse order array
    */
    int arr[N];
    for (int i = 0; i < N; i++){
        arr[i] = N - i;
    }
    int num = 1;
    int pin = binary(arr, num, 0, N-1);
    if(pin > -1){
        printf("the number %d is on the position of: %d", num, pin + 1);
    }else{
        printf("no fit number");
    }
    return 0;
}

int binaryReWithNoOrder(int array[], int num, int low, int high){
    int r;
    if(array[(low+high)/2] != num){
        if(high == low){;
            return -1;
        }else{
            int r1 = binaryReWithNoOrder(array, num, low, (low+high)/2);
            int r2 = binaryReWithNoOrder(array, num, (low+high)/2 + 1, high);
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

int binaryRe(int array[], int num, int low, int high){
    int r;
    if(array[(low+high)/2] == num){
        return (low+high)/2;
    }else if(array[(low+high)/2] < num && low != high){
        return binaryRe(array, num, low, (low+high)/2);
    }else if(array[(low+high)/2] > num && low != high){
        return binaryRe(array, num, (low+high)/2+1, high);
    }else{
        return -1;
    }
}

int binary(int array[], int num, int low, int high){
    while(array[(low+high)/2] != num){
        int v = array[(low+high)/2];
        if(high == low){
            return -1;
        }else if(v < num){
            high = (low+high)/2;
        }else if(v > num){
            low = (low+high)/2 + 1;
        }
    }
    return (low+high)/2;
}
