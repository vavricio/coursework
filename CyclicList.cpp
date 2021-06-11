//
// Created by cio on 6/5/21.
//

#include "CyclicList.h"

Node::Node(Person *value_, Node *next_) : value(value_), next(next_){}

Node::~Node() {
    delete value;
}

CyclicList::CyclicList() : end(nullptr), size(0) {}

CyclicList::~CyclicList() {
    deleteAll();
}

unsigned int CyclicList::getSize() const {
    return size;
}

void CyclicList::insert(Person* element) {
    this->size++;
    if(end == nullptr) {
        Node* newNode = new Node(element, nullptr);
        end = newNode;
        newNode->next = newNode;
        return;
    }
    Node *currentNode = end->next;

    while (currentNode != end) {
        currentNode = currentNode->next;
    }

    Node* newNode = new Node(element, end->next);
    currentNode->next = newNode;
    end = newNode;
}

bool CyclicList::del(uint index) {
    if(end == nullptr){
        cout << "List is empty" << endl;
        return false;
    }

    if(index >= size){
        cout << "Wrong index";
        return false;
    }

    if(size == 1) {
        cout << "Surname of deleted object:" << end->value->getSurname() << endl;
        delete end;
        end = nullptr;
        size--;
        return true;
    }

    if(index == 0) {
        Node *oldStartNode = end->next;

        end->next = oldStartNode->next;

        cout << "Surname of deleted object:" << oldStartNode->value->getSurname() << endl;
        delete oldStartNode;
        this->size--;
        return true;
    }

    Node* currentNode = end->next;

    // визначаємо вузол що передує видаляємому
    for (int i = 0; i < index - 1; ++i) {
        currentNode = currentNode->next;
    }
    // вузол після видаляємого
    Node* tempRef = currentNode->next->next;

    cout << "Surname of deleted object:" << currentNode->next->value->getSurname() << endl;
    delete currentNode->next;
    currentNode->next = tempRef;
    this->size--;
    return true;
}


bool CyclicList::deleteAll() {
    if(end == nullptr){
        cout << "List is empty" << endl;
        return false;
    }

    if(this->size == 1){
        delete end;
        end = nullptr;
        cout << "List was cleared" << endl;
        return true;
    }

    Node* currentNode = end;
    Node* nextNode = currentNode->next;

    do {
        delete currentNode;
        currentNode = nextNode;
        nextNode = currentNode->next;
    } while (currentNode != end);

    end = nullptr;
    size = 0;

    cout << "List was cleared" << endl;
    return true;
}

bool CyclicList::apply(const std::function<void (Person*)>& fun) {
    if(end == nullptr)
        return false;

    Node* currentNode = end->next;
    do  {
        fun(currentNode->value);
        currentNode = currentNode->next;
    } while (currentNode != end->next);
    return true;
}

bool CyclicList::sort() {
    if(size <= 1)
        return false;

    for(int i = 0; i < size; ++i) {
        Node *currentNode = end->next;
        Node *preNode = end;
        Node *nextNode = currentNode->next;
        for(int j = 0; j < size-i-1; ++j) {
            if(nextNode->value->getSurname() < currentNode->value->getSurname()) {
                preNode->next = nextNode;
                Node *tempRef = nextNode->next;
                nextNode->next = currentNode;
                currentNode->next = tempRef;
                if(nextNode == end)
                    end = currentNode;
                currentNode = nextNode;

            }
            preNode =currentNode;
            currentNode = currentNode->next;
            nextNode = currentNode->next;
        }
    }
    return true;
}
