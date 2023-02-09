#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx)
{
    int i, j, maxi, *x, *ratio;
    x = (int *)malloc(n * sizeof(int));
    ratio = (int *)malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++)
    {
        ratio[i] = v[i] / w[i];
    }
  
  for (i = 0; i < n; i++)
  {
    maxi = i;
    for (j = i + 1; j < n; j++) 
    {
        if (ratio[j] > ratio[maxi]) 
        {
            maxi = j;
        }
    }
    
    int temp = ratio[i];
    ratio[i] = ratio[maxi];
    ratio[maxi] = temp;
    
    temp = w[i];
    w[i] = w[maxi];
    w[maxi] = temp;
    
    temp = v[i];
    v[i] = v[maxi];
    v[maxi] = temp;
  }
  
  for (i = 0; i < n; i++)
  {
    if (wx >= w[i]) 
    {
        x[i] = 1;
        wx -= w[i];
    } 
    else 
    {
        x[i] = wx / w[i];
        break;
    }
  }
  
  free(ratio);
  return x;
}

int main()
{
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x = KnapsackGreedy(w, v, n, wx);
    for (int i = 0; i < n; i++)
    printf("%d ", x[i]);
    return 0;
} //end function
