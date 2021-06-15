cmake_minimum_required(VERSION 3.19)
project(courseWork)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Person.cpp
        Person.h
        Student.cpp
        Student.h
        UserInterface.cpp
        UserInterface.h
        CyclicList.cpp
        CyclicList.h
        Postgraduate.cpp
        Postgraduate.h)


add_executable(courseWork ${SOURCE_FILES} main.cpp)

#find_package(Boost COMPONENTS REQUIRED unit_test_framework)
#
#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#    add_executable(course_work_test ${SOURCE_FILES} Test.cpp)
#    target_link_libraries(course_work_test ${Boost_LIBRARIES})
#endif()
