#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include "Student.h"

using namespace std;

class Window
{
public:
//declare variables
    int timeBusy;
    bool isOpen;
    int timeIdle;
//declare methods for window
    Window();
    void addStudentToWindow(Student* s);
    Student* removeStudent();
    Student* currentStudent;
};
#endif
