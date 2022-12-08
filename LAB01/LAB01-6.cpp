#include <stdio.h>

int find_NewValue(int New_Value);

int main()
{
    int n_value = 10;

    int New_Value = find_NewValue(n_value);
    printf("New Value is : %d\n",New_Value);

    return 0;
}

int find_NewValue(int New_Value)
{
    return New_Value + 10;
}