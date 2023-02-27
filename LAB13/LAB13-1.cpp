#include <stdio.h>
#include <stdlib.h>

int* KnapsackDP(int* w, int* v, int n, int wx);

int main() 
{
  int n = 5, wx = 11;
  int w[5] = {1, 2, 5, 6, 7};
  int v[5] = {1, 6, 18, 22, 28};
  int* x;
  x = KnapsackDP(w, v, n, wx);
  for (int i = 0; i < n; i++) printf("%d ", x[i]);
  free(x);
  return 0;
} //end function

int* KnapsackDP(int* w, int* v, int n, int wx) 
{
  int* x = (int*)malloc(n * sizeof(int));
  int K[n + 1][wx + 1];
  for (int i = 0; i <= n; i++) 
  {
    for (int j = 0; j <= wx; j++) 
    {
      if (i == 0 || j == 0)
        K[i][j] = 0;
      else if (w[i - 1] <= j)
        K[i][j] = (v[i - 1] + K[i - 1][j - w[i - 1]]) > K[i - 1][j]
                      ? (v[i - 1] + K[i - 1][j - w[i - 1]])
                      : K[i - 1][j];
      else
        K[i][j] = K[i - 1][j];
    }
  }

  int j = wx;
  for (int i = n; i > 0 && j >= 0; i--) 
  {
    if (K[i][j] != K[i - 1][j]) 
    {
      x[i - 1] = 1;
      j -= w[i - 1];
    } 
    else 
    {
      x[i - 1] = 0;
    }
  }
  return x;
}
