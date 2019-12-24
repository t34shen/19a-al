#include <stdio.h>

/* global values */
int puzzlexy[5][2];

/* initiate the 8-puzzle
 * in a 3-3 array
 */
int puzzle[3][3] = {{0, 5, 4}, {3, 2, 8}, {7, 1, 4}};
int correct[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
int puzzleCopy[3][3];

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

/* print the spare one */
void print0(int p[][3]){
	find0(p);
	printf("the spare blank: row %d\tcolumn %d\n", 
			puzzlexy[0][0], puzzlexy[0][1]);
}

/* find the directions puzzle can go
 * give the possible directions in array dir
 * return the number of direction 
 */
int findDir(int p[][3], int dir[][3]){
	
	return 0;
}

/* return the number of the same blocks */
int correctness(int p[][3]){
	
	return 0;
}

/**/
void astar(int p[][3]){
	
	return;
}

int main(void){
	//some test
	printP(puzzle);
	printP(correct);
	print0(puzzle);
	print0(correct);
} 
