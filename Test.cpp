#define BOOST_TEST_MODULE mytests
#define BOOST_TEST_MAIN

#include "CyclicList.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(testStudentMethods)

    BOOST_AUTO_TEST_CASE(methodsStudent){
        Student *testStudent = new Student();

        testStudent->setName("Anna");
        BOOST_TEST(testStudent->getName() == "Anna");

        testStudent->setSurname("Vavryk");
        BOOST_TEST(testStudent->getSurname() == "Vavryk");

        testStudent->setAge(19);
        BOOST_TEST(testStudent->getAge() == 19);

        testStudent->setCourse(2);
        BOOST_TEST(testStudent->getCourse() == 2);

        testStudent->setUniversity("KPI");
        BOOST_TEST(testStudent->getUniversity() == "KPI");

        testStudent->setFaculty("FBME");
        BOOST_TEST(testStudent->getFaculty() == "FBME");

        delete testStudent;
    }


    BOOST_AUTO_TEST_SUITE(testPostgraduateMethods)

    BOOST_AUTO_TEST_CASE(methodsStudent){
        Postgraduate *testPostgraduate = new Postgraduate();

        testPostgraduate->setName("Ivan");
        BOOST_TEST(testPostgraduate->getName() == "Ivan");

        testPostgraduate->setSurname("Serov");
        BOOST_TEST(testPostgraduate->getSurname() == "Serov");

        testPostgraduate->setAge(24);
        BOOST_TEST(testPostgraduate->getAge() == 24);

        testPostgraduate->setField("Math");
        BOOST_TEST(testPostgraduate->getField() == "Math");

        testPostgraduate->setAdviser("Nastenko");
        BOOST_TEST(testPostgraduate->getAdviser() == "Nastenko");

        delete testPostgraduate;
    }

    BOOST_AUTO_TEST_CASE(testInsert){

}


BOOST_AUTO_TEST_SUITE_END()