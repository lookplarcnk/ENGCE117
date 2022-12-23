#include <iostream>
#include <string>

struct Person 
{
    std::string name;
    int age;
    Person *daughter;
};

int main() 
{
    Person john {"Mark Smith", 30};
    Person jane {"Jane Smith", 10};
    john.daughter = &jane;
    std::cout << john.daughter->name << std::endl; // prints " Jane Smith"
    return 0;
}
