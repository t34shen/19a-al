#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* store puzzle as node:
 * puzzle in int array + correctness + next node
 */
typedef struct PUZZLE{
	int array[9];
	int correctValue;
	struct PUZZLE *next;
}puzzleNode;

typedef puzzleNode *pNode; 

/* print the puzzle */
void printP(int p[][3]){
	printf("puzzle: \n");
	int i, j;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			printf("%d\t", p[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/* find the zero, and store the position into direction */
void find0(int p[][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(p[i][j] == 0){
				puzzlexy[0][0] = i;
				puzzlexy[0][1] = j;
			}
		}
	}
}

/* change puzzle according to the step x,y*/
void step(int p[][3], int x, int y){
	int xp = puzzlexy[0][0];
	int yp = puzzlexy[0][1];
	p[xp][yp] = p[x][y];
	p[x][y] = 0;
}

/* print the spare one */
void print0(int p[][3]){
	find0(p);
	printf("the spare blank: row %d\tcolumn %d\n", 
			puzzlexy[0][0], puzzlexy[0][1]);
}

/* copy puzzle from p to copy*/
void pCopy(int p[][3], int copy[][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			copy[i][j] = p[i][j];
		}
	}
}

/* find the directions puzzle can go, give the possible directions
 * return the number of direction
 * # warning # this function must be implement after 'find0'
 */
int findDir(int p[][3]){
	/* possible steps number */
	int count;
	/* get the coodinate of spare blank*/
	int x = puzzlexy[0][0];
	int y = puzzlexy[0][1];
	/*calculate the possible step*/
	if(x == 1){
		if(y == 1){
			count = 4;
			puzzlexy[1][0] = 1; puzzlexy[1][1] = 0;
			puzzlexy[2][0] = 1; puzzlexy[2][1] = 2;
			puzzlexy[3][0] = 0; puzzlexy[3][1] = 1;
			puzzlexy[4][0] = 2; puzzlexy[4][1] = 1;
		}else{
			count = 3;
			puzzlexy[1][0] = 1; puzzlexy[1][1] = 1;
			puzzlexy[2][0] = 0; puzzlexy[2][1] = y;
			puzzlexy[3][0] = 2; puzzlexy[3][1] = y;
		}
	}else{
		if(y == 1){
			count = 3;
			puzzlexy[1][0] = 1; puzzlexy[1][1] = 1;
			puzzlexy[2][0] = x; puzzlexy[2][1] = 0;
			puzzlexy[3][0] = x; puzzlexy[3][1] = 2;
		}else{
			count = 2;
			puzzlexy[1][0] = x; puzzlexy[1][1] = 1;
			puzzlexy[2][0] = 1; puzzlexy[2][1] = y;
		}
	}
	return count;
}

/* return the number of the same blocks */
int correctness(int p[][3]){
	int correct = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			//once i forgot to put 3* before i
			int n = p[i][j];
			int x = n / 3;
			int y = n % 3;
			correct += abs(x-i + y-j);
		}
	}
	return correct;
}


/* struct the prior queue */
typedef struct{
	puzzleNode head;
}priorQueue;

typedef priorQueue *priorQ;

/* add a new puzzle into the prior queue
 * change the sequence according to the correctValue of new node
 */
void addP(priorQ queue, pNode p){
	return;
}

/* always delete the very first node of queue */
void deleteQ(priorQ queue){
	return;
}

/* initiate the 8-puzzle
 * in a 3-3 array
 */
int puzzle[3][3] = {{6, 1, 0}, {3, 2, 5}, {7, 8, 4}};
int correct[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
int puzzleCopy[3][3];

/*  */
void astar(int p[][3]){
	int x, y;
	while(correctness(p) != 0){
		find0(p);
		int num = findDir(p);
		/* find the best way to go, with puzzleCopy*/
		int bestway = -1;
		int best = correctness(p);
		int temp;
		for(int i = 1; i < 1+num; i++){
			pCopy(p, puzzleCopy);
			step(puzzleCopy, puzzlexy[i][0], puzzlexy[i][1]);
			temp = correctness(puzzleCopy);
			if(temp < best){
				best = temp;
				bestway = i;
			}
		}
		if(bestway == -1){
			bestway = 1 + rand() % num;
		}
		printf("best: %d\n", best);
		/* give the best way to puzzle*/
		x = puzzlexy[bestway][0];
		y = puzzlexy[bestway][1];
		step(p, x, y);
		
		printP(p);
	}
}

int main(void){
	//some test
//	printP(puzzle);
//	printP(correct);
//	print0(puzzle);
//	print0(correct);
	astar(puzzle);
}

