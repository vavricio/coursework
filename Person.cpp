
#include "Person.h"

// ------------------------------- constructor and destructor implementation
Person::Person() : name("default"), surname("default"), age(0) {}

Person::Person(const string &name, const string &surname, unsigned int age): name(name), surname(surname), age(age) {}

Person::~Person() = default;

// ------------------------------- setters implementation
void Person::setName(const string& name) {
    this->name = name;
}

void Person::setSurname(const string& surname) {
    this->surname = surname;
}

void Person::setAge(const unsigned int& age) {
    this->age = age;
}

// ------------------------------- getters implementation
string Person::getName() const {
    return name;
}

string Person::getSurname() const {
    return surname;
}

unsigned int Person::getAge() const {
    return age;
}

string Person::getType() const {
    return "Person";
}

// ------------------------------- methods for working with stream implementation
void Person::osSerialize(ostream &os) const {
    os << "Identifier:" << " " << getType() << "\n"
       << "Name:" << " " << name << "\n"
       << "Surname:" << " " << surname << "\n"
       << "Age:" << " " << age << "\n";
}

void Person::ofSerialize(ofstream &of) const {
    of << getType() << "\n"
       << name << "\n"
       << surname << "\n"
       << age << "\n";
}

void Person::ifDeserialize(ifstream &is) {
    getline(is, name, '\n');
    getline(is, surname, '\n');
    string stringAge;
    getline(is, stringAge, '\n');
    age = stoul(stringAge);
}

// ------------------------------- operator overloading implementation
ostream &operator<<(ostream &os, const Person *person) {
    person->osSerialize(os);
    return os;
}

ofstream &operator<<(ofstream &of, const Person &person) {
    person.ofSerialize(of);
    return of;
}

ifstream &operator>>(ifstream &is, Person &person) {
    person.ifDeserialize(is);
    return is;
}


