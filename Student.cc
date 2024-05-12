#include <iostream>
using namespace std;
#include <string>

#include "Student.h"

Student::Student(string name, string id, string email) {
    this->studentName = name;
    this->studentID = id;
    this->email = email;
}

bool Student::lessThan(const Student& s) const {
    return this->studentName < s.studentName;
}

void Student::print() const {
    cout << "" << studentName << "  " << studentID << "  " << email << endl;
}

string Student::getStudentID() const {
    return studentID;
}

string Student::getStudentName() const {
    return studentName;
}


string Student::getId() const {
    return studentID;
}

string Student::getName() const {
    return studentName;
}

