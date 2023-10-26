#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
	printf("Queue is full\n");
	return;
    }
    if (front == -1) {
	front = 0;
    }
    queue[++rear] = data;
}

int dequeue() {
    int data = queue[front];
    if (front == -1) {
	printf("Queue is empty\n");
	return -1;
    }
    if (front == rear) {
	front = rear = -1;
    } else {
	front++;
    }
    return data;
}

int isQueueEmpty() {
    if(front == -1){
	return 1;
    }
    return 0;
}

void breadthFirstSearch(int adj[][MAX], int visited[], int n, int start) {
    int i;
    enqueue(start);
    visited[start] = 1;

    while (!isQueueEmpty()) {
	int currentNode = dequeue();
	printf("%d ", currentNode);

	for (i = 0; i < n; i++) {
            if (adj[currentNode][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
	}
    }
}

int main() {
    int startNode,i,j,n,adj[MAX][MAX],visited[MAX]= {0}; // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);


    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    scanf("%d", &adj[i][j]);
	}
    }
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    printf("Breadth-First Search Traversal:\n");
    breadthFirstSearch(adj, visited, n, startNode);

    getch();
    return 0;
}
