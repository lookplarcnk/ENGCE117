#include <stdio.h>
#include <string.h>

struct studentNode {
  char name[ 20 ] ;
  int age ;
  char sex ;
  float gpa ;
  studentNode *next;
};

class LinkedList {
  protected :
    struct studentNode *start, **now ;
  public :
    LinkedList() ; //กำหนดค่าเริ่มต้นของ start และ now
    ~LinkedList() ; //คืนหน่วยความจำที่จองไว้ในลิงค์ลิสต์ทุกโหนด
    void InsNode( const char n[], int a, char s, float g ) ; //แทรกโหนดใหม่อยู่ก่อนโหนดปัจจุบัน
    void DelNode() ; //ลบโหนดปัจจุบัน
    void GoNext() ; //เปลี่ยนโหนดปัจจุบันไปชี้ที่โหนดถัดไป
    virtual void ShowNode() ; //แสดงข้อมูลในโหนดปัจจุบัน
}; //end class

class NewList : public LinkedList {
  public :
    void GoFirst() ; //เปลี่ยนโหนดปัจจุบันไปชี้ที่โหนดเริ่มต้น
    virtual void ShowNode() ; //แสดงข้อมูลในทุกโหนดตั้งแต่เริ่มต้นถึงสุดท้าย
}; //end class

int main() {
  LinkedList listA ;
  NewList listB ;
  LinkedList *listC ;

  listA.InsNode( "one", 1, 'A', 1.1 ) ;
  listA.InsNode( "two", 2, 'B', 2.2 ) ;
  listA.InsNode( "three", 3, 'C', 3.3 ) ;
  listA.GoNext() ;
  listA.ShowNode() ;

  listB.InsNode( "four", 4, 'D', 4.4 ) ;
  listB.InsNode( "five", 5, 'E', 5.5 ) ;
  listB.InsNode( "six", 6, 'F', 6.6 ) ;
  listB.GoNext() ;
  listB.DelNode() ;
  listB.ShowNode() ;

  listC = &listA;
  listC->GoNext() ;
  listC->ShowNode() ;

  listC = &listB ;
  listC->ShowNode() ;

  return 0 ;
} //end function

LinkedList::LinkedList() {
  start = NULL;
  now = &start;
}

LinkedList::~LinkedList() {
  struct studentNode *cur = start;
  while (cur != NULL) {
    struct studentNode *temp = cur;
    cur = cur->next;
    delete temp;
  }
}

void LinkedList::InsNode ( const char n[], int a, char s, float g ){
  struct studentNode *newNode = new studentNode;
  strcpy( newNode->name, n );
  newNode->age = a;
  newNode->sex = s;
  newNode->gpa = g;
  
  newNode->next = start;
  start = newNode;
  *now = start;
}

void LinkedList::DelNode(){
  if (*now){
    struct studentNode *tmp = *now;
    *now = (*now)->next;
    delete tmp;
  }
}

void LinkedList::GoNext(){
  *now = ( *now ) -> next ;
}

void LinkedList::ShowNode(){
  if(*now){
    printf("Name: %s\n", (*now)->name);
    printf("Age: %d\n", (*now)->age);
    printf("Sex: %c\n", (*now)->sex);
    printf("GPA: %f\n", (*now)->gpa);
  }
  else{
    printf("No current node.\n");
  }
}

void NewList::GoFirst(){
  this->now = &(this->start);
}

void NewList::ShowNode(){
  struct studentNode *ptr = start;
  while (ptr != NULL){
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);
    printf("Sex: %c\n", ptr->sex);
    printf("GPA: %f\n", ptr->gpa);
    ptr = ptr->next;
  }
}


