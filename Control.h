#ifndef CONTROL_H
#define CONTROL_H

#include "School.h"
#include "View.h"

class Control {
private:
    School* school;
    View view;

public:
    Control();
    ~Control();
    void launch();
    void initStudents(School* sch);  
    void initCourses(School* sch);
};

#endif 

