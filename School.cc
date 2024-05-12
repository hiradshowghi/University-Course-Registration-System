#include "School.h"
#include "RegList.h"
#include <iostream>


School::School(std::string name) : name(name) {}


School::~School() {
    
    registrations.cleanData();
}


void School::addStu(Student* s) {
    students.add(s);
}

void School::addCourse(Course* c) {
    courses.add(c);
}

void School::addRegistration(Student* s, Course* c) {
    Registration* newReg = new Registration(s, c);
    registrations.add(newReg);
}

Student* School::findStu(std::string num) const {
    Student* result = nullptr;
    students.find(num, &result);
    return result;
}

Course* School::findCourse(int id) {
    Course* result = nullptr;
    courses.find(id, &result);
    return result;
}

void School::printStudents() const {
    std::cout << "School: " << name << std::endl;
    students.print();
}

void School::printCourses() const {
    std::cout << "School: " << name << std::endl;
    courses.print();
}

void School::printCoursesByTerm(std::string term) const {
    std::cout << "School: " << name << " Term: " << term << std::endl;
    courses.print(term);
}

void School::printRegistrations() const {
    std::cout << "School: " << name << std::endl;
    registrations.print();
}

void School::printRegistrationsByStu(std::string studentNum) const {
    Student* s = findStu(studentNum);
    if (s) {
        std::cout << "School: " << name << " Student: " << s->getName() << std::endl;
        
        
        
        printRegistrations();  
    } else {
        std::cout << "Student not found." << std::endl;
    }
}



