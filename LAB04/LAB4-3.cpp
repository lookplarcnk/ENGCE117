#include <stdio.h>
#include <string.h>

struct studentNode 
{
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void SaveNode(struct studentNode *child, const char n[], int a, char s, float g)
{
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
}//end function

void GoNext1(struct studentNode *walk)
{
    if (walk != NULL)
        walk = walk->next;
}

int main()
{
    struct studentNode *start = new struct studentNode;
    SaveNode(start, "one", 6, 'M', 3.11);
    start->next = new struct studentNode;
    SaveNode(start->next, "two", 8, 'F', 3.22);
    start->next->next = new struct studentNode;
    SaveNode(start->next->next, "three", 10, 'M', 3.33);
    start->next->next->next = new struct studentNode;
    SaveNode(start->next->next->next, "four", 12, 'F', 3.44);

    struct studentNode *now1 = start;
    struct studentNode **now2 = &start;

    GoNext1(now1);
    printf( "%s ", now1->name );
}//end function
