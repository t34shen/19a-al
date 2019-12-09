#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 26
#include "readwords.c"

/*define the sturct of huffman tree*/
typedef struct{
	double weight;
	int lchild;
	int rchild;
	int parent;
}HTNODE;

/*print HTNODE H[]*/
void printH(HTNODE H[], int length, int letter[]){
	int len = 2 * length - 1;
	for(int i = 0; i < len; i++){
		printf("%d %d %c  weight: %f  parent: %d\tlchild: %d\trchild: %d\n"
		, i, letter[i], letter[i], H[i].weight, H[i].parent, H[i].lchild, H[i].rchild);
	}
	printf("\n\n");
}

/*initiate the huffman tree*/
void initH(HTNODE H[], int length){
	int len = 2 * length - 1;
	for(int i = 0; i < len; i++){
		H[i].weight = 0;
		H[i].lchild = H[i].rchild = H[i].parent = -1;
	}
}

/* build the huffman tree */
void buildH(HTNODE H[], int length){
	int maxNode = length;
	
	for(int i = 0; i < length-1; i++){
		/*find the smallest two number*/
		double smallFirst = 100;
		int first = -1;
		double smallSecond = 100;
		int second = -1;
		for(int j = 0; j < maxNode; j++){
			if(H[j].parent == -1){
				/*inner compare lines*/
				if(H[j].weight < smallSecond){
					if(H[j].weight < smallFirst){
						smallFirst = H[j].weight;
						first = j;
						//printf("%d, %f\n", j, H[j].weight);
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
		H[maxNode].weight = smallSecond + smallFirst;
		H[maxNode].lchild = first;
		H[maxNode].rchild = second;
		H[first].parent = H[second].parent = maxNode;
		maxNode++;
	}
}

/*define the huffmanCode table*/
typedef struct{
	char ch;
	char bits[61+1];
}codeNode;

/*input: HuffmanTree output: Hufftable*/
void buildTable(HTNODE H[], codeNode T[], int length, int letter[]){
	for(int i = 0; i < length; i++){
		int track = i;
		T[i].ch = letter[i];
		char code[length + 1];
		int count = length;
		code[count] = '\0';
		int p;
		/*give the code in a reverse way*/
		while(H[track].parent != -1){
			count--;
			p = H[track].parent;
			if(H[p].lchild == track){
				code[count] = '0';
			}else{
				code[count] = '1';
			}
			track = p;
		}
/*OMG use the strcpy to copy the string right on the situation where loop ends*/
		strcpy(T[i].bits, &code[count]);
	}
}

/*print the huffman table*/
void printTable(codeNode T[], int length){
	for(int i = 0; i < length; i++){
		printf("%c:  %s\n", T[i].ch, T[i].bits);
	}
}
/*****************************************************
 main funtion:
 open file - distill data - build huffman tree - get huffman code
 - compress txt - calculate rates - decode&compare
 *****************************************************/
 
int main(void){
	/* get the data of the text
 	 * change the array of letter rates
 	 */
	FILE *file = NULL;
	file = fopen("test.txt", "r");
	double wordsRate[127];
	getTxtData(file, wordsRate);
	
	/* clear the data make sure every line is filled
	 * first get sum and make huffman tree
	 */
	int length = 0;
	for(int i = 0; i < 127; i++){
		if(wordsRate[i] != 0.0){
			length++;
		}
	}
	/* struct huffman tree
	 * word array records the chars appear in the text
	 * HuffmanT get the percentages stored in wordsRate according the sequence of count 
	 */
	int word[length];
	HTNODE HuffmanT[2 * length-1];
	initH(HuffmanT, length);
	int count = 0;
	double summary;/*only to test the correctness of distill*/
	for(int i = 0; i < 127; i++){
		if(wordsRate[i] != 0.000){
			summary += wordsRate[i];
			word[count] = i;
			HuffmanT[count].weight = wordsRate[i];
			count++;
		}
	}
	//printf("summary: %f\n", summary);
	//printH(HuffmanT, length, word); 
	/*then implement huffman algorithm get the huffman table*/
	buildH(HuffmanT, length);
	printH(HuffmanT, length, word); 
	
	/*get the huffman code table*/
	codeNode HuffTable[length];
	buildTable(HuffmanT, HuffTable, length, word);
	printTable(HuffTable, length);
}
