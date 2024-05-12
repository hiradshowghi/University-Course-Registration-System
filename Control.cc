#include <iostream>
using namespace std;
#include <string>

#include "Control.h"


Control::Control() {
    school = new School("CS"); 
}


Control::~Control() {
    delete school;
}


void Control::launch() {
    int choice;
    std::string studentNum, term;
    int courseId;
    Student* student = nullptr;
    Course* course = nullptr;

    
    
    initStudents(school);
    initCourses(school);

    while (true) {
        view.showAdminMenu(choice);  

        switch(choice) {
            case 0:  
                return;
            case 1:  
                cout << "Students of Carleton University ";
                school->printStudents();
                break;
            case 2:  
                cout << "Courses at Carleton University ";
                school->printCourses();
                break;
            case 3:  
                cout << "Registrations of Carleton University ";
                school->printRegistrations();
                break;
            case 4:  
                view.readStr(studentNum);  
                student = school->findStu(studentNum);
                while (!student) {
                    view.printError("Invalid student number.");  
                    view.readStr(studentNum);  
                    student = school->findStu(studentNum);
                }
                
                int studentChoice;
                do {
                    
                    string studentName = student->getName(); 
                    view.showStudentMenu(studentName, studentChoice);  
                    switch(studentChoice) {
                        case 1:  
                            view.readStr(term);
                            school->printCoursesByTerm(term);
                            break;
                        case 2:  
                            school->printRegistrationsByStu(studentNum);
                            break;
                        case 3:  
                            view.readInt(courseId);
                            course = school->findCourse(courseId);
                            if (course) {
                                school->addRegistration(student, course);
                            } else {
                                view.printError("Invalid course ID.");
                            }
                            break;
                        default:
                            if (studentChoice != 0) {  
                                view.printError("Invalid choice.");
                            }
                            break;
                    }
                } while (studentChoice != 0);  
                break;
            default:
                view.printError("Invalid choice.");
                break;
        }
    }
}



void Control::initStudents(School* sch)
{
  sch->addStu(new Student("100567888", "Matilda", "CS"));
  sch->addStu(new Student("100333444", "Harold", "Geography"));
  sch->addStu(new Student("100444555", "Joe", "Physics"));
  sch->addStu(new Student("100775588", "Timmy", "CS"));
  sch->addStu(new Student("100111222", "Amy", "Math"));
  sch->addStu(new Student("100222333", "Stanley", "Art History"));
}

void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", "2401", "A", "Laurendeau"));
  sch->addCourse(new Course("F23", "COMP", "2401", "B", "Hillen"));
  sch->addCourse(new Course("F23", "COMP", "2401", "C", "Laurendeau"));
  sch->addCourse(new Course("F23", "COMP", "2401", "D", "Hillen"));
  sch->addCourse(new Course("F23", "COMP", "2402", "A", "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", "2402", "B", "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", "2404", "A", "Hill"));
  sch->addCourse(new Course("F23", "COMP", "2404", "B", "Hill"));
  sch->addCourse(new Course("F23", "COMP", "2406", "A", "Nel"));
  sch->addCourse(new Course("F23", "COMP", "2406", "B", "Shaikhet"));
  sch->addCourse(new Course("F23", "COMP", "2804", "A", "Morin"));
  sch->addCourse(new Course("F23", "COMP", "2804", "B", "Hill"));

  sch->addCourse(new Course("W24", "COMP", "2401", "A", "CI"));
  sch->addCourse(new Course("W24", "COMP", "2401", "B", "Lanthier"));
  sch->addCourse(new Course("W24", "COMP", "2402", "A", "Sharp"));
  sch->addCourse(new Course("W24", "COMP", "2402", "B", "Sharp"));
  sch->addCourse(new Course("W24", "COMP", "2404", "A", "Hill"));
  sch->addCourse(new Course("W24", "COMP", "2404", "B", "Laurendeau"));
  sch->addCourse(new Course("W24", "COMP", "2404", "C", "Laurendeau"));
  sch->addCourse(new Course("W24", "COMP", "2406", "A", "Nel"));
  sch->addCourse(new Course("W24", "COMP", "2406", "B", "Nel"));
  sch->addCourse(new Course("W24", "COMP", "2804", "A", "Hill"));
  sch->addCourse(new Course("W24", "COMP", "2804", "B", "Hill"));
}


