#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    Student(std::string name, std::string id, std::string email);
    std::string getName() const;
    std::string getId() const;
    bool lessThan(const Student& s) const;
    void print() const;
    std::string getStudentID() const;
    std::string getStudentName() const;

private:
    std::string studentName;
    std::string studentID;
    std::string email; 
};

#endif 

