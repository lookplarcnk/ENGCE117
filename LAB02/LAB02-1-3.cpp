#include <stdio.h>
#include <string.h>

char *Text_T();

int main()
{
    char str[30];
    strcpy(str, Text_T());
    printf("\n%s\n", str);
    return 0;
}
char *Text_T()
{
    char *text = new char[30];
    gets(text);
    return text;
}