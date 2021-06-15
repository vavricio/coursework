
#ifndef COURSEWORK_CYCLICLIST_H
#define COURSEWORK_CYCLICLIST_H

#include <functional>
#include "Person.h"


struct Node {
    // ------------------------------- Node constructor/destructor
    Node(Person* value, Node * next);
    ~Node();

    Person* value;
    Node * next;
};

class CyclicList {
public:
    // ------------------------------- constructor/destructor
    CyclicList();
    ~CyclicList();

    // ------------------------------- List methods
    unsigned int getSize() const;
    void insert(Person* element);
    bool del(unsigned int index);
    bool deleteAll();
    bool sort();

    // ------------------------------- Method apply with lambda function
    bool apply(const std::function<void (Person*)>& fun);
private:
    Node *end;
    unsigned int size;

};


#endif //COURSEWORK_CYCLICLIST_H
