<br></br><br></br><br></br><br></br><br></br>
<center style="font-size:24px">哈尔滨工业大学计算机科学与技术学院 </center>
<center style="font-size:36px">作业报告 </center>
<br></br>
<center style="font-size:24px">课程名称：数据结构与算法</center>
<center style="font-size:24px">课程类型： 辅修</center>
<center style="font-size:24px">作业名称： 第二章与第三章作业</center>
<br></br>
<center style="font-size:24px">学号：1153470104</center>
<center style="font-size:24px">姓名：沈孙乐</center>
<div STYLE="page-break-after: always;"></div>

##### 1.设计二分查找的非递归算法，并分析其时间复杂性。
在最坏情况下, 将会查找到 low 值与 high 相等或者是相差 1 的情况。此时进行了 $log2(n)$ 次的递归，每次迭代所需要的计算设为 $C$。
因此时间复杂性为： $O(n) = Clog_2(n)=long_2(n)$
```c
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
```
##### 2.设计二路归并排序的迭代算法，并分析其时间和空间复杂性。
每次归并的时间为本次归并的时间加上分开两路的各自的时间相加, 所以二路归并排序的递归方程为：$T(1)=0; T(n)=2T(n/2)+cn$ 通过master公式可以知道二路归并的时间复杂性为：$T(n)=nT(1)+cnlog_2n=\theta(nlog_2n)$
```c
void merge(int a[], int b[], int low, int mid, int high){
    int i = low;
    int k = low;
    int j = mid + 1;
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
```
```c
    while(i <= mid){
        b[k] = a[i];
        k++;
        i++;
    }
    for(int i = low; i < high + 1; i++){
        a[i] = b[i];
    }
}

void mergeSortRe(int a1[], int b1[], int low, int high){
    if(high - low > 0){
        mergeSortRe(a1, b1, low, (low+high)/2);
        mergeSortRe(a1, b1, (low+high)/2 + 1, high);
        merge(a1, b1, low, (low+high)/2, high);
    }
}
```
##### 3.基于快速排序划分的思想，设计一个在$n$个元素的表$a[1:n]$中确定第$k（1≤k≤n）$小元素的算法，并分析其最好、最坏和平均时间复杂性。
利用快速排序一次迭代确定某个数在元素中是第几个的性质，设计排序方法。
最好的情况下经过一次迭代就知道位置在哪里，时间复杂度为$O(n)$
最差的情况下递归方程为$O(n) = O(n-1) + cn$, 最终得到时间复杂性为：$O(n^2)$
平均情况下时间复杂度与快速排序本身的时间复杂度相同，为：$O(log_2n)$
```c
int quick(int array[], int k, int low, int high){
    //use the lowest element as the base
    int base = low;
    int basevalue = array[low];
    int li = low + 1;
    int ri = high;
    while (li < ri){
        for(;ri >= base ; ri--){
            if(array[ri] < basevalue){
                array[base] = array[ri];
                base = ri;
                break;
            }
        }
        for(;li <= base ; li++){
            if(array[li] > basevalue){
                array[base] = array[li];
                base = li;
                break;
            }
        }
    }
```
```c 
    array[base] = basevalue;

    if (base == k-1){
        return basevalue;
    }else if (base > k-1){
        return quick(array, k, low, base);
    }else if (base < k-1){
        return quick(array, k, base + 1, high);
    }
}
```
##### 4.写出二叉查找树的查找算法，并分析其平均情况的复杂性。
二叉排序树的时间复杂性取决于二叉树生成的形态。最坏情况下：插入形成了一个单链表，此时查找效率为$O(n)$。当在最好情况下形成高度为$log_2n$的判别树，其中排序效率为$O(long_2n)$因为二叉查找树的平均高度为$O(log_2n)$,所以二叉查找树的平均时间复杂度为: $O(long_2n)$
```c
/*define a inner struct*/
typedef struct datatype{
	int key;
	int count;
}records;

/*define the structure*/
typedef struct celltype{
    records data;
    struct celltype *lchild, *rchild;
}BSTNode;

/*define node data type*/
typedef BSTNode *BST;

/*function to insert data*/
BST insertBST(records R, BST F){
    if(F == NULL){
		F = (BST)malloc(sizeof(BSTNode));
        F->data = R;
		F->lchild = NULL;
		F->rchild = NULL;
		return F;
    }else if(R.key < F->data.key){
	    F->lchild = insertBST(R, F->lchild);
	}else if(R.key >= F->data.key){
		F->rchild = insertBST(R, F->rchild);
	}
	return F;
}
```
```c 
/*function to create the tree*/
BST createBST(int inp[]){
    BST T = NULL;
    for(int i = 0; i < N; i++){
        records d;
    	d.key = inp[i];
    	d.count = i;
		T = insertBST(d, T);
	}
	return T;
}

/*define function*/
BSTNode *binarytreeRe(BST F, int k){
	BSTNode *p = F;

	if(p == NULL || k == p->data.key){
	    return p;
	}
	if(k < p->data.key){
	    return(binarytreeRe(p->lchild, k));
	}else{
	    return(binarytreeRe(p->rchild, k));
	}
}
```
##### 5.设计一个算法在$O(n)$时间内，对0 到$n^2-1$ 之间的$n$ 个整数进行排序
利用基数排序的原理，只是将十进制的技术排序设置为N进制的技术排序即可，先利用 % 取余运算将低位进行排序，然后用除法，进行分类进行高位的排序，每次的时间为$Cn$,则时间复杂度为: $O(2cn)=O(n)$
```c
#define N 20
#define NN 399

/*link queue*/
/*initial the node of queue*/
typedef struct QNode{
	int data;
	struct QNode* next;
}QNode, *QueuePtr;

/*main struct of queue*/
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}queue, *LinkQueue;
```
```c 
/*initialize a queue*/
void InitQueue(LinkQueue Q){
	Q->rear = (QueuePtr)malloc(sizeof(QNode));
	Q->front = Q->rear;
	Q->front->next = NULL;
}

/*free a queue*/
void DestroyQueue(LinkQueue Q){
	while(Q->rear){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}

/*add an element to the queue*/
void EnQueue(LinkQueue Q, int e){
	printf("here\n");
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

/*add elements depends on their sequence*/
void AddQueue(LinkQueue Q, int e){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = e;
	QueuePtr s = Q->front->next;
	if(s->data <= e && s != NULL){
		s = s->next;
	}else{
		s = p->next;
		s = p;
	}
}

void Concatenate(LinkQueue q1, LinkQueue q2){
	if(q2->front->next != NULL){
		q1->rear->next = q2->front->next;
		q1->rear = q2->rear;
	}
}

void PrintQueue(LinkQueue q, int arr[]){
	QueuePtr m = q->front->next;
	/*count the number of array elements*/
	int count = 0;
	while(m != q->rear && m != NULL){
		printf("%d\t", m->data);
		arr[count] = m->data;
		count++;
		m = m->next;
	}
	if(m == q->rear){
    	printf("%d\n", q->rear->data);
		arr[count] = m->data;
		count++;
	}
}

/*sort of radix sort,but not purely radix sort
 *there's only one radix operate
 *the second radix sort the sequence of 1n to nn
 */
void radixsort2(int arr[]){
	/*make a queue* array to give N queue to carry the data*/
	LinkQueue q[N];
	for(int k=0; k < N; k++){
		q[k] = (LinkQueue)malloc(sizeof(queue));
		InitQueue(q[k]);
	}
	/*add the data into different queue depends on value*/
	for(int i=0; i < N; i++){
		//printf("wow %d\n", i);
		int tem = arr[i] / N;
		EnQueue(q[tem], arr[i]);
	}
	for(int i = 0; i < N; i++){
		PrintQueue(q[i], arr);
	}
	/*to concatenate data in the queues*/
	for(int i = 1; i < N; i++){
		Concatenate(q[0], q[i]);
	}
	printf("the result: ");
	PrintQueue(q[0], arr);
}

/*the first radix sort the lower sequence*/
void radixsort1(int arr[]){
	/*make a queue* array to give N queue to carry the data*/
	LinkQueue q[N];
	for(int k=0; k < N; k++){
		q[k] = (LinkQueue)malloc(sizeof(queue));
		InitQueue(q[k]);
	}
	/*add the data into different queue depends on value*/
	for(int i=0; i < N; i++){
		//printf("wow %d\n", i);
		int tem = arr[i] % N;
		EnQueue(q[tem], arr[i]);
	}
	for(int i = 0; i < N; i++){
		PrintQueue(q[i], arr);
	}
	/*to concatenate data in the queues*/
	for(int i = 1; i < N; i++){
		Concatenate(q[0], q[i]);
	}
	printf("the result: ");
	PrintQueue(q[0], arr);
}

/*get random value array
 *as well as the function to print the array
 */ 
void randomArray(int arr[]){
    for(int i = 0; i < N; i++){
        arr[i] = rand() % 399;
    }
}

void printarray(int arr[]){
	printf("The array is:  ");
	for (int i = 0; i < N; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int main(void){
	/*initialize an array*/
	int array[N];
	randomArray(array);
	printarray(array);
	//sort
	radixsort1(array);
	radixsort2(array);
}
```

