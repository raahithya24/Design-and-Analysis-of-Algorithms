#include <stdio.h>
int queue[100], front = -1, rear = -1;
int visited[100], adj[100][100];
int n;
void enqueue(int v) {
    if(front == -1)
        front = 0;
    queue[++rear] = v;
}
int dequeue() {
    return queue[front++];
}
void bfs(int start) {
    enqueue(start);
    visited[start] = 1;
    while(front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("BFS Traversal: ");
    bfs(start);
    printf("\n");
    return 0;
}

