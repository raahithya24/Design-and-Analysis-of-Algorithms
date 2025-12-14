#include <stdio.h>
int visited[100], adj[100][100];
int n;
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
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
    printf("DFS Traversal: ");
    dfs(start);
printf("\n");
    return 0;
}

