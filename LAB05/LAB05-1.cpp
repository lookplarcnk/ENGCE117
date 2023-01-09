#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>

using namespace std;

struct studentNode{
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

studentNode* AddNode(studentNode **start, const char *name, int age, char sex, float gpa){
    studentNode *new_node = new studentNode;
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->sex = sex;
    new_node->gpa = gpa;
    new_node->next = nullptr;
if (*start == nullptr){
    *start = new_node;
    return new_node;
}

studentNode *last = *start;
while (last->next != nullptr){
    last = last->next;
}
last->next = new_node;
return new_node;
}

void InsNode(studentNode *prev_node, const char *name, int age, char sex, float gpa){
    if (prev_node == nullptr){
        return;
    }

studentNode *new_node = new studentNode;
strcpy(new_node->name, name);
new_node->age = age;
new_node->sex = sex;
new_node->gpa = gpa;
new_node->next = prev_node->next;
prev_node->next = new_node;
}

void DelNode(studentNode *prev_node){
    if (prev_node == nullptr || prev_node->next == nullptr){
        return;
    }

studentNode *temp = prev_node->next;
prev_node->next = temp->next;
delete temp;
}

void ShowAll(studentNode *walk){
    while (walk != nullptr){
        cout << walk->name << " ";
        walk = walk->next;
    }
cout << endl;
}

int main(){
    studentNode *start = nullptr;
    studentNode *now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44); 
    ShowAll(start);
    DelNode(now); 
    ShowAll(start);
    return 0;
}

