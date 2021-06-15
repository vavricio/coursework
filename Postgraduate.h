
#ifndef COURSEWORK_POSTGRADUATE_H
#define COURSEWORK_POSTGRADUATE_H

#include "Person.h"


using namespace std;
class Postgraduate : public Person {
private:
    string field;
    string adviser;

    // ------------------------------- methods for working with stream
    void osSerialize(ostream &os) const override;
    void ofSerialize(ofstream &of) const override;
    void ifDeserialize(ifstream &is) override;

public:
    // ------------------------------- constructor/destructor
    Postgraduate();
    Postgraduate(const string &name, const string &surname, unsigned int age, const string &field, const string &adviser);
    ~Postgraduate() override = default;

    // ------------------------------- setters
    void setField(const string &field);
    void setAdviser(const string &adviser);

    // ------------------------------- getters
    string getType() const override;
    string getField() const;
    string getAdviser() const;
};


#endif //COURSEWORK_POSTGRADUATE_H
