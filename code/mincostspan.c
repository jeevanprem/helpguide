/*7. Minimum Cost Spanning Tree — Kruskal

For MST, one common algorithm is Kruskal's Algorithm.

🧠 Core concept

Given a weighted graph:

Select the smallest edges one by one, but don't create a cycle.

Memory trick
SORT → PICK → CHECK CYCLE
Algorithm
1. Sort all edges by weight
2. Start with no edges
3. Pick smallest edge
4. Check whether it creates cycle
5. If no cycle → include it
6. Continue until V-1 edges

To check cycle, use Disjoint Set / Union-Find.

⭐ Important
if (find(parent, u) != find(parent, v)) {
    add edge;
    union(parent, u, v);
}
*/

#include <stdio.h>

struct Edge {
    int u, v, weight;
};

int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);

    return parent[x];
}

void unionSet(int parent[], int rank[], int x, int y) {

    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;

        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;

        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {

    int V, E;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];

    for (int i = 0; i < E; i++) {
        printf("Enter u v weight: ");
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }

    // Sort edges
    for (int i = 0; i < E - 1; i++) {
        for (int j = i + 1; j < E; j++) {

            if (edges[i].weight > edges[j].weight) {

                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    int parent[V];
    int rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int count = 0;
    int cost = 0;

    printf("Edges in MST:\n");

    for (int i = 0; i < E && count < V - 1; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        if (find(parent, u) != find(parent, v)) {

            printf("%d -- %d = %d\n",
                   u, v, edges[i].weight);

            cost += edges[i].weight;

            unionSet(parent, rank, u, v);

            count++;
        }
    }

    printf("Minimum cost = %d\n", cost);

    return 0;
}

/*
Enter vertices and edges: 4 5

0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Edges in MST:
2 -- 3 = 4
0 -- 3 = 5
0 -- 1 = 10

Minimum cost = 19
*/