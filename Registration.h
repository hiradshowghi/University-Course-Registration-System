#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Student.h"  
#include "Course.h"

class Registration {
public:
    
    Registration(Student* student, Course* course);

    
    Student* getStudent() const;

    
    bool lessThan(const Registration& r) const;
    void print() const;

    
    static int nextId;

private:
    int regId; 
    Student* student;
    Course* course;
};

#endif 
