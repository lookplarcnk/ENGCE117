#include <stdio.h>

void merge(int t[], int l, int m, int r);

void mergesort(int t[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(t, l, m);
        mergesort(t, m + 1, r);
        merge(t, l, m, r);
    }
}

void merge(int t[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = t[l + i];
    for (j = 0; j < n2; j++)
        R[j] = t[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            t[k] = L[i];
            i++;
        }
        else
        {
            t[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        t[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        t[k] = R[j];
        j++;
        k++;
    }
}

int main() 
{
    int data[7] = {4, 6, 1, 2, 5, 1, 8};
    int n = 7;
    mergesort(data, 0, n - 1);
    for(int i = 0 ; i < n ; i++) printf("%d ", data[i]);
    printf("\n");
    return 0;
}
