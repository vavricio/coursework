//
// Created by cio on 6/5/21.
//

#include "Student.h"


Student::Student() : Person(), course(0), university("default"), faculty("default") {}

Student::Student(const string &name, const string &surname, unsigned int age, unsigned int course, const string &university, const string &faculty)
    : Person(name, surname, age), course(course), university(university), faculty(faculty) {}

void Student::setCourse(unsigned int course) {
    this->course = course;
}

void Student::setUniversity(const string &university) {
    this->university = university;
}

void Student::setFaculty(const string &faculty) {
    this->faculty = faculty;
}

unsigned int Student::getCourse() const {
    return course;
}

string Student::getUniversity() const {
    return university;
}

string Student::getFaculty() const {
    return faculty;
}

void Student::osSerialize(ostream &os) const {
    Person::osSerialize(os);
    os << "Course:" << " " << course << "\n"
    << "University:" << " " << university << "\n"
    << "Faculty:" << " " << faculty << "\n";
}

string Student::getType() const {
    return "Student";
}

void Student::ofSerialize(ofstream &of) const {
    Person::ofSerialize(of);
    of << course << "\n"
    << university << "\n"
    << faculty << "\n";
}

void Student::ifDeserialize(ifstream &is) {
    Person::ifDeserialize(is);
    string stringCourse;
    getline(is, stringCourse, '\n');
    course = stoul(stringCourse);
    getline(is, university, '\n');
    getline(is, faculty, '\n');
}



