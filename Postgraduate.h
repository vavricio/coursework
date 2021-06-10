//
// Created by cio on 6/5/21.
//

#ifndef COURSEWORK_POSTGRADUATE_H
#define COURSEWORK_POSTGRADUATE_H

#include "Person.h"


using namespace std;
class Postgraduate : public Person {
private:
    string field;
    string adviser;
    void osSerialize(ostream &os) const override;
    virtual void ofSerialize(ofstream &of) const override;
    virtual void ifDeserialize(ifstream &is) override;

public:
    Postgraduate();
    Postgraduate(const string &name, const string &surname, unsigned int age, const string &field, const string &adviser);
    ~Postgraduate() = default;

    void setField(const string &field);
    void setAdviser(const string &adviser);

    string getType() const override;
    string getField() const;
    string getAdviser() const;
};


#endif //COURSEWORK_POSTGRADUATE_H
