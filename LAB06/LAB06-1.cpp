#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
    struct studentNode *back ;
} ;

struct studentNode *AddNode(struct studentNode **start, const char *name, int age, char sex, float gpa) {
    struct studentNode *new_node = new studentNode;
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->sex = sex;
    new_node->gpa = gpa;
    new_node->next = NULL;
    new_node->back = NULL;

    if(*start == NULL) {
        *start = new_node;
    }
    else{
        struct studentNode *current = *start;
        while(current->next!=NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->back = current;
    }

    return new_node;
}

void InsNode(struct studentNode *now, const char *name, int age, char sex, float gpa) {
    struct studentNode *new_node = new studentNode;
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->sex = sex;
    new_node->gpa = gpa;
    new_node->next = NULL;
    new_node->back = NULL;

    if (now == NULL) {
        return;
    }

    if (now->back == NULL){
        now->back = new_node;
        new_node->next = now;
    }
    else{
        now->back->next = new_node;
        new_node->back = now->back;
        new_node->next = now;
        now->back = new_node;
    }
}

void GoBack(struct studentNode **now) {
    if (*now != NULL) {
        *now = (*now)->back;
    }
}

void DelNode(struct studentNode *now) {
    if (now == NULL)
    {
        return;
    }

    if (now->back == NULL && now->next == NULL) {
        delete now;
        now = NULL;
    }
    else if (now->back == NULL) {
        now->next->back = NULL;
        delete now;
        now = now->next;
    }
    else if (now->next == NULL) {
        now->back->next = NULL;
        delete now;
        now = now->back;
    }
    else
    {
        now->back->next = now->next;
        now->next->back = now->back;
        delete now;
        now = now->next;
    }
}

void ShowAll (struct studentNode *walk ) {
    while( walk != NULL ) {
        printf( "%s ", walk->name ) ;
        walk = walk->next ;
        }//end while
        printf( " " ) ;
}//end function

int main() {
    struct studentNode *start, *now ;
    start = NULL ;
    now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
    now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
    GoBack( &now ) ;
    DelNode( now ) ; ShowAll( start ) ;
    DelNode( now ) ; ShowAll( start ) ;
    DelNode( now ) ; ShowAll( start ) ;
    return 0 ;
}//end function