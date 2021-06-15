
#ifndef COURSEWORK_PERSON_H
#define COURSEWORK_PERSON_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Person {
protected:
    string name;
    string surname;
    unsigned int age;

    // ------------------------------- methods for working with stream
    virtual void osSerialize(ostream &os) const;
    virtual void ofSerialize(ofstream &of) const;
    virtual void ifDeserialize(ifstream &is);

public:
    // ------------------------------- constructor/destructor
    Person();
    Person(const string &, const string &, unsigned int);
    virtual ~Person();

    // ------------------------------- setters
    void setName(const string& name);
    void setSurname(const string& surname);
    void setAge(const unsigned int& age);

    // ------------------------------- getters
    virtual string getType() const;
    string getName() const;
    string getSurname() const;
    unsigned int getAge() const;

    // ------------------------------- operator overloading
    friend ostream& operator<<(ostream& os, const Person* person);
    friend ofstream& operator<<(ofstream& of, const Person& person);
    friend ifstream& operator>>(ifstream& is, Person& person);
};


#endif //COURSEWORK_PERSON_H
