#include <stdio.h>
#define N 30

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
    //printf("get insert!!!\n");
    if(F == NULL){
    	/*此处大坑！！c语言内本身没有new， 
        *又难以找到对于一个指针类型的struct的初始化方法
		*/ 
		F = (BST)malloc(sizeof(BSTNode));
        F->data = R;
        //printf("get 1!!!\n");
		F->lchild = NULL;
		//printf("get 2!!!\n");
		F->rchild = NULL;
		//printf("get 3!!!\n");
		/*我的我的天哪！！ 
		*涉及到指针是否指向同一个啥的这种问题，
		*直接用返回值的方式，就可以瞬间解决！！！
		*强制进行一个过程，省略掉所有烦人的指针操作 
		*毕竟c还是太诡异了 
		*/
		return F;
    }else if(R.key < F->data.key){
    	/*靠。。用返回值赋值我tm也没想到
		*能力不够啊，水平不够 
    	*/
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
    	//printf("records:%d, %d\n", d.key, d.count);
		T = insertBST(d, T);
		//printf("!tree:%d, %d\n", T->data.key, T->data.count);
	}
	return T;
}

// define function
BSTNode *binarytreeRe(BST F, int k){
    printf("\n\nget sort!!!\n");
	BSTNode *p = F;

	if(p == NULL || k == p->data.key){
        printf("get 1!!!\n");
	    return p;
	}
	if(k < p->data.key){
        printf("get 2!!!\n");
	    return(binarytreeRe(p->lchild, k));
	}else{
        printf("get 3!!!\n");
	    return(binarytreeRe(p->rchild, k));
	}
}

//random array
void randomArray(int arr[]){
    for(int i = 0; i < N; i++){
        arr[i] = rand() % 100;
    }
}

int main(void){
    //test
	int arr[N];
	randomArray(arr);
	for(int i = 0; i < N; i++){
        printf("%d\t", arr[i]);
	}
    printf("\n");
    BST tree;
	tree = createBST(arr);
    //printf("\n get here");
    //printf("\ntree's first: %d\n", tree->data.key);
    //give a number to search
    int x = 76;
    BSTNode *result = binarytreeRe(tree, x);
    if(result == NULL){
    	printf("\nThere is no number%d", x);
	}else{
        printf("\nnumber x is on the %d position!\n", result->data.count);
	}
}
