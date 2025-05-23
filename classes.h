#pragma once

#include <iostream>
#include <string>
#include "global.h"
//#include "managementsystem.h"
using namespace std;

class Student
{
public:
    string name;
    int studentID;

    Student();
    Student(string, int);
};

class Course
{
public:
    string courseName;
    bool enrolled; // Track if the course is enrolled

    Course();
    Course(string);

};


class Attendance
{
public:
    int studentID;
    string courseName;
    int daysPresent;
    int daysAbsent;

    Attendance();
    Attendance(int, string, int, int);
};



class Marks
{
public:
    int studentID;
    string courseName;
    float marks;

    Marks();
    Marks(int, string, float);

};