<br></br><br></br><br></br><br></br><br></br>
<center style="font-size:24px">哈尔滨工业大学计算机科学与技术学院 </center>
<center style="font-size:36px">作业报告 </center>
<br></br>
<center style="font-size:24px">课程名称：数据结构与算法</center>
<center style="font-size:24px">课程类型： 辅修</center>
<center style="font-size:24px">作业名称： 第一章与第二章作业</center>
<br></br>
<center style="font-size:24px">学号：1153470104</center>
<center style="font-size:24px">姓名：沈孙乐</center>
<div STYLE="page-break-after: always;"></div>

## 1.
写出欧几里得算法，证明其正确性并分析其时间复杂性。
设经过计算一共需要$n$步，则$T(n)=1+T(n-1)$所以有$T(n) = n - 1 + T(1) = O(n)$
```c
int euclidean(int x, int y)
{
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
	}
	return b;
}
```
## 2.
写出汉诺塔问题的算法，并分析其时间和空间复杂性。
可以得到递归方程：$T(n) = 2T(n-1)+1$,对这个递归方程求解得到$T(n)=2^{n-1}T(1)+2^{n-1}-1=2^n-1$所以时间复杂度为$T(n)=\theta(2^n)$
```c
char barName[3] = {'A','B','C'};


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
    printf("move a plate from %c to %c\n", barName[i], barName[j]);
}

int hanoi(int x, int i, int j)
{
    if(x == 1)
    {
        move(i, j);
        return 1;
    }
    else if(x > 1)
    {
        int z = hanoi(x - 1, i, rest(i, j));

        move(i, j);
        hanoi(x - 1, rest(i, j), j);
        return(2 * z + 1);
    }
}
```

## 4.
写出（直接）选择排序，证明其正确性，并分析其时间复杂性。
递归方程：$T(n)=T(n-1)+n$得到$T(n)=n(n+1)/2, T(n)=\theta(n^2)$
```c
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

        int t = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = t;
    }
```
## 5.
设计气泡排序、（直接）插入排序、（直接）选择排序的递归算法，并分析其时间和空间复杂性。
直接插入排序：$T(n)=T(n-1)+n$得到$T(n)=n(n+1)/2, T(n)=\theta(n^2)$
气泡排序：$T(n)<T(n-1)+2n,T(n)=n(n+1),T(n)=O(n^2)$
选择排序：$T(n)<T(n-1)+2n,T(n)=n(n+1),T(n)=O(n^2)$
```c
int * bubbleRe(int *arr, int bn)
{
    if(bn == 0){
        return arr;
    }else{
        int c = N - bn;
        for(int i = c; (i > 0) && (i < N); i--){
            if(arr[i] <= arr[i - 1]){
                int temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
            }
        }
        return bubbleRe(arr, bn - 1);
    }

}

int *insertionRe(int arr[], int i)
{
    if(i == N){
        return arr;
    }else{
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
                break;
            }
            else if(arr[j] > t && j == 0)
            {
                arr[j + 1] = arr[j];
                arr[0] = t;
            }
        }
        return insertionRe(arr, i + 1);
    }
}

int *straightRe(int arr[], int s)
{
    if(s == N){
        return arr;
    }else{
        int smallest = s;
        for(int j = s + 1; j < N; j++)
        {
            if(arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }

        int t = arr[s];
        arr[s] = arr[smallest];
        arr[smallest] = t;
        return straightRe(arr, s + 1);
    }
}
```
## 6.
证明以下结论：
##### (1)$ n! = \Omega(2^n)$
要证明上式成立，即证明：$\exist c>0,n_0，$对$\forall n>n_0,n! \geq c*2^n$,而
$$\frac{n!}{2^n}=\frac{1}{2}*\frac{2}{2}*\frac{3}{2}*...*\frac{n}{2}\geq\frac{1}{2}$$
所以当$c = 1/4$时，对$\forall n>1$成立。得证。
##### (2)$log_2{n}=o(\sqrt{n})$
要证明上式成立，即证明：$\forall c>0,\exist n_0，$对$\forall n>n_0, log_2{n}<c*\sqrt{n}.$所以问题变成了对$\forall c$求$\exist n_0$使得$n>n_0$时：$$f(x)=\frac{log_2n}{\sqrt{n}}<c$$。设始终有$n_0>1024$由于$$f'(n)=\frac{d}{dx}\frac{log_2n}{\sqrt{n}}=\frac{1}{n\sqrt{n}}(\frac{1}{ln2}-\frac{log_2n}{2})$$$$而在n>2时已经有f'(n)<0$$$$同时，\frac{log_2n}{\sqrt{n}}<\frac{1}{log_2n},所以此时只要使得\frac{1}{log_2{n_0}}=c即可$$所以分别进行讨论,$$当c<1/10时，取n_0 = 2^{\frac{1}{c}};$$$$而c>1/10时，直接取n_0=1024$$。得证。

