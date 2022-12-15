#include <stdio.h>

void T_Text (char **text);
int main()
{
    char *str;
    T_Text(&str);
    printf("\n%s\n", str);
    return 0;
}
void T_Text (char **text)
{
    *text = new char[30];
    gets(*text);
}