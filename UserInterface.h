//
// Created by cio on 6/5/21.
//

#ifndef COURSEWORK_USERINTERFACE_H
#define COURSEWORK_USERINTERFACE_H

#include <string>
#include "Student.h"
#include "Postgraduate.h"
#include "CyclicList.h"

using namespace std;
class UserInterface {
public:
    [[noreturn]] void startInterface();
    static UserInterface *getUserInterface();
private:
    UserInterface() = default;
    unsigned int validateCourse();
    void getPersonData(string &name, string &surname, unsigned int &age);
    void createStudent();
    void createPostgraduate();
    bool sortElements();
    bool showElements();
    bool makeRequest(unsigned int courseNumber);
    bool deleteByIndex(unsigned int index);
    bool deleteAll();
    bool writeToFile(const string&);
    bool readFromFile(const string &filename);

    static UserInterface *ui;
    CyclicList lst;
};


#endif //COURSEWORK_USERINTERFACE_H
