#include "Registrar.h"
#include <iostream>
using namespace std;
//method to check whether the loop should keep going
bool ShouldKeepGoing(Registrar* reg)
{
    //if its not empty return true
    if(!reg->studentQueue->isEmpty())
    {
        return true;
    }
    //if windows are all not empty return true
    if(reg->AreAllWindowsEmpty() == false)
    {
        return true;
    }
    //else return false
    return false;

}
//main method
int main(int argc, char** argv)
{
    //take in the file as a command line arguement
    if(argc <= 1)
    {
        cout << "You didn't enter a file!" << endl;
        return 0;
    }

    string fileName = argv[1];
//delcare time
    int time = 0;
//delcare keepgoing and registrar object
    bool keepGoing = true;
    Registrar* reg = new Registrar();
    //fil the queue and the windows
    reg->FillQueue(fileName);
    reg->FillWindows();
//declare the current size
    int currentSize = reg->studentQueue->getSize();
//while loop
    while(keepGoing)
    {
        //method to clean out windoes
        reg->DepopulateWindows();
        //method to populate all the windows that can be
        reg->PopulateWindows(time);
        //increment the idle windows idle time
        reg->IncrementTimeIdleForAll();
        //increment the time
        ++time;
        //incremenet the wait time variable
        ++reg->waitTimeVariable;
        //ask if we should keep going by calling the method
        keepGoing = ShouldKeepGoing(reg);
        //fo loop to decrement the time busy for all the windows that are taken
        for (int i = 0; i < reg->windowsOpen; ++i)
        {
            if(reg->windows[i].timeBusy != 0)
                reg->windows[i].timeBusy--;
        }
    }
//lastly calculate the stats
    reg -> CalculateStats();
    return 0;
}
