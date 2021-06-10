//
// Created by cio on 6/5/21.
//

#ifndef COURSEWORK_STUDENT_H
#define COURSEWORK_STUDENT_H

#include "Person.h"

using namespace std;
class Student : public Person{
private:
    unsigned int course;
    string university;
    string faculty;

    void osSerialize(ostream &os) const override;
    virtual void ofSerialize(ofstream &of) const override;
    virtual void ifDeserialize(ifstream &is) override;

public:
    Student();
    Student(const string &name, const string &surname, unsigned int age, unsigned int course, const string &university, const string &faculty);
    ~Student() = default;

    void setCourse(unsigned int course);
    void setUniversity(const string &university);
    void setFaculty(const string &faculty);

    string getType() const override;
    unsigned int getCourse() const;
    string getUniversity() const;
    string getFaculty() const;

};


#endif //COURSEWORK_STUDENT_H
