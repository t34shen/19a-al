#include <stdio.h>

int main(void)
{
    int x = 4;
    printf("we need %d times to move plates.\n", hanoi(x));
    return 0;
}

int hanoi(int x)
{
    if(x == 1)
    {
        return 1;
    }
    else
    {
        return(2 * hanoi(x - 1) + 1);
    }
}
