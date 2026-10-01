/*8. Dijkstra Algorithm
🧠 Core concept

Find shortest path from one source to every other vertex.

Works with:

Non-negative edge weights only.

Memory trick
DISTANCE → MINIMUM → FIX → RELAX
Algorithm
1. Set all distances = infinity
2. source distance = 0
3. Find unvisited vertex with minimum distance
4. Mark it visited
5. Relax all its neighbours
6. Repeat V-1 times
Relaxation ⭐⭐⭐

This is the most important line:

if (dist[u] + graph[u][v] < dist[v])
    dist[v] = dist[u] + graph[u][v];
    */

#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int visited[]) {

    int min = INT_MAX;
    int index = -1;

    for (int i = 0; i < V; i++) {

        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int graph[V][V], int source) {

    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, visited);

        visited[u] = 1;

        for (int v = 0; v < V; v++) {

            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] =
                    dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance\n");

    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {

    int graph[V][V] = {

        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 9, 4},
        {5, 2, 9, 0, 2},
        {0, 0, 4, 2, 0}
    };

    dijkstra(graph, 0);

    return 0;
}

/*
Vertex  Distance
0       0
1       7
2       8
3       5
4       7
*/