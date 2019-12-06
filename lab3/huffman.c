#include <stdio.h>
#include <math.h>
#define N 26

/* get the data of the text
 * change the array of letter rates
 */
double letterRate[N];
void getRateOfText(File){
	
}

/*define the sturct of huffman tree*/
typedef struct{
	double weight;
	int lchild;
	int rchild;
	int parent;
}HTNODE;

/*define the huffman array*/
typedef HTNODE HuffmanT[2N-1];

/*initiate the huffman tree*/
void initH(HTNODE H[]){
	for(int i = 0; i < 2N-1; i++){
		H[i].weight = 0;
		H[i].lchild = H[i].rchild = H[i].parent = 0;
	}
}

/* build the tree
 */
void buildH(HTNODE H[]){
	int maxNode = N;
	
	for(int i = 0; i < N-1; i++){
		/*find the smallest two number*/
		double smallFirst = 30;
		int first = -1;
		double smallSecond = 30;
		int second = -1;
		for(int j = 0; j < maxNode; j++){
			if(H[j].parent == -1){
				/*inner compare lines*/
				if(H[j].weight < smallSecond){
					if(H[j].weight < smallFirst){
						smallFirst = H[j].weight;
						first = j;
						break;
					}else{
						smallSecond = H[j].weight;
						second = j;
					}
				}
			} 
		}
		/* change two smallest's parents
		 * add a new node
		 * give parent's l&r child
		 */
	} 
} 

int main(void){
	//test
	getRateOfText(argv/*to do*/);
	HuffmanT Huf;
	initH(Huf);
	
} 
