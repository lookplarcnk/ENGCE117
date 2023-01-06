#include <iostream>
#include <cstring>

struct studentNode {
  char name[20];
  int age;
  char sex;
  float gpa;
  struct studentNode *next;
};

struct studentNode *start;

void InsNode(struct studentNode **now, char *name, int age, char sex, float gpa) {
  // Create a new node
  struct studentNode *new_node = new studentNode;
  strcpy(new_node->name, name);
  new_node->age = age;
  new_node->sex = sex;
  new_node->gpa = gpa;
  new_node->next = NULL;

  // Insert the new node before the current node
  new_node->next = *now;
  if (*now == start) {
    start = new_node;
  } else {
    struct studentNode *prev = start;
    while (prev->next != *now) {
      prev = prev->next;
    }
    prev->next = new_node;
  }
}

void GoNext(struct studentNode **now){
  if (*now != NULL) {
    *now = (*now)->next;
  }
}

void DelNode(struct studentNode **now) {
  // Check if the current node is the start of the list
  if (*now == start) {
    // Update the start pointer to point to the next node in the list
    start = (*now)->next;
  } else {
    // Iterate through the list to find the node before the current node
    struct studentNode;
  }
}

void ShowAll( struct studentNode **walk ){
    while( *walk != NULL ) {
        printf( "%s", (*walk)->name ) ;
        walk = &(*walk)->next ;
        }//end while
        printf(" ");
}//end function

int main() {
    struct studentNode *start, **now ;
    start = NULL ; now = &start ;
    InsNode( now, "one", 6, 'M', 3.11 ) ; ShowAll( &start ) ;
    InsNode( now, "two", 8, 'F', 3.22 ) ; ShowAll( &start ) ;
    GoNext( &now ) ;
    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( &start ) ;
    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( &start ) ;
    GoNext(&now) ;
    DelNode(&now) ; ShowAll( &start ) ;
    return 0 ;
}//end function


