#ifndef SCHOOL_H
#define SCHOOL_H

#include "StuArray.h"
#include "CourseArray.h"
#include "RegList.h"
#include <string>

class School {
private:
    std::string name;
    StuArray students;
    CourseArray courses;
    RegList registrations;

public:
    
    School(std::string name);
    ~School();

    
    void addStu(Student* s);
    void addCourse(Course* c);
    void addRegistration(Student* s, Course* c);
    Student* findStu(std::string num) const;
    Course* findCourse(int id);
    void printStudents() const;
    void printCourses() const;
    void printCoursesByTerm(std::string term) const;
    void printRegistrations() const;
    void printRegistrationsByStu(std::string studentNum) const;
};

#endif 
