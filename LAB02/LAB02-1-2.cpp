#include <stdio.h>

void TText (char *text);
int main()
{
    char str[20];
    TText(str);
    printf("\n%s\n", str);
    return 0;
}
void TText (char *text)
{
    gets(text);
}