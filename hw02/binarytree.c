#include <stdio.h>

//define structure
typedef struct{
    int key;
}

typedef struct celltype{
    records data;
    struct celltype *lchild, *rchild;
}BSTNode;

//define node data type
typedef BSTNode *BST;

// define function
BSTNode *binarytreeRe(BST F, int k){

}

void insertBST(records R, BST F){
    if(F == NULL){
        F = new BSTNode;
    }
}

BST createBST(void){
    BST F = NULL;
    int key;

}

int main(void){
    //test
}
