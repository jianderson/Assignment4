#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "GenQueue.h"

using namespace std;

class Student
{
public:
    //initilize methods
    Student();
    Student(int tA, int winT);
    void setWaitTime(int wait);
//initialize variables
    int timeArrived;
    int waitTime;
    int windowTime;

};
#endif
