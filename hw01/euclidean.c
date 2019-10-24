#include <stdio.h>

/*
to realize the Euclidean Algorihthm
*/
int main(void)
{
    //test
	int x = 75;
	int y = 50;
	printf("The greatest common divisor of %d and %d is: %d\n", x, y, euclidean(x, y));
}

int euclidean(int x, int y)
{
    //find the bigger one of x,y
    int a, b;
	if (x > y)
    {
		a = x;
		b = y;
    }
	else if(x < y)
    {
		a = y;
		b = x;
	}
	else
    {
	    return x;
	}
	//euclidean
	while (a % b != 0)
	{
		int c = a % b;
		a = b;
		b = c;
		//printf("a: %d, b: %d\n", a, b);
	}
	return b;
}