##### 6. 输油管道问题：
某石油公司计划建造一条由东向西的主输油管道。该管道要穿过一个有n 口油井的油田。从每口油井都要有一条输油管道沿南北向最短路经与主管道相连。如果给定n 口油井的地理位置，即它们的x 坐标（东西向）和y 坐标（南北向），应如何确定主管道的最优位置，使得各油井到主管道之间的输油管道的长度总和最小？设计一个线性时间算法计算各油井到主管道之间的输油管道最小长度总和。
显然，只需要将这n口油井的y坐标进行排序，如果$n$为偶数，则只要将油管y坐标放在两个最中间的油田之间，如果是奇数则，直接选取中间的油田。所以这个问题就变成了一个中位数的查找问题，即在线性时间内查找出y坐标集合的中位数。
所以可以选择用快速排序来完成这个问题：
```c
int findmiddle(int array[], int k, int low, int high){
    int base = low;
    int basevalue = array[low];
    int li = low + 1;
    int ri = high;
    //quicksearch loop
    while (li < ri){
        for(;ri >= base ; ri--){
            if(array[ri] < basevalue){
                array[base] = array[ri];
                base = ri;
                break;
            }
        }
        for(;li <= base ; li++){
            if(array[li] > basevalue){
                array[base] = array[li];
                base = li;
                break;
            }
        }
    }
    array[base] = basevalue;

    if (base == k){
        return basevalue;
    }else if (base > k){
        return findmiddle(array, k, low, base);
    }else if (base < k){
	    return findmiddle(array, k, base + 1, high); 
    }
}

void randomArray(int arr[]){
    for(int i = 0; i < N; i++){
        arr[i] = rand() % 100;
    }
}

void printarray(int arr[]){
	printf("The array is: ");
	for (int i = 0; i < N; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
```
```c 
int main(void){
	//test
	int oily[N];
	randomArray(oily);
	printarray(oily);
	int middle = findmiddle(oily, N/2, 0, N-1);
	printf("The Y coordinate of oil pipe is %d\n", middle);
} 
```
##### 7.利用分治方法设计如下算法并分析其时间复杂性。
（1） 大整数相乘
（2） $N*N$ 矩阵相乘
（3） 最近点对问题