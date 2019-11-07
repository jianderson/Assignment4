#include "Registrar.h"
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;
//registrar constructor to delcare
Registrar::Registrar()
{
    //declare
    pastStudents = new DoublyLinkedList<Student*>();
    windowsOpen = 0;
    arrivalTime = 0;
    numStudents = 0;
    studentQueue = new GenQueue<Student*>();
}
//fill queue method that takes in file
void Registrar::FillQueue(string fileName)
{
    //open file stuff
    bool fileEmpty = false;
    ifstream fileStreamer;
    fileStreamer.open(fileName);
    string line;
    //if the file cannot be opened
    if(!fileStreamer)
    {
        throw runtime_error("The file could not be opened.");
    }
    int lineCount = 0;
    //go through each line
        while(getline(fileStreamer, line))
        {
            //take in the number of open windows
            if(lineCount == 0)
            {
                windowsOpen = stoi(line); //assigns number as integer
            //increase line count
                lineCount++;
                continue;
            }
            //takes in the time
            if(lineCount == 1)
            {
                arrivalTime = stoi(line); // stores it as arrival time
                lineCount++;
                continue;
            }
            if(lineCount == 2) // takes in number of student
            {
                numStudents = stoi(line);//stores it as integer
                lineCount = 1; //set it back up to the top to take in new arrival time

                for(int i = 0; i < numStudents; ++i)
                {
                    //iterate through num students to get each window needed time to create student oject
                    getline(fileStreamer, line);
                    if(fileStreamer.eof())
                    {
                        fileEmpty = true;
                        break;
                    }
                    newStudent = new Student(arrivalTime, stoi(line));
                    //push student objects to the queue
                    studentQueue->insert(newStudent);
                }
                //set numstudents back to 0
                numStudents = 0;
                continue;

            }
            //if num student = 0 then send it back up to arrival time
            if(numStudents == 0)
            {
                lineCount = 1;
            }
//if the file is empty break
            if(fileEmpty == true)
            {
                break;
            }
        }

}
//fill the windows with the correcvt number of window objetcs
void Registrar::FillWindows()
{
    windows = new Window[windowsOpen];
}

//popualte the windows with students//will occur every clock tick
void Registrar::PopulateWindows(int currentTime)
{
    //if there is a window open
    for(int i = 0; i < windowsOpen; ++i)
    {
        if(windows[i].isOpen == true)
        {
            //and if there is still stuff in the queue
            if(!studentQueue->isEmpty())
            {
                //peek the top of the queue
                Student *stu = studentQueue->peek();
                //make sure that the student doesnt leave the queue until after their arrival time
                if(stu->timeArrived <= currentTime)
                {
                    //add student to window and set the wait time
                    Student *thisStudent = studentQueue->remove();

                    thisStudent->setWaitTime(waitTimeVariable - thisStudent->timeArrived);
                    windows[i].addStudentToWindow(thisStudent);
                    // cout << "This is the wait time" << windows[i].currentStudent->waitTime << endl;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

//this method also runs every clock tick
void Registrar::DepopulateWindows()
{
    //for all the open windows
    for(int i = 0; i < windowsOpen; ++i)
    {
        if(windows[i].isOpen == false)
        {
            //if the time busy is not there
            if(windows[i].timeBusy == 0)
            {
                //insert the student into the past students
                pastStudents->insertBack(windows[i].removeStudent());
                //increment past students count
                pastStudentsCount++;
            }
        }
    }
}
//incremement idle window times
void Registrar::IncrementTimeIdleForAll()
{
    //for all the windows
    for(int i = 0; i < windowsOpen; ++i)
    {
        //if the windows are open
        if(windows[i].isOpen == true)
        {
            //increment their idletime
            windows[i].timeIdle += 1;
        }
    }
}
//are all windows empty ( will be using for checking if the while loop should still be going)
bool Registrar::AreAllWindowsEmpty()
{
    bool isItEmpty = true;
    //if the windows are not open
    for(int i = 0; i < windowsOpen; ++i)
    {
        if(windows[i].isOpen == false)
        {
            //it is false
            isItEmpty = false;
        }
    }

    return isItEmpty;
}


//calculate stats
void Registrar::CalculateStats()
{
//create wait times array
   int waitTimesArr[pastStudentsCount];
  //put all wait times in the array
   for(int i = 0; i < pastStudentsCount; ++i)
   {
       waitTimesArr[i] = pastStudents->removeFront()->waitTime;
   }
   //sort wait times
   sort(waitTimesArr, waitTimesArr + pastStudentsCount);
   //find some with for loop
   int waitTimeSum = 0;
   for(int i = 0; i < pastStudentsCount; ++i)
   {
       waitTimeSum += waitTimesArr[i];
   }
   //calculating mean
   meanWait = waitTimeSum / pastStudentsCount;
   //calculating median
   int middle = pastStudentsCount / 2.0;
   if(pastStudentsCount % 2 == 0)
   {
       medianWait = (waitTimesArr[middle] + waitTimesArr[middle + 1]) / 2.0;
   }
   else
   {
       medianWait = waitTimesArr[middle] / 1.0 ;
   }
//longest is just the end
   longestWait = waitTimesArr[pastStudentsCount - 1];
//calculate wait times over 10
   for(int i = 0; i < pastStudentsCount; ++i)
   {
       if(waitTimesArr[i] > 10)
       {
           numStuWaitOver10++;
       }
   }



//for windows idle calculations
   int windowIdleTimesArr[windowsOpen];
   for(int i = 0; i < windowsOpen; ++i)
   {
       windowIdleTimesArr[i] = windows[i].timeIdle;
   }

//sort the window idle
   sort(windowIdleTimesArr, windowIdleTimesArr + windowsOpen);
   //calculate the sum
   int windowSum = 0;

   for(int i = 0; i < windowsOpen; ++i)
   {
       windowSum += windowIdleTimesArr[i];
   }
   //calculate the mean
   meanWindow = windowSum / windowsOpen; // mean
//calculate the longest
   longestWindow = windowIdleTimesArr[windowsOpen - 1];
//calculate all values over 5
   for(int i = 0; i < windowsOpen; ++i)
   {
       if(windowIdleTimesArr[i] > 5)
       {
           numWinIdleOver5++;
       }
   }
   //print out all results
   cout << "The mean student wait time: " << meanWait << endl;
   cout << "The median student wait time: " << medianWait << endl;
   cout << "The longest student wait time: " << longestWait << endl;
   cout << "The number of students waiting over 10 minutes: " << numStuWaitOver10 << endl;
   cout << "The mean window idle time: " << meanWindow << endl;
   cout << "The longest window idle time: " << longestWindow << endl;
   cout << "Number of windows idle for over 5 minutes: " << numWinIdleOver5 << endl;




}
