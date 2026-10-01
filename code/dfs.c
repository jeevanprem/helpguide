/*
1. DFS — Depth First Search
Main concept

DFS goes as deep as possible before coming back.

Start
 ↓
Visit vertex
 ↓
Mark visited
 ↓
Check neighbours
 ↓
If unvisited → go there
 ↓
Repeat
⭐ Important logic to remember
printf("%d ", v);
visited[v] = 1;

for (int i = 0; i < n; i++)
{
    if (graph[v][i] == 1 && visited[i] == 0)
    {
        DFS(i, n);
    }
}

The most important line is:

DFS(i, n);

Because i is the new unvisited neighbour.
*/

#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void DFS(int v, int n)
{
    // Visit the vertex
    printf("%d ", v);
    visited[v] = 1;

    // Check all adjacent vertices
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i, n);
        }
    }
}

int main()
{
    int n;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");

    DFS(start, n);

    return 0;
}
/*
Example Input
Enter number of vertices: 5

Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 0
1 0 0 1 1
0 1 1 0 1
0 0 1 1 0

Enter starting vertex: 0
Output
DFS Traversal: 0 1 3 2 4

The exact DFS order can vary depending on the order in which neighbours are checked.

🧠 DFS — What to memorize
1. Global arrays
int graph[MAX][MAX];
int visited[MAX];
2. DFS function
void DFS(int v, int n)
3. Visit current vertex
printf("%d ", v);
visited[v] = 1;
4. Check neighbours
for (int i = 0; i < n; i++)
5. Connected + unvisited
if (graph[v][i] == 1 && visited[i] == 0)
6. Recursive call ⭐⭐⭐⭐
DFS(i, n);*/