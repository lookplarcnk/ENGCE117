#include <iostream>  
using namespace std;  
  
int main()  
{  
    int num = 20; 
    int * p;  
    p = &num;  
  
    cout << "Address of num : " << p << "\n";  
  
    int b = *p;  
    cout << "Value of num : " << *p << "\n";  
  
    return 0;  
}