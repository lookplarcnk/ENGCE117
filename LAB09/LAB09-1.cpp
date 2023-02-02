#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode
{
  char name[20];
  int age;
  char sex;
  float gpa;
  struct studentNode *next;
};

class LinkedList
{
  protected:
  struct studentNode *start, **now;

  public:
  LinkedList();
  ~LinkedList();
  void InsNode(const char n[], int a, char s, float g);
  void GoNext();
  void GoFirst();
  void GoLast();
  void ShowAll();
  void DelNode();
  int FindNode(const char n[]);
  struct studentNode *NowNode();
  void EditNode(const char n[], int a, char s, float g);
}; // end class

void EditData(LinkedList *ll);
void AddData(LinkedList *ll);
void FindData(LinkedList *ll);
void readfile(LinkedList *ll);
void writefile(LinkedList *ll, char filename[]);

LinkedList::LinkedList()
{
  start = NULL;
  now = &start;
}

LinkedList::~LinkedList()
{
  struct studentNode *temp;
  while (start != NULL)
{
  temp = start;
  start = start->next;
  delete temp;
}
}

void LinkedList::InsNode(const char n[], int a, char s, float g)
{
  struct studentNode *newnode;
  
  newnode = new studentNode;
  strcpy(newnode->name, n);
  newnode->age = a;
  newnode->sex = s;
  newnode->gpa = g;
  newnode->next = NULL;
  
  if (start == NULL)
  {
    start = newnode;
    *now = start;
  }
  else
  {
    (*now)->next = newnode;
    *now = newnode;
  }
}

void LinkedList::GoNext()
{
  if (*now != NULL)
  *now = (*now)->next;
}

void LinkedList::GoFirst()
{
  *now = start;
}

void LinkedList::GoLast()
{
  if (start != NULL)
{
  *now = start;
  while ((*now)->next != NULL)
  *now = (*now)->next;
}
}

void LinkedList::ShowAll()
{
  struct studentNode *temp;
  
  temp = start;
  
  while (temp != NULL)
  {
    printf("Name: %s\n", temp->name);
    printf("Age: %d\n", temp->age);
    printf("Sex: %c\n", temp->sex);
    printf("GPA: %.2f\n", temp->gpa);
    temp = temp->next;
  }
}

void LinkedList::DelNode()
{
  struct studentNode *temp;

  if (*now == start)
  {
    temp = *now;
    start = (*now)->next;
    *now = start;
    delete temp;
  }
  else
  {
    temp = start;
    while (temp->next != *now)
    temp = temp->next;
    temp->next = (*now)->next;
    delete *now;
    *now = temp->next;
  }
}

int LinkedList::FindNode(const char n[])
{
  struct studentNode *temp;

  temp = start;

  while (temp != NULL)
{
  if (strcmp(temp->name, n) == 0)
  return 1;
  temp = temp->next;
}
return 0;
}

struct studentNode *LinkedList::NowNode()
{
  return *now;
}

void LinkedList::EditNode(const char n[], int a, char s, float g)
{
  strcpy((*now)->name, n);
  (*now)->age = a;
  (*now)->sex = s;
  (*now)->gpa = g;
}

void EditData(LinkedList *ll)
{
  char name[20];
  int age;
  char sex;
  float gpa;

  printf("Enter student name : ");
  scanf("%s", name);

  printf("Enter age : ");
  scanf("%d", &age);

  printf("Enter sex : ");
  do 
  {
    sex = getchar();
  } 
  while (sex != 'M' && sex != 'F');

  printf("Enter GPA : ");
  scanf("%f", &gpa);
  
  ll->EditNode(name, age, sex, gpa);
}

void AddData(LinkedList *ll)
{
  char name[20];
  int age;
  char sex;
  float gpa;

  printf("Enter student name : ");
  scanf("%s", name);
  printf("Enter age : ");
  scanf("%d", &age);
  printf("Enter sex : ");
  scanf(" %c", &sex);
  printf("Enter GPA : ");
  scanf("%f", &gpa);

  ll->InsNode(name, age, sex, gpa);
}

void FindData(LinkedList *ll)
{
  char name[20];

  printf("Enter student name : ");
  scanf("%s", name);
  
  if (ll->FindNode(name) == 1)
  {
    printf("Student Found\n");
  }
  else
  {
    printf("Student not found\n");
  }
}

void readfile(LinkedList *ll)
{
  FILE *fp;
  fp = fopen("student.txt", "r");

  if (fp == NULL)
{
  printf("Error opening file\n");
  return;
}

char name[20];
int age;
char sex;
float gpa;

while (fscanf(fp, "%s %d %c %f\n", name, &age, &sex, &gpa) != EOF)
{
  ll->InsNode(name, age, sex, gpa);
}

fclose(fp);
}

void writefile(LinkedList *ll, const char filename[])
{
  FILE *fp;
  fp = fopen(filename, "w");

  if (fp == NULL)
{
  printf("Error opening file\n");
  return;
}

  ll->GoFirst();

  struct studentNode *temp;

  while (temp = ll->NowNode())
  {
    fprintf(fp, "%s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
    ll->GoNext();
  }
  
fclose(fp);
}

int main()
{
  LinkedList listA;
  int menu;
  readfile(&listA);
  printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : ");
  scanf("%d", &menu) ;
  while(menu != 0) 
  {
    switch(menu) 
  {
    case 1 : AddData(&listA); 
    break;
    case 2 : EditData(&listA); 
    break;
    case 3 : listA.DelNode(); 
    break;
    case 4 : FindData(&listA); 
    break;
    case 5 : listA.ShowAll(); 
    break;
  }//end switch
  printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : ");
  scanf("%d", &menu);
  }//end while
  writefile(&listA, "student.txt");
  return 0;
}//end function