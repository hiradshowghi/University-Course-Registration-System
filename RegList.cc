#include "RegList.h"
#include <iostream>


RegList::RegList() : head(nullptr), tail(nullptr) {}

RegList::RegList(RegList& otherList, Student* stu) : head(nullptr), tail(nullptr) {
    for (Node* curr = otherList.head; curr != nullptr; curr = curr->next) {
        if (curr->data->getStudent() == stu) {
            add(curr->data); 
        }
    }
}


RegList::~RegList() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}


void RegList::add(Registration* r) {
    Node* newNode = new Node(r);
    if (!head || r->lessThan(*(head->data))) {
        newNode->next = head;
        head = newNode;
        if (!tail) tail = head;
    } else {
        Node* curr = head;
        while (curr->next && curr->next->data->lessThan(*r)) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        if (curr == tail) tail = newNode;
    }
}

void RegList::cleanData() {
    Node* current = head;
    while (current != nullptr) {
        delete current->data; 
        current = current->next;
    }
    
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void RegList::print() const {
    Node* current = head;
    while (current != nullptr) {
        current->data->print();
        current = current->next;
    }
    
    if (head) {
        std::cout << "Head: ";
        head->data->print();
    }
    if (tail) {
        std::cout << "Tail: ";
        tail->data->print();
    }
}


