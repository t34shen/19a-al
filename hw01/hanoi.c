#include <stdio.h>

char barName[3] = {'A','B','C'};

//get the rest
int rest(int i, int j)
{
    int k;
    if((i != 0)&&(j != 0))
    {
        k = 0;
    }
    else if((i != 1)&&(j != 1))
    {
        k = 1;
    }
    else
    {
        k = 2;
    }
    return k;
}

void move(int i, int j)
{
    //血的教训，调试了半天居然是因为打印字符串用了%s而不是%c而出现诡异的bug
    printf("move a plate from %c to %c\n", barName[i], barName[j]);
}

int hanoi(int x, int i, int j)
{
    if(x == 1)
    {
        //printf("x:%d\n", x);
        move(i, j);
        return 1;
    }
    else if(x > 1)
    {
        //printf("x:%d\n", x);
        int z = hanoi(x - 1, i, rest(i, j));

        move(i, j);
        //printf("biggest is at%d\n", rest(i, irr(x, i, j)));
        hanoi(x - 1, rest(i, j), j);
        return(2 * z + 1);
    }
}

int main(void)
{
    //test
    int x = 4;
    printf("\nwe need %d times to move plates.\n", hanoi(x, 0, 2));
}
