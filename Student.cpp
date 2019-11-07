
#include <iostream>
#include "Student.h"

using namespace std;
//student constructor to initialize
Student::Student()
{
    timeArrived = 0;
    windowTime = 0;
    waitTime = 0;
}

//overloaded constructor to initialize
Student::Student(int tA, int winT)
{
    timeArrived = tA;
    windowTime = winT;
    waitTime = 0;
}
//method to set the wait time equal to the param
void Student::setWaitTime(int wait)
{
    waitTime = wait;
}
