#include <stdio.h>

#define MAX 100

void depthFirstSearch(int adj[][MAX], int visited[], int n, int vertex) {
    int i;
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (i = 0; i < n; i++) {
	if (adj[vertex][i] == 1 && !visited[i]) {
	    depthFirstSearch(adj, visited, n, i);
	}
    }
}

int main() {
    int startVertex,i,j,n,adj[MAX][MAX],visited[MAX] = {0}; // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    scanf("%d", &adj[i][j]);
	}
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("Depth-First Search Traversal:\n");
    depthFirstSearch(adj, visited, n, startVertex);

    getch();
    return 0;
}