#### (3)若平均情况的代价是$\theta(f(n))$,则最坏情况下的代价是$\Omega(f(n))$。
由平均情况得知$\exist c_1,c_2,n_0$，使得$\forall n>n_0,c_1f(n)\leq g(n)\leq c_2f(n)$。
即证在最坏情况下$\exist c',n'$,使得$g'(n)\geq cf'(n)$
因为$g'(n)>g(n), 所以有g'(n)\geq g(n)\geq c_1f(n)$,上式得证。

## 7.
设$T(n) = aT(n/b) + cn^k，T(1) =c$。其中$a\geq1，b>0，c>0，k$ 都是常数。证明：
$$T(n)=aT(n/b)+cn^k$$$$T(n/b)=aT(n/b^2)+c(n/b)^k$$$$...$$$$T(n/b^{m-1})=aT(n/b^m)+c(n/b^{m-1})^k$$所以归并之后得到：$$T(n)=a^mT(1)+n^k\sum_0^{m-1}a/b^k$$最后得到：$$ T(n)=n^{log_ba}+\frac{(a/b^k)^{log_bn}-1}{a/b^k-1}n^k$$
#####(1)若$a>b^k$,则$T(n)=\theta(n^{log_ba})$
在这种情况下，前一项比后一项要高阶，所以$T(n)=\theta(n^{log_ba})$
#####(2)若$a=b^k$,则$T(n)=\theta(n^klogn)$
这种情况下两项式子的阶数相同，所以：$$T(n)=(m+1)n^k=log_bn*n^k=\theta(n^klogn)$$
#####(3)若$a<b^k$,则$T(n)=\theta(n^k)$
这种情况下后一项比前一项要高阶，因此$T(n)=\theta(n^k)$
## 8.
#####(1)$T(n)=2T(n/2)+\sqrt{n},T(1)=c$
根据$master$定理，因为$n^{log_ab}=n^{log_22}=n>\sqrt{n}$所以可得$T(n)=\theta(n)$
#####(2)$T(n)=2T(n/2)+n,T(1)=c$
同理：因为$n^{log_ab}=n^{log_22}=n$,所以：$T(n)=\theta(nlogn)$
#####(3)$T(n)=2T(n/2)+5n^2,T(1)=c$
因为$n^{log_ab}=n^{log_22}=n<5n^2$,所以：$T(n)=\theta(n^2)$
#####(4)$T(n)=2T(n/2)+1,T(1)=1$
因为$n^{log_ab}=n^{log_22}=n>1$所以可得$T(n)=\theta(n)$
#####(5)$T(n)=3T(n/2),T(1)=1$
根据$master$定理，可得$T(n)=\theta(n^{log_23})$
#####(6)$T(n)=3T(n/6+10)+logn,当n\leq20时，T(n)=O(1)$
以$n=m+12$：得到：$$T(m+12)=3T(m/6+12)+log(m+12)$$
以$S(m)=T(m+12)$：$$S(m)=3S(m/6)+log(m+12)$$
由$master$定理,对于充分大的$m$, 存在$m^{log_63}>\sqrt m>log(m+12)$
所以得到答案：$T(n)=n^{log_63}$
#####(7)$T(n)=1.44T(\lceil n/1.2\rceil)+n,当n\leq5时,T(n)=O(1)$
求出函数的上下界，就可以求出递归方程的界。先有等式：$$T(n)=1.44(\lceil n/1.2\rceil)+n>S(n)=1.44(S(n/1.2)+n$$而由master定理：$S(n)=n^2$所以$T(n)=\Omega(n^2)$
另一方面由于当：$n\leq5时,T(n)=O(1)$：所以$$T(n)=1.44(\lceil n/1.2\rceil)+n<U(n)=1.44(U(n/1.2+1)+n$$利用第6题的解法，$$U(n+6)=1.44U(n/1.2+6)+n+6$$最后得到：$T(n)=O(n^2)$综上可得：$T(n)=\theta(n^2)$
#####(8)$用迭代法解方程:T(n)=5T(n/3)+n^2,T(1)=1$
通过迭代得到：$$T(n)=n^{log_35}+\frac{(5/3)^{log_3n}-1}{2/3}n^2$$由于后一项比前一项阶数更高，所以得到答案：$T(n)=\theta(n^2)$
