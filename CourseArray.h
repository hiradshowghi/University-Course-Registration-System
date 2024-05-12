#ifndef COURSEARRAY_H
#define COURSEARRAY_H

#include "Course.h"
#include <string>

class CourseArray {
public:
    
    CourseArray();
    ~CourseArray();

    
    void add(Course* course);
    bool find(int id, Course** c);
    void print() const;
    void print(std::string term) const;

private:
    static const int MAX_COURSES = 100; 
    Course* courses[MAX_COURSES];
    int numCourses; 
};

#endif 
