//
// Created by cio on 6/5/21.
//

#ifndef COURSEWORK_CYCLICLIST_H
#define COURSEWORK_CYCLICLIST_H

#include <functional>
#include "Person.h"


struct Node {
    Node(Person* value, Node * next);
    ~Node();
    Person* value;
    Node * next;
};

class CyclicList {
public:
    CyclicList();
    unsigned int getSize() const;
    void insert(Person* element);
    bool del(unsigned int index);
    bool deleteAll();
    bool sort();
    bool apply(const std::function<void (Person*)>& fun);
private:
    Node *end;
    unsigned int size;

};


#endif //COURSEWORK_CYCLICLIST_H
