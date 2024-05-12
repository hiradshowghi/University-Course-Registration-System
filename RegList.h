#ifndef REGLIST_H
#define REGLIST_H

#include <functional>
#include "Registration.h"

class RegList {
public:
    
    RegList();
    RegList(RegList& otherList, Student* stu);
    ~RegList();

    
    void add(Registration* r);
    void cleanData();
    void print() const;
        class Node {
    public:
        Registration* data;
        Node* next;
        Node(Registration* reg, Node* nxt = nullptr) : data(reg), next(nxt) {}
    };

    Node* head;
    Node* tail;
};

#endif 
