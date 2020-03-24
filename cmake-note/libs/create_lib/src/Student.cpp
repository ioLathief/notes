#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(string name):name(name){}

void Student::display(){
	cout << "A student j with name " << this->name << endl;
}