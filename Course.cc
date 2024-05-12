#include "Course.h"  
#include <iostream>  


const int INITIAL_COURSE_ID = 1000;  


int Course::nextId = INITIAL_COURSE_ID;


Course::Course(std::string term, std::string subject, std::string code, std::string section, std::string instructor)
    : term(term), subject(subject), code(code), section(section), instructor(instructor), courseId(nextId++) {
    
}


std::string Course::getTerm() const {
    return term;
}

std::string Course::getFullCourseCode() const {
    return subject + " " + code + "-" + section;
}

int Course::getCourseId() const {
    return courseId;
}



bool Course::lessThan(const Course& c) const {
    
    if (term != c.term) return term < c.term;
    if (subject != c.subject) return subject < c.subject;
    if (code != c.code) return code < c.code;
    return section < c.section;
}

void Course::print() const {
    
    std::cout << "" << courseId 
              << " Term: " << term 
              << "" << subject << " " << code << " " << section 
              << " Instructor: " << instructor << std::endl;
}
