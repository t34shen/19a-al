#include <stdio.h>
#define S 1500

/* to count how many type of words in the file
 * as well as count how many s in the file
 * count the percentage of letters in the file
 */
void getTxtData(FILE *fp, double rate[]){
	/*initiate rate[]*/
	for(int i = 0; i < 127; i++){
		rate[i] = 0;
	}
	
	/*if we meet '10', the text would change line and can't get by a single fgets*/
	char buf[S];
	/* use a while loop to read txt with line break!!!
	 * though I still don't understand why it could do it
	 */
	int sum = 0;
	while (fgets(buf, S, fp) != NULL){
		for(int i = 0; i < S; i++){
			if(buf[i] == 10){
				break;
			}
			sum += 1;
			//printf("%d", buf[i]);
			rate[buf[i]] += 1;
		}
	}
	double summary;
	/*calculate the percentage of every letter*/
	for(int i = 0; i < 127; i++){
		rate[i] = rate[i] / sum * 100;
		summary += rate[i];
	}
	printf("summary: %f\n", summary);
//	/*exam the rate array*/
//	for(int i = 0; i < 127; i++){
//		/*can't use %d to printf a double!!! remenber!*/
//		printf("%d %c: %f\n", i, i, rate[i]);
//	}
}
