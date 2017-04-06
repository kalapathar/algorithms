#include<iostream>
using namespaces std;

   
int n=10;
int graph[128][128], n; // a weighted graph and its size
void floydWarshall() {
	for( int k = 0; k < n; k++ )
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
				graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j] );
 }
   int main {
       // initialize the graph[][] adjacency matrix and n
       // graph[i][i] should be zero for all i.
       // graph[i][j] should be "infinity" if edge (i, j) does not exist
       // otherwise, graph[i][j] is the weight of the edge (i, j)
       floydWarshall();
       // now graph[i][j] is the length of the shortest path from i to j
   }
