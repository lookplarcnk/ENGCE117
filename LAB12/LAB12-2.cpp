#include <stdio.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx)
{
    int *x = new int[n];
    double *r = new double[n];
    for (int i = 1; i < n; i++) 
    {
        r[i] = (double)v[i] / w[i];
        x[i] = 0;
    }
    for (int i = 1; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (r[i] < r[j]) 
            {
                double temp = r[i];
                r[i] = r[j];
                r[j] = temp;
                int temp1 = w[i];
                w[i] = w[j];
                w[j] = temp1;
                int temp2 = v[i];
                v[i] = v[j];
                v[j] = temp2;
            }
        }
    }
    
    int weight = 0;
    for (int i = 0; i < n; i++) 
    {
        if (weight + w[i] <= wx) 
        {
            x[i] = 1;
            weight += w[i];
        }
    }
    
    delete[] r;
    return x;
}

int main() 
{
    int n = 5, wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x = KnapsackGreedy( w, v, n, wx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    return 0 ;
} //end function
