#include <stdio.h>
#define INF 9999

int main() {
    int n, e, graph[10][10];
    int parent[10], key[10], visited[10];
    int u, v, w, choice;

    while(1) {
        printf("\n1. Enter Graph (Edges)\n2. Run Prim's MST\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter number of vertices: ");
                scanf("%d", &n);

                // Initialize graph
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        graph[i][j] = 0;

                printf("Enter number of edges: ");
                scanf("%d", &e);

                printf("Enter edges (u v weight):\n");
                for(int i=0;i<e;i++) {
                    scanf("%d %d %d", &u, &v, &w);
                    graph[u][v] = w;
                    graph[v][u] = w; // undirected graph
                }
                break;

            case 2:
                // Initialize
                for(int i=0;i<n;i++) {
                    key[i] = INF;
                    visited[i] = 0;
                }

                key[0] = 0;
                parent[0] = -1;

                for(int count=0; count<n-1; count++) {
                    int min = INF, u_index;

                    for(int i=0;i<n;i++)
                        if(!visited[i] && key[i] < min) {
                            min = key[i];
                            u_index = i;
                        }

                    visited[u_index] = 1;

                    for(int j=0;j<n;j++)
                        if(graph[u_index][j] && !visited[j] &&
                           graph[u_index][j] < key[j]) {
                            parent[j] = u_index;
                            key[j] = graph[u_index][j];
                        }
                }

                printf("Edges in MST:\n");
                int total = 0;
                for(int i=1;i<n;i++) {
                    printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
                    total += graph[i][parent[i]];
                }
                printf("Total Cost = %d\n", total);
                break;

            case 3:
                return 0;
        }
    }
}
/* 4. PRIM’S ALGORITHM (MST)
   Using Matrix:
      Time Complexity: O(V^2)

   Using Min Heap:
      Time Complexity: O(E log V)

   Space Complexity: O(V)
*/