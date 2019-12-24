   #include <stdio.h>
#define MAXPLATE 100
#define COUNT 10
/* two main data struct in the pr */
/* record every bar's every plate number */
typedef struct BAR{
	int plate[MAXPLATE];
	int length;
}bar;

/*fill the one with plates*/
void fillBar(int b[]){
	for(int i = 0; i < COUNT; i++){
		b[i] = COUNT - i;
	}
}

/*fill the empty bar*/
void initBar(int b[]){
	for(int i = 0; i < COUNT; i++){
		b[i] = 0;
	}
}

/* count the nearest 3 steps' 123 usage */
typedef struct PREV_PROC{
	int count[4];
}prev_proc;

/* print prev */
void printPrev(prev_proc prev){
	printf("previous operations");
	for(int i = 0; i < 4; i++){
		printf("%d\t", prev.count[i]);
	}
	printf("\n");
}
/*print bar in three column*/
void printBar(bar b[]){
	bar b1, b2, b3;
	b1 = b[1]; b2 = b[2]; b3 = b[3];
	int l1, l2, l3;
	l1 = b1.length;
	l2 = b2.length;
	l3 = b3.length;
	int len;
	
	/*find the longest bar and count its length*/
	if(l1 > l2)
		len = l1;
	else
		len = l2;
	if(l3 > len)
		len = l3; 
		
	printf("three bars: \n");
	printf("    \tbar1\tbar2\tbar3\n");
	/*print in three row*/
	for(int i = len - 1; i > -1; i--){
		printf("row %d\t", i);
		if(b1.plate[i] > 0)					/*the b1 row*/
			printf("%d\t", b1.plate[i]);
		else
			printf("\t");
		if(b2.plate[i] > 0)					/*the b2 row*/
			printf("%d\t", b2.plate[i]);
		else
			printf("\t");
		if(b3.plate[i] > 0)					/*the b3 row*/
			printf("%d\t", b3.plate[i]);
		else
			printf("\t");
		printf("\n");
	}
	printf("\n");
	return;
}

int useTwice(prev_proc prev){
	//I ! forgot to instantiate the int value before using them to calculate 
	int b1 = 0;
	int b2 = 0;
	int b3 = 0;
	for(int i = 0; i < 4; i++){
		if(prev.count[i] == 1){
			b1++;
		}else if(prev.count[i] == 2){
			b2++;
		}else if(prev.count[i] == 3){
			b3++;
		}
	}
	int twice;
	if(b1 == 2){
		twice = 1;
	}else if (b2 == 2){
		twice = 2;
	}else if (b3 == 2){
		twice = 3;
	}
	return twice;
}

/* return 0/1, 
 * 1 means the order is right b1 top plate < b2's
 * 0 means the order should be reversed
 */
int bigPlate(bar b1, bar b2){
	/*check if there's plate on both bar*/
	if(b1.length == 0){
		return 0;
	}
	if(b2.length == 0){
		return 1;
	}
	
	int b1top, b2top;
	b1top = b1.plate[b1.length - 1];
	b2top = b2.plate[b2.length - 1];
	
	if(b1top > b2top){
		return 0;
	}else{
		return 1;
	}
}

int topp(bar b){
	return b.plate[b.length - 1];
}

/*watch out! return the bar struct!*/
bar add(int p, bar b){
	b.plate[b.length] = p;
	b.length += 1;
	return b;
}
bar del(bar b){
	b.plate[b.length - 1] = 0;
	b.length -= 1;
	return b;
}

/* main method:
 * according to different length, set the start process
 * move plates according to three rules, bar to bar
 *    1. among three operation, every bar must appear twice
 * 	  2. destination can't be the a new start, which would be one of the ending condition
 *    3. the small one can't be placed over a bigger one
 * then a resolution must be get
 */
void hanoi(bar b[], prev_proc prev){
	/*determine the first two destination*/
	if(COUNT % 2 == 0){
		/*first step*/
		b[2] = add(topp(b[1]), b[2]); b[1] = del(b[1]);
		prev.count[0] = 1; prev.count[1] = 2;
		/*second step*/
		b[3] = add(topp(b[1]), b[3]); b[1] = del(b[1]);
		prev.count[2] = 1; prev.count[3] = 3;
	}else{
		/*first step*/
		b[3] = add(topp(b[1]), b[3]); b[1] = del(b[1]);
		prev.count[0] = 1; prev.count[1] = 3;
		/*second step*/
		b[2] = add(topp(b[1]), b[2]); b[1] = del(b[1]);
		prev.count[2] = 1; prev.count[3] = 2;
	}
	
	/* first we make sure the length of b1 should bigger than 3
	 * so, we ignore the situation which COUNT is less than 3
	 */
	int k = 0; 
	int start, dest, twice, last;
	while(b[1].length != 0 || b[2].length != 0){
		printPrev(prev);
	 	k++;
	 	printf("%d round: \n", k);
		/*check the twice*/
	 	twice = useTwice(prev);
	 	last = prev.count[3];
	 	printf("twice: %d, last: %d\n", twice, last);
	 	/*get the new destination and the start*/
	 	for(int i = 1; i < 4; i++){
	 		if(i != last && i != twice){
	 			start = i;
	 			/*sily enough to put 'break' outside the if-loop*/
	 			break;
			}
		}
		//printf("here\t");
		for(int i = 1; i < 4; i++){
			//sometime we should check well after we arbitrarily use another block of code 
		 	if(i != twice && i != start){
		 		dest = i;
		 		break;
			}
		}
		int tem;
		if(!bigPlate(b[start], b[dest])){
			tem = start;
			start = dest;
			dest = tem;
		}
		/* edit of prev */
		prev.count[0] = prev.count[2];
		prev.count[1] = prev.count[3];
		prev.count[2] = start;
		prev.count[3] = dest;
		printPrev(prev);
		//printf("there\t");
		printf("start: %d, dest: %d\n", start, dest);
		/* add & delete */
		b[dest] = add(topp(b[start]), b[dest]);
		b[start] = del(b[start]);
		printBar(b);
		//printf("this\t");
	}
	
	return;
}
/* main function */
int main(void){
	/* initiate bar */
	bar b1, b2, b3;
	fillBar(b1.plate); initBar(b2.plate); initBar(b3.plate);
	b1.length = COUNT; b2.length = 0; b3.length = 0;
	
	prev_proc prev;
	
	/*set a bar struct array store b1 b2 b3, for easy to use*/
	bar bara[4]; bara[1] = b1; bara[2] = b2; bara[3] = b3;
	
	//small test
//	printBar(bara);
//	bara[2] = add(topp(bara[1]), bara[2]); bara[1] = del(bara[1]);
	//printBar(bara);
	
	/* irretate hanoi */
	hanoi(bara, prev);
}
