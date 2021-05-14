#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;


class Person::PersonImpl {
 public:
  void greet(Person *person) { cout << "Hello, my name is " << person->name << endl; }
};

Person::Person(std::string name) : pImpl(new PersonImpl), name(name){};
void Person::greet() { pImpl->greet(this); };
