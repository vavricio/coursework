//
// Created by cio on 6/5/21.
//

#include "UserInterface.h"
#include <iostream>
#include <limits>


using namespace std;

const unsigned int maxCommandNumber = 9;
const unsigned int maxAge = 200;
const unsigned int maxCourse = 6;

UserInterface* UserInterface::ui = nullptr;

[[noreturn]] void UserInterface::startInterface() {
    while (true){
        //system("cls");

        cout << "Enter command: \n"
        << "\tAvailable commands:\n"
        << "\t\t0. Create Student\n"
        << "\t\t1. Create Postgraduate\n"
        << "\t\t2. Show elements\n"
        << "\t\t3. Sort elements\n"
        << "\t\t4. Make request\n"
        << "\t\t5. Delete by index\n"
        << "\t\t6. Delete all elements\n"
        << "\t\t7. Read from file\n"
        << "\t\t8. Save to file\n"
        << "\t\t9. Quit\n"
        << endl;

        string commandNumberString;
        cin >> commandNumberString;
        unsigned int commandNumber;
        try {
            commandNumber = stoul(commandNumberString);
            if(commandNumber > maxCommandNumber) {
                throw invalid_argument("Command number too big");
            }
            
        } catch (invalid_argument &e) {
            cout << "Enter valid command number!" << endl;
            continue;
        }

        switch (commandNumber) {
            case 0:
                cout << "Creating student" << endl;
                createStudent();
                //system("pause");
                break;
            case 1:
                cout << "Creating postgraduate" << endl;
                createPostgraduate();
                //system("pause");
                break;
            case 2:
                cout << "Showing elements" << endl;
                showElements();
                //system("pause");
                break;
            case 3:
                cout << "Sorting elements" << endl;
                sortElements();
                //system("pause");
                break;
            case 4:
            {
                cout << "Make request" << endl;
                unsigned int courseNumber = validateCourse();
                makeRequest(courseNumber);
                //system("pause");
                break;
            }
            case 5:
                cout << "Deleting by index" << endl;
                unsigned int index;
                cout << "Enter index for deleting:";
                cin >> index;
                cout << endl;

                while(true){
                    if(!cin.fail())
                        break;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Wrong input, enter correct index" << endl;
                    cin >> index;
                }
                deleteByIndex(index);
                //system("pause");
                break;
            case 6:
                cout << "Deleting all" << endl;
                deleteAll();
                //system("pause");
                break;
            case 7:
                cout << "Reading from file..." << endl;
                readFromFile("courseWork.txt");
                //system("pause");
                break;
            case 8:
                cout << "Saving to file..." << endl;
                writeToFile("courseWork.txt");
                //system("pause");
                break;
            case 9:
                cout << "Quiting" << endl;
                exit(0);
            default:
                cout << "Enter valid command number!" << endl;
                continue;
        }
    }
}

UserInterface *UserInterface::getUserInterface() {
    if (ui == nullptr){
        ui = new UserInterface();
    }
    return ui;
}

unsigned int UserInterface::validateCourse() {
    unsigned int courseNumber;
    string courseString;

    while (true) {
        cout << "Enter course:";
        cin >> courseString;
        try {
            courseNumber = stoul(courseString);
            if (courseNumber > maxCourse || courseNumber == 0){
                throw invalid_argument("Invalid course");
            }
            break;
        } catch (invalid_argument &e) {
            cout << "Enter valid course!" << endl;
            continue;
        }
    }
    return courseNumber;
}

void UserInterface::getPersonData(string &name, string &surname, unsigned int &age) {
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter surname: ";
    cin >> surname;

    string ageString;
    while (true) {
        cout << "Enter age:";
        cin >> ageString;

        try {
            age = stoul(ageString);
            if (age > maxAge || age == 0) {
                throw invalid_argument("Age is below zero");
            }
            break;
        } catch (invalid_argument &e) {
            cout << "Enter valid age!" << endl;
            continue;
        }
    }
}

void UserInterface::createStudent() {
    string name, surname, university, faculty;
    unsigned int age, course;

    cout << "Enter information about student" << endl;
    getPersonData(name, surname, age);

    course = validateCourse();

    cout << "Enter university: ";
    cin >> university;

    cout << "Enter faculty: ";
    cin >> faculty;

    Student *student = new Student(name, surname, age, course, university, faculty);
    lst.insert(student);
}

void UserInterface::createPostgraduate() {
    string name, surname, field, adviser;
    unsigned int age;

    cout << "Enter information about postgraduate" << endl;
    getPersonData(name, surname, age);

    cout << "Enter field of study: ";
    cin >> field;

    cout << "Enter name of adviser: ";
    cin >> adviser;

    Postgraduate *postgraduate = new Postgraduate(name, surname, age, field, adviser);
    lst.insert(postgraduate);
}

bool UserInterface::showElements() {
    bool conclusion;
    conclusion = lst.apply([](Person *person){
        cout << person;
    });
    if (conclusion == false){
        cout << "There is nothing to show" << endl;
    }
    return conclusion;
}

// -------------------------------------------------------

bool UserInterface::makeRequest(unsigned int courseNumber) {
    bool conclusion;
    conclusion = lst.apply([courseNumber](Person* person){
        if(person->getType() == "Student"){
            Student *student = dynamic_cast<Student*>(person);
            if(student->getCourse() == courseNumber) {
                cout << "Surname:"<< student->getSurname() << "\n";
            }
        }
    });
    if (conclusion == false){
        cout << "There is no students on this course" << endl;
    }

    return conclusion;
}

bool UserInterface::deleteByIndex(unsigned int index) {
    bool conclusion;
    conclusion = lst.del(index);
    return conclusion;
}

bool UserInterface::deleteAll() {
    bool conclusion;
    conclusion = lst.deleteAll();
    return conclusion;
}

bool UserInterface::sortElements() {
    bool conclusion;
    conclusion = lst.sort();
    return conclusion;
}

bool UserInterface::writeToFile(const string &filename) {
    bool conclusion;
    ofstream of;
    of.open(filename);

    if (!of.is_open()){
        conclusion = false;
        cout << "Error opening file" << endl;
        return conclusion;
    }

   conclusion = lst.apply([&of](Person* person){
        of << person;
    });
    of.close();
    return conclusion;
}

bool UserInterface::readFromFile(const string& filename) {
    ifstream ifs;
    ifs.open(filename);

    if (!ifs.is_open()){
        cout << "Error opening file" << endl;
        return false;
    }

    if (ifs.peek() == EOF){
        cout << "File is empty";
        return false;
    }

    string type;

    while (ifs.peek() != EOF){
        getline(ifs, type, '\n');

        if (type == "Student"){
            Student *student = new Student();
            ifs >> *student;
        } else if (type == "Postgraduate"){
            Postgraduate *postgraduate = new Postgraduate();
            ifs >> *postgraduate;
        }
    }
    ifs.close();
    return true;
}




