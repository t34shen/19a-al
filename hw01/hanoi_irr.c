#include <stdio.h>
#define MAXPLATE 100

/* two main data struct in the pr */
/* record every bar's every plate number */
typedef struct BAR{
	int plate[MAXPLATE];
	int length;
}bar;

/* count the nearest 3 steps' 123 usage */
typedef struct PREV_PROC{
	int count1;
	int count2;
	int count3;
	int last;
}prev_proc;

void printBar(bar b1, bar b2, bar b3){
	//
	return;
}

int useTwice(prev_proc prev){
	//
	return;
}

int bigPlate(bar b1, bar b2){
	//
	return; 
}

int addPlate(int p, bar b){
	//
	return;
}

int delPlate(int p, bar b){
	//
	return;
}

/* main method:
 * according to different length, set the start process
 * move plates according to three rules, bar to bar
 *    1. among three operation, every bar must appear twice
 * 	  2. destination can't be the a new start, which would be one of the ending condition
 *    3. the small one can't be placed over a bigger one
 * then a resolution must be get
 */
void hanoi(bar b1, bar b2, bar b3, prev_proc prev){
	//
	return;
}
/* main function */
int main(void){
	//test
	return 0;
}
