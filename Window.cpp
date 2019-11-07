
#include <iostream>
#include "Window.h"

using namespace std;
//window constructor to initialize
Window::Window()
{
    timeIdle = 0;
    timeBusy = 0;
    currentStudent = NULL;
    isOpen = true;

}
//add a student from the queue to the window
void Window::addStudentToWindow(Student* s)
{
    currentStudent = s;
    isOpen = false;
    timeBusy = s->windowTime;
}
//remove a strudent
Student* Window::removeStudent()
{
    isOpen = true;
    Student* thisStudent = currentStudent;
    currentStudent = NULL;
    return thisStudent;
}
