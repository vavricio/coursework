
#include "Postgraduate.h"

// ------------------------------- constructor implementation
Postgraduate::Postgraduate() : Person (), field("default"), adviser("default") {}

Postgraduate::Postgraduate(const string &name, const string &surname, unsigned int age, const string &field,
                           const string &adviser) : Person(name, surname, age), field(field), adviser(adviser){}

// ------------------------------- setters implementation
void Postgraduate::setField(const string &field) {
    this->field = field;
}

void Postgraduate::setAdviser(const string &adviser) {
    this->adviser = adviser;
}

// ------------------------------- getters implementation
string Postgraduate::getField() const {
    return field;
}

string Postgraduate::getAdviser() const {
    return adviser;
}

string Postgraduate::getType() const {
    return "Postgraduate";
}

// ------------------------------- methods for working with stream implementation
void Postgraduate::osSerialize(ostream &os) const {
    Person::osSerialize(os);
    os << "Field of study:" << " " << field << "\n"
       << "Adviser:" << " " << adviser << "\n";
}

void Postgraduate::ofSerialize(ofstream &of) const {
    Person::ofSerialize(of);
    of << field << "\n"
    << adviser << "\n";
}

void Postgraduate::ifDeserialize(ifstream &is) {
    Person::ifDeserialize(is);
    getline(is, field, '\n');
    getline(is, adviser, '\n');
}

