#include <stdio.h>
#include <stdlib.h>
#define N 8
#define Z 5000
#define inf 100000

///*define a queue*/
//typedef struct{
//	int data[N];
//	int size;
//}queue;

/*define a function that give 0 randomly*/
int givezero(){
	return (rand() % 4);
}
/*the function to form a graph in a matrix
 */
void makeG(int graph[][N]){
	/*make the n*n graph*/ 
	for(int i = 0; i < N; i++){
		graph[i][i] = 0;
		for(int j = 0; j < i; j++){
			if(givezero()){
				graph[i][j] = -1 * rand() % 8;
				graph[j][i] = -1 * graph[i][j];
			}else {
				graph[i][j] = inf;
				graph[j][i] = graph[i][j];
			}
	    }
	}
}

void printG(int graph[][N]){
	/*print the matrix in a matrix way*/
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			//printf("the distance between %d and %d is %d\n", i, j, graph[i][j]);
	        printf("%d\t", graph[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*the matrix to save the closest distance between every 2 points*/ 
void initial(int d[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			d[i][j] = Z;
		}
		d[i][i] = 0;
	}
}

/*give an array, record the node on the closest road
 *and give a function to print the shortest road
 */
int node[N];
void printRoad(int n[]){
	int before = 0;
	printf("the road: 0\t");
	while(before != N-1){
		printf("%d\t", n[before]);
		before = n[before];
	}
}


/*the function to find the shortest way
 *input:graph matrix, output:length of the road between a & b 
 */
int dijkstra(int g[][N], int d[][N], int a, int b){
	/*dijkstra algoritm
	 *find out the shortest way between pointer a & b
	 *int dis is the steps between them 
	 */
	int distance = 1000;
	int shortest = -1;
	for(int i = 0; i < N; i++){
		/*make sure the direction is right*/
		if(g[a][i] > 0 && g[a][i] < 200){
			/*get the distance of i & b*/
			int dis_i;
			if(d[i][b] == Z){
				dis_i = dijkstra(g, d, i, b);
			}else{
				dis_i = d[i][b];
			}
			/*test if any could be shorter in set of d(a-i) + d(i-b)*/
			if(distance > (g[a][i] + dis_i)){
				distance = g[a][i] + dis_i;
				shortest = i;
			}
		}
	}
	node[a] = shortest;
	d[a][b] = distance;
	return distance;
}


int main(void){
 	/* initialize the graph matrix g*/ 
 	int g[N][N];
 	makeG(g);
 	g[0][N-1] = 50;
 	
 	/*give a fixed example*/
 	int g2[8][8] = {
 		{0, 1, 2, 5, inf, inf, inf, inf},
 		{inf, 0, inf, inf, 4, 11, inf, inf},
		{inf, inf, 0, inf, 9, 5, 16, inf},
 		{inf, inf, inf, 0, inf, inf, 2, inf},
 		
 		{inf, inf, inf, inf, 0, inf, inf, 18},
 		{inf, inf, inf, inf, inf, 0, inf, 1},
 		{inf, inf, inf, inf, inf, inf, 0, 2},
 		{inf, inf, inf, inf, inf, inf, inf, 0},
	};
	
 	/*initial distance matrix d*/ 
 	int d[N][N];
 	initial(d);

 	/*show the graph, do the dijkstra, show the distance matrix, print result*/
 	printG(g);
 	int length = dijkstra(g2, d, 0, N-1);
	printG(d);
 	
 	/*print the result*/
 	printf("the length of road: %d\n", length);
 	printRoad(node);
}
