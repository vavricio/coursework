
#ifndef COURSEWORK_USERINTERFACE_H
#define COURSEWORK_USERINTERFACE_H

#include <string>
#include "Student.h"
#include "Postgraduate.h"
#include "CyclicList.h"

using namespace std;
class UserInterface {
public:
    // ------------------------------- Start UI method
    [[noreturn]] void startInterface();

    // ------------------------------- Singleton
    static UserInterface *getUserInterface();
private:

    // ------------------------------- constructor
    UserInterface() = default;

    // ------------------------------- Method fow validation course
    unsigned int validateCourse();

    // ------------------------------- Methods for creating elements
    void getPersonData(string &name, string &surname, unsigned int &age);
    void createStudent();
    void createPostgraduate();

    // ------------------------------- Methods for working with list
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
