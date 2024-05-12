#ifndef STUARRAY_H
#define STUARRAY_H

#include "Student.h"
#include <string>

class StuArray {
public:
    
    StuArray();
    ~StuArray();

    
    void add(Student* student);
    bool find(std::string num, Student** stu) const;
    void print() const;

private:
    static const int MAX_STUDENTS = 100; 
    Student* students[MAX_STUDENTS];
    int numStudents; 
};

#endif 
