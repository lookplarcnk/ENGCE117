#include <iostream>

using namespace std;

int main()
{
  int score;
  cout<<"Enter Your Score: ";
  cin>>score;
  if (score >= 80)
  {
    cout<<"A";
  }
  else if (score < 80)
  {
    cout<<"FAIL";
  }
  else
  {
    cout<<"Enter Valid Score";
  }
  return 0;
}