#include <stdio.h>
#include <stdlib.h>
#define INF 9999

int min(int a,int b){
        if(a>b){
          return b;
        }else{
          return a;
	}
}
///////////////////////////////////////////////////////////////////////
// Recursive Function that estimates the shortest path between nodes //
///////////////////////////////////////////////////////////////////////
int shortest_path(int **graph,int ***iterration,int k,int i,int j){
	int distance1,distance2;
		
		if(k<0){
			return graph[i][j];
		}else{

			distance1=shortest_path(graph,iterration,k-1,i,j);
			distance2=shortest_path(graph,iterration,k-1,i,k)+shortest_path(graph,iterration,k-1,k,j);
			//in this point the array value will take the minimum distance value:
			iterration[k][i][j]=min(distance1,distance2);
		}
		//No need for the return value since we changed the memory that iterration[k][i][j] points to but it makes the program more understandable
return iterration[k][i][j];
}
//////////////////////////////////
// Basic solve function         //
//////////////////////////////////
void solve(int n,int **graph){
int i,j,k;
int ***iterration; //This will be the three dimensional array and it will get the memory needed due dynamic allocation(iterration[k][i][j])

	//DYNAMIC MEMORY ALLOCATION FOR THE THREE DIMENSIONAL ARRAY
	iterration=(int***)malloc(n*sizeof(int**));
	for(k=0; k<n; k++){
		iterration[k]=(int**)malloc(n*sizeof(int*));
		for(i=0; i<n; i++){
			iterration[k][i]=(int*)malloc(n*sizeof(int));
		}
	}

    //Here we initiallize the 3-D array to infinity values in order to take the minimum distance every time we change the k value in the function above
	for(k=0; k<n; k++){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				iterration[k][i][j]=INF;
			}
		}
	}

	//Here the recursive function changes the starting values of our array
	for(i=0; i<n; i++){
		for(j=0; j<i; j++){
			iterration[n-1][i][j]=shortest_path(graph,iterration,n-1,i,j);
		}
	}
	
	//Printinng results
 	for(i=0; i<n; i++){
        	for(j=0; j<i; j++){
        	if(iterration[n-1][i][j]!=INF)
        	printf("The shortest path from %d node to %d node is : %d\n",i,j,iterration[n-1][i][j]);
        	else
        	printf("No path\n");
        	}
        printf("\n");
 	}

	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			free(iterration[k][i]);
		}
	free(iterration[k]);
	}
free(iterration);
}
