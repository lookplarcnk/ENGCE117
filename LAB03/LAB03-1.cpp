#include <iostream>

struct Person 
{
    std::string name;
    int age;
    char gender;

void print() 
{
    std::cout << name << " is a " << age << "-year-old " << gender << "." << std::endl;
}

};

int main() 
{
  Person p {"John Smith", 30, 'M'};
  p.print(); // prints "John Smith is a 30-year-old M."
  return 0;
}
