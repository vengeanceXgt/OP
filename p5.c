#include <stdio.h>
#define INF 9999

struct Edge {
    int u, v, w;
};

int main() {
    int n, e, choice, src;
    struct Edge edges[50];
    int dist[10];

    while(1) {
        printf("\n1. Enter Graph (Edges)\n2. Run Bellman-Ford\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter number of vertices: ");
                scanf("%d", &n);

                printf("Enter number of edges: ");
                scanf("%d", &e);

                printf("Enter edges (u v weight):\n");
                for(int i = 0; i < e; i++) {
                    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
                }
                break;

            case 2:
                printf("Enter source: ");
                scanf("%d", &src);

                // Initialize distances
                for(int i = 0; i < n; i++)
                    dist[i] = INF;

                dist[src] = 0;

                // Relax edges V-1 times
                for(int i = 1; i <= n-1; i++) {
                    for(int j = 0; j < e; j++) {
                        int u = edges[j].u;
                        int v = edges[j].v;
                        int w = edges[j].w;

                        if(dist[u] != INF && dist[u] + w < dist[v])
                            dist[v] = dist[u] + w;
                    }
                }

                // Check negative cycle
                int flag = 0;
                for(int j = 0; j < e; j++) {
                    int u = edges[j].u;
                    int v = edges[j].v;
                    int w = edges[j].w;

                    if(dist[u] != INF && dist[u] + w < dist[v]) {
                        flag = 1;
                        break;
                    }
                }

                if(flag) {
                    printf("Negative weight cycle detected!\n");
                } else {
                    printf("Shortest distances:\n");
                    for(int i = 0; i < n; i++)
                        printf("%d ", dist[i]);
                }
                break;

            case 3:
                return 0;
        }
    }
}
/* 5. BELLMAN-FORD ALGORITHM
   Time Complexity: O(V * E)
   Space Complexity: O(V)

   Note: Can detect negative weight cycles
*/