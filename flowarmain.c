#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "flowar.h"

int main(){
clock_t start,end,total;
	float user=0.0,system=0.0,elapsed=0.0;
	int cpu=0;
	int i,j;
	int **graph,nodes;

	start=clock();

	printf("Enter the number of the nodes");
	scanf("%d",&nodes);
	printf("\n");
	
	//Here we allocate memory to the array given the number of the nodes
	graph=(int**)malloc(nodes*sizeof(int*));
		for(i=0; i<nodes; i++){
			graph[i]=(int*)malloc(nodes*sizeof(int));
		}
		
		//At this point we will initiallize the array that holds the starting weights between every node
		for(i=0; i<nodes; i++){
			graph[0][0]=0;
        		for(j=0; j<i; j++){
            		scanf("%d",&graph[i][j]);

			if(graph[i][j]==-1)
			graph[i][j]=INF;

        		graph[j][i]=graph[i][j];
        		graph[i][i]=0;
        		}
	 	}
		end=clock();
		user=(double)(end-start)/CLOCKS_PER_SEC;
///////////////////////////////////////////////////////////////////////////////////////
// Here we call the function solve in order to find the shortest path from every nod //
///////////////////////////////////////////////////////////////////////////////////////
solve(nodes,graph);

total=clock();
system=(double)(total-end)/CLOCKS_PER_SEC;
elapsed=(double)(total-start)/CLOCKS_PER_SEC;
cpu=(double)(system/elapsed)*100;
printf("user:%.5f system:%.5f elapsed %2.5f cpu:%d %%\n ",user,system,elapsed,cpu);
	for(i=0; i<nodes; i++){
		free(graph[i]);
	}
free(graph);
}

