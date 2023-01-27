//น.ส.รัชนีกร เชื้อดี 65543206077-1 Sec 3
//https://youtu.be/6THKTWRc924
#include <iostream>
#include <stdio.h>

struct N_Node {
  int d_data;
  N_Node* next;
};

N_Node* start = NULL;

void AddNode(N_Node** head, int value) {
  N_Node* newNode = new N_Node();
  newNode->d_data = value;
  newNode->next = *head;
  *head = newNode;
}

void ShowAll() {
  N_Node* current = start;
  while (current != NULL) {
    std::cout << current->d_data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

void UpdateNode(N_Node** head, int oldValue, int newValue) {
  N_Node* current = *head;
  while (current != NULL) {
    if (current->d_data == oldValue) {
      current->d_data = newValue;
      break;
    }
    current = current->next;
  }
}

void ShowBack(N_Node* head) {
  if (head == NULL) {
    return;
  }
  ShowBack(head->next);
  std::cout << head->d_data << " ";
}

void SwapNode(N_Node** head, int value1, int value2) {
  N_Node* current = *head;
  N_Node* prev1 = NULL;
  N_Node* prev2 = NULL;
  while (current != NULL) {
    if (current->d_data == value1) {
      prev1 = current;
    }
    if (current->d_data == value2) {
      prev2 = current;
    }
    current = current->next;
  }
  if (prev1 != NULL && prev2 != NULL) {
    int temp = prev1->d_data;
    prev1->d_data = prev2->d_data;
    prev2->d_data = temp;
  }
}

int main() {
  AddNode(&start, 10);
  AddNode(&start, 20);
  AddNode(&start, 30);
  AddNode(&start, 40);
  ShowAll(); // 10 20 30 40
  UpdateNode(&start, 20, 99);
  ShowAll(); // 10 99 30 40
  UpdateNode(&start, 30, 98);
  ShowAll(); // 10 99 98 40
  std::cout << "Show back : ";
  ShowBack(start); // 40 98 99 10
  std::cout << std::endl;
  std::cout << "Swap 20 and 98 : ";
  SwapNode(&start, 20, 98);
  ShowAll(); // 10 98 99 40
  return 0;
}
