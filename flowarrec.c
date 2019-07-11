#include <stdio.h>
#include <stdlib.h>
#define INF 9999
int min(int a,int b){
	if(a>b){
	  return b;  //a>b
	}else{
	  return a;  //a<b
	}
}
/////////////////////////////////////////////////////////////
// Recursive Function that estimates the Shortest Path     //
/////////////////////////////////////////////////////////////
int shortest_path(int **graph,int k,int i,int j){
int distance1,distance2;
 //Finding the shortest i->k + k->j path:
	
	if(k<0){
	return graph[i][j];
	}else{
		distance1=shortest_path(graph,k-1,i,j);
		distance2=shortest_path(graph,k-1,i,k)+shortest_path(graph,k-1,k,j);
	}
	
return min(distance1,distance2);
}
/////////////////////////////////////////////////////////////
void solve(int n,int **graph){
int i,j,k;
    //here we change the values of the starting "graph" array to those that finaly will give us the shortest path between every node
	for(i=0; i<n; i++){
 		for(j=0; j<i; j++){
			graph[i][j]=shortest_path(graph,n-1,i,j);
			}
 	}
 //Printing the results
 for(i=0; i<n; i++){
 	for(j=0; j<i; j++){
	if(graph[i][j]!=INF)
	printf("The shortest path from %d node to %d node is : %d\n",i,j,graph[i][j]);
	else
	printf("No path\n");
	}
	printf("\n");
 }
}



