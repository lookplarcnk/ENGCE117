#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;
 
int main()
{
  char str[86];
  int length;
  cout<<"Please Enter String : ";
  gets(str);
  length = strlen(str);
  cout<<"Please String Length : "<<length;
  return 0;
}