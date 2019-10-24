#include <stdio.h>

int main(void)
{
    int x = 10;
    printf("times: %d\n", hanoi(x));
    return 0;
}

//loop version
int hanoi(x)
{
    int count = 0;
    for(int i = 0; i < x; i++)
    {
        count = 2 * count + 1;
    }
    return count;
}
