#include "Registration.h"
#include <iostream>



const int INITIAL_REGISTRATION_ID = 1000; 
int Registration::nextId = INITIAL_REGISTRATION_ID;


Registration::Registration(Student* student, Course* course)
    : regId(nextId++), student(student), course(course) {
}



Student* Registration::getStudent() const {
    return student;
}


bool Registration::lessThan(const Registration& r) const {
    return this->course->lessThan(*(r.course));
}

void Registration::print() const { 
    std::cout << "Registration ID: " << regId << std::endl
              << "Student Name: ";
    student->print(); 
    std::cout << "Course: ";
    course->print(); 
}
