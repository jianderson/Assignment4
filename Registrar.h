#include "Window.h"
#include <iostream>

using namespace std;

class Registrar
{
public:
    //methods for the registrar
    Registrar();
    //fill the queue with students
    void FillQueue(string fileName);
    //fill the windows
    void FillWindows();
    //populater the windows with students
    void PopulateWindows(int currentTime);
    //depopulate all the windows that are empty
    void DepopulateWindows();
    //increment the idlt time for the windows
    void IncrementTimeIdleForAll();
    //check if all windows are empty
    bool AreAllWindowsEmpty();
    //calculate the Stats
    void CalculateStats();
    //wait time variable that will keep track of the wait time
    int waitTimeVariable;
    //past students in linked list
    DoublyLinkedList<Student*>* pastStudents;

//create your student Queue
    GenQueue<Student*> *studentQueue;
    //create the new student
    Student* newStudent;
    //create the windows variable
    Window* windows;
    //create a variable to hold the number of past students
    int pastStudentsCount = 0;
    //int windows open variable
    int windowsOpen;

//variables for stat calcs
    double meanWait;
    double medianWait;
    int longestWait;
    int numStuWaitOver10;

    double meanWindow;
    int longestWindow;
    int numWinIdleOver5;


private:
//declare the few private variables
    unsigned int arrivalTime;
    int numStudents;
    Window* newWindow;

};
