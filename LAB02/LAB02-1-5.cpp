#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverseStr(char s[])
{
    printf("Initial string is: %s\n", s);
    int cCounter = strlen(s);
    char *result = (char *) malloc(cCounter + 1);

    printf("String contains %d symbols\n", cCounter);

    int begin = cCounter;

    for(; cCounter > 0; cCounter--)
    {
        result[begin - cCounter] = s[cCounter - 1];
    }
    result[begin] = '\0';   
    return result;
}

int main()
{
    char testStr[] = "Hello worlddddd";
    char *pTestStr;

    puts("----------------------------------");
    puts("Input a string:");
    pTestStr = reverseStr(testStr);
    printf("%s\n", pTestStr);
    free(pTestStr);
    return 0;
}