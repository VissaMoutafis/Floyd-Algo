#include <stdio.h>
#include <stdlib.h>
#define INF 9999
/////////////////////////////////////////////////////////////
// Printing the shortest path with this recursive function //
/////////////////////////////////////////////////////////////
#ifdef PATH
void print_path(int **path,int i,int j){
	if(path[i][j]==i){
		return;
	}
	print_path(path,i,path[i][j]);  //Here we use recursion in order to find the shortest path from node i to node k and then to node j etc using the path array
	printf("%d->",path[i][j]);
}
#endif
////////////////////////////////////////////////////
// Basic solve Function                           //
////////////////////////////////////////////////////
void solve(int n,int **graph){
	int i,j,k;
	int **short_graph;
	int **path;

	#ifdef PATH
	//Here we allocate memory for the array we use to build the path,which component will be the next node from node i,when we will trying to find the shortest i->j path
	 path=(int **)malloc(n*sizeof(int *));
	 for (i=0; i<n; i++){
	 	path[i]=(int *)malloc(n*sizeof(int));
	 }
	#endif

	//Here we allocate memory to the array we use to keep the minimum distances between nodes
	short_graph=(int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		short_graph[i]=(int*)malloc(n*sizeof(int));
	}

	//We give to the short_graph array starting values of the first graph
	for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				short_graph[i][j]=graph[i][j];
			}
		}
	#ifdef PATH
	//Here we initiallize the "path" array
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(graph[i][j]==0){
				path[i][j]=0;
			}else if (graph[i][j]==INF){
				path[i][j]=INF;
			}else{
				path[i][j]=i;
			}
		}
	}
	#endif
	//we change the values of our array for each k (Repetitive Algorithm found in the wiki page)
	for(k=0; k<n; k++){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(short_graph[i][k]!=INF && short_graph[k][j]!=INF &&(short_graph[i][k]+short_graph[k][j]<short_graph[i][j])){
					#ifdef PATH
					path[i][j]=path[k][j];  //Storing the "next node" in order to build the path i->j
					#endif
					short_graph[i][j]=short_graph[i][k]+short_graph[k][j];
				}
			}
		}
	}

	//Printing the results
	for(i=0; i<n; i++){
        	for(j=0; j<i; j++){
        		if(short_graph[i][j]!=INF){
        		printf("The shortest path from %d node to %d node is : %d\n",i,j,short_graph[i][j]);
        		#ifdef PATH
			printf(" and the actual path is:\t");
        		printf("%d->",i);
        		print_path(path,i,j);
        		printf("%d\n",j);
			#endif
        	}else{
        		printf("No path\n");
        	}
       	}
		printf("\n");
 	}


}
