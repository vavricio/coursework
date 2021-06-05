//
// Created by Cio on 01.06.2021.
//

#include "Person.h"

Person::Person() : name(""), surname(""), age(0) {}

Person::Person(string name, string surname, unsigned int age): name(name), surname(surname), age(age) {}

Person::~Person() = default;

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setSurname(const string& surname) {
    this->surname = surname;
}

void Person::setAge(const unsigned int& age) {
    this->age = age;
}

string Person::getName() const {
    return name;
}

string Person::getSurname() const {
    return surname;
}

unsigned int Person::getAge() const {
    return age;
}

string Person::getId() const {
    return "Person";
}

void Person::print(ostream &os) const {
    os << "Identifier:" << " " << getId() << "\n"
       << "Name:" << " " << name << "\n"
       << "Surname:" << " " << surname << "\n"
       << "Age:" << " " << age << "\n";
}

void Person::fromFile(string filename, ifstream &ifs) const {
    ifstream fin;
    fin.open(filename);
    if (!fin){
        cout << "Error opening file.\n";
    } else {
        
    }
}

ostream &operator<<(ostream &os, const Person &person) {
    person.print(os);
    return os;
}

ofstream &operator<<(ofstream &of, const Person &person) {
    of << person.getId() << ","
       <<person.name << ","
       <<person.surname << ","
       <<person.age << ",";
    return of;
}

