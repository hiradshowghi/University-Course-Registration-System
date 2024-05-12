#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
public:
    
    Course(std::string term, std::string subject, std::string code, std::string section, std::string instructor);

    
     int getCourseId() const;
    std::string getTerm() const;
    std::string getFullCourseCode() const; 

    
    bool lessThan(const Course& c) const;
    void print() const;

    
    static int nextId;

private:
    std::string term;
    std::string subject;
    std::string code;
    std::string section;
    std::string instructor;
    int courseId; 
};

#endif 
