#include <stdio.h>

int *Dijkstra(int *L, int n);

int main() 
{
    int n = 5, i, j, *d, *g;
    
    g = new int[n * n];
    
    for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
    g[i * n + j] = -1;
    
    g[0 * n + 1] = 100; g[0 * n + 2] = 80;
    g[0 * n + 3] = 30; g[0 * n + 4] = 10;
    g[1 * n + 2] = 20; g[3 * n + 1] = 20;
    g[3 * n + 2] = 20; g[4 * n + 3] = 10;
    
    d = Dijkstra(g, n);
    
    for(i = 0; i < n - 1; i++)
    printf("%d ", d[i]);
    
    return 0; //end function
}

int *Dijkstra(int *L, int n)
{
    int *d;
    
    d = new int[n];
    
    return d;
}

