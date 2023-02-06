#include <stdio.h>

int BinSearch(int arr[], int size, int target) 
{
    int low = 0, high = size - 1, mid;
    while (low <= high) 
    {
        mid = (low + high) / 2;
        if (arr[mid] == target) 
        {
            return mid;
        } 
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main() 
{
    int data[6] = {1, 2, 3, 4, 5, 7};
    int n = 6, find = 5;
    int pos = BinSearch(data, n, find);
    if (pos == -1) 
    {
        printf("Element not found in the array\n");
    } 
    else 
    {
        printf("Found 5 at %d\n", pos);
    }
    return 0;
}
