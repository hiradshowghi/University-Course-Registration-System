#include "CourseArray.h"
#include <iostream>


CourseArray::CourseArray() : numCourses(0) {}


CourseArray::~CourseArray() {
    for (int i = 0; i < numCourses; ++i) {
        delete courses[i]; 
    }
}


void CourseArray::add(Course* course) {
    int i;
    for (i = numCourses - 1; (i >= 0 && courses[i]->lessThan(*course)); --i) {
        courses[i + 1] = courses[i]; 
    }
    courses[i + 1] = course; 
    ++numCourses;
}

bool CourseArray::find(int id, Course** c) {
    for (int i = 0; i < numCourses; ++i) {
        
        if (courses[i]->getCourseId() == id) {
            *c = courses[i];
            return true;
        }
    }
    *c = nullptr; 
    return false;
}

void CourseArray::print() const {
    for (int i = 0; i < numCourses; ++i) {
        courses[i]->print();
    }
}

void CourseArray::print(std::string term) const {
    for (int i = 0; i < numCourses; ++i) {
        if (courses[i]->getTerm() == term) {
            courses[i]->print();
        }
    }
}
