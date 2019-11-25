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
```c
//define a inner struct
typedef struct datatype{
	int key;
	int count;
}records;

//define the structure
typedef struct celltype{
    records data;
    struct celltype *lchild, *rchild;
}BSTNode;

//define node data type
typedef BSTNode *BST;

//function to insert data
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

//function to create the tree
BST createBST(int inp[]){
    BST T = NULL;
    for(int i = 0; i < N; i++){
        records d;
    	//d = new records;
    	d.key = inp[i];
    	d.count = i;
		T = insertBST(d, T);
	}
	return T;
}

// define function
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
```c

```
##### 6. 输油管道问题：
某石油公司计划建造一条由东向西的主输油管道。该管道要穿过一个有n 口油井的油田。从每口油井都要有一条输油管道沿南北向最短路经与主管道相连。如果给定n 口油井的地理位置，即它们的x 坐标（东西向）和y 坐标（南北向），应如何确定主管道的最优位置，使得各油井到主管道之间的输油管道的长度总和最小？设计一个线性时间算法计算各油井到主管道之间的输油管道最小长度总和。
显然，只需要将这n口油井的y坐标进行排序，如果$n$为偶数，则只要将油管y坐标放在两个最中间的油田之间，如果是奇数则，直接选取中间的油田。所以这个问题就变成了一个中位数的查找问题，即在线性时间内查找出y坐标集合的中位数。
所以可以选择用快速排序来完成这个问题：
```c

```
##### 7.利用分治方法设计如下算法并分析其时间复杂性。
（1） 大整数相乘
（2） $N*N$ 矩阵相乘
（3） 最近点对问题