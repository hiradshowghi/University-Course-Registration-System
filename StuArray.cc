#include "StuArray.h"
#include <iostream>


StuArray::StuArray() : numStudents(0) {}


StuArray::~StuArray() {
    for (int i = 0; i < numStudents; ++i) {
        delete students[i]; 
    }
}


void StuArray::add(Student* student) {
    int i;
    for (i = numStudents - 1; (i >= 0 && students[i]->lessThan(*student)); --i) {
        students[i + 1] = students[i]; 
    }
    students[i + 1] = student; 
    ++numStudents;
}

bool StuArray::find(std::string num, Student** stu) const{
    for (int i = 0; i < numStudents; ++i) {
        if (students[i]->getId() == num) {
            *stu = students[i];
            return true;
        }
    }
    *stu = nullptr; 
    return false;
}

void StuArray::print() const {
    for (int i = 0; i < numStudents; ++i) {
        students[i]->print();
    }
}
