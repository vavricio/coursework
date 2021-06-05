//
// Created by Cio on 01.06.2021.
//

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
public:
    // ------------------------------- constructor/destructor
    Person();
    Person(string, string, unsigned int);
    ~Person();

    // ------------------------------- setters
    void setName(const string& name);
    void setSurname(const string& surname);
    void setAge(const unsigned int& age);

    // ------------------------------- getters
    string getName() const;
    string getSurname() const;
    unsigned int getAge() const;

    // ------------------------------- getting ID
    virtual string getId() const;

    friend ostream& operator<<(ostream& os, const Person& person);
    friend ofstream& operator<<(ofstream& of, const Person& person);
    virtual void print(ostream &os) const;
    virtual void fromFile(string filename, ifstream &ifs) const;
    virtual void toFile(string filename) const;
};


#endif //COURSEWORK_PERSON_H
