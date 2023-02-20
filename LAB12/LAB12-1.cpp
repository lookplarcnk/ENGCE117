#include <stdio.h>
#include <limits.h>

int* Dijkstra(int* L, int n);

int main()
{
    int n = 5, i = 0, j = 0, *d, *g;
    g = new int[n * n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100; g[0 * n + 2] = 80;
    g[0 * n + 3] = 30; g[0 * n + 4] = 10;
    g[1 * n + 2] = 20; g[3 * n + 1] = 20;
    g[3 * n + 2] = 40; g[4 * n + 3] = 10;

    d = Dijkstra(g, n);
    for (i = 1; i < n; i++)
        printf("%d ", d[i]);
    return 0; 
} //end function

int* Dijkstra(int* L, int n) 
{
    int i, j, u, v, min;
    int* dist = new int[n];
    int* s = new int[n];

    for (i = 1; i < n; i++) 
    {
        dist[i] = L[i];
        s[i] = 0;
    }
    s[0] = 1;

    for (i = 1; i < n; i++) 
    {
        min = INT_MAX;
        for (j = 1; j < n; j++) 
        {
            if (!s[j] && dist[j] < min) 
            {
                u = j;
                min = dist[j];
            }
        }
        s[u] = 1;
        for (v = 1; v < n; v++) 
        {
            if (!s[v] && L[u * n + v] != -1) 
            {
                if (dist[u] + L[u * n + v] < dist[v])
                    dist[v] = dist[u] + L[u * n + v];
            }
        }
    }
    return dist;
}
