#define BOOST_TEST_MODULE mytests
#define BOOST_TEST_MAIN

#include "CyclicList.h"
#include "Postgraduate.h"
#include "Student.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_SUITE(unitTests)

    BOOST_AUTO_TEST_CASE(methodsStudent) {
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


    BOOST_AUTO_TEST_CASE(methodsPostgraduate) {
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

    BOOST_AUTO_TEST_CASE(testInsert) {
        CyclicList lst;
        BOOST_TEST(lst.getSize() == 0);

        Student* student = new Student();
        lst.insert(student);

        BOOST_TEST(lst.getSize() == 1);

        Postgraduate* postgraduate = new Postgraduate();
        lst.insert(postgraduate);

        BOOST_TEST(lst.getSize() == 2);
    }

    BOOST_AUTO_TEST_CASE(testDelByIndex) {
        CyclicList lst;
        Student* student1 = new Student();
        Student* student2 = new Student();
        Postgraduate* postgraduate = new Postgraduate();

        lst.insert(student1);
        lst.insert(student2);
        lst.insert(postgraduate);

        BOOST_TEST(lst.getSize() == 3);

        bool conclusion = lst.del(1);
        BOOST_TEST(conclusion == true);
        BOOST_TEST(lst.getSize() == 2);
}

    BOOST_AUTO_TEST_CASE(testDeleteAll) {
        CyclicList lst;
        Student* student1 = new Student();
        Student* student2 = new Student();
        Postgraduate* postgraduate = new Postgraduate();

        lst.insert(student1);
        lst.insert(student2);
        lst.insert(postgraduate);

        BOOST_TEST(lst.getSize() == 3);

        lst.deleteAll();
        BOOST_TEST(lst.getSize() == 0);
}

    BOOST_AUTO_TEST_CASE(testSort) {
        CyclicList lst;
        Student* student = new Student("Anna", "Vavryk", 19, 2, "KPI", "FBME");
        Postgraduate* postgraduate = new Postgraduate("Ivan", "Serov", 22, "Math", "Nastenko");
        lst.insert(student);
        lst.insert(postgraduate);

        bool conclusion = lst.sort();
        BOOST_TEST(conclusion == true);
}

BOOST_AUTO_TEST_SUITE_END()