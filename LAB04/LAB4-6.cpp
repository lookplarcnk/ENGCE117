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

void SaveNode (struct studentNode *child, char n[], int a, char s, float g)
{
    strcpy(child->name, n);
    child->age = a;
    child->sex = s;
    child->gpa = g;
}

void GoNext2(struct studentNode **walk)
{
    if (*walk != NULL)
    *walk = (*walk)->next;
}

int main()
{
    struct studentNode *now1, **now2, *start = new struct studentNode;
    SaveNode(start, "one", 6, 'M', 3.11);
    start->next = new struct studentNode;
    SaveNode(start->next, "two", 8, 'F', 3.22);
    start->next->next = new struct studentNode;
    SaveNode(start->next, "three", 10, 'M', 3.33);
    start->next->next = new struct studentNode;
    SaveNode(start->next, "four", 12, 'F', 3.44);
    start->next->next->next = new struct studentNode;

    now1 = start;
    now2 = &start;

    GoNext2(now2);
    printf("%s", (*now2)->name);

    return 0;
}

