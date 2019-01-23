/*
Dylan Alvarez
Programming Assignment 2
Memory Management/OS Program
*/
#include <iostream>
#include <string>
#include <cstring>
//#include <pa2.h>
#include "pa2.h"

using namespace std;

//Commandline arguments


int main(int argc, char** argv)
{
//Create a linked list called memory that will initially have 32 pages that are "free"

LinkedList *freeMemory = new LinkedList();
LinkedList *usedMemory = new LinkedList();
int size;
string programName;
int programSize;
string analysisAlg;
//creates a pointer to freeMemory

Node *freeHead = new Node("free", 0, 32);
//Initialize the whole list as "free"


//Check to make sure correct amount of parameters, and correct strings for parameters are called before running program
    if(argc >= 3)
    {
       cout << "Too many arguments, please enter either the Best or Worse fit algorithm parameter only" << endl;
       return 0;
    }
    else if(argc == 1)
    {
      cout << "You need an argument that is either Best or Worst to determine which alogorithm to use to allocate memory" << endl;
      return 0;
    }
	if((argc > 1) && (argc < 3))
	{
		analysisAlg = argv[1];
	}


//*******Include tolowercase example later*******
    if(!(analysisAlg == "best") && !(analysisAlg == "worst"))
    {
        cout << "Invalid parameter, please enter best or worst" << endl;
        return 0;
    }

  cout << "Using " << argv[1] << " fit algorithm" << endl;
  int choice = 0;
  bool programActive = true;
  //get valid input
  //Loop the program indefinantly till you want to end the application
  while(programActive)
  { //User input dictates what the programs functionality is
     cout << '\t' <<"1. Add Program" << '\n' << '\t' << "2. Kill Program" << '\n' << '\t' << "3. Fragmentation" << '\n' << '\t' << "4. Print Memory" << '\n' << '\t' << "5. Exit" << endl;
   cin >> choice;
 if(choice < 1 || choice > 5 || int(choice) != choice)
    {
          continue;
    }

      switch(choice)
      {
        case 1:
         //Add program and take away the memory used. Add a memory node into the used memory linked list and take away the required amount of pages/memory to do it
            cout << "choice- " << choice << endl;

            //Check to see which command line arg is there to see which best or worse case analysis is to be used in adding programs.
            if(analysisAlg == "worst")
            {
                //Run worst fit algorithm
		cout << "Program name - ";
		cin >> programName;
		cout << '\n' <<"Program Size (KB) - ";
		cin >> programSize;
//The parameters in my worstFit analysis might be erroneous, im not really sure if these values are equivolent to what i expected to put into it in my header file for the algorithm.
		worstFit(programSize/4, freeMemory->getHeadNodeIndex(), freeMemory->getHeadNodeSize(), programName, freeMemory->getHeadNodeIndex(), programSize/4, freeMemory, usedMemory);
                cout << "Debug: yay we did worst fit" << endl;
            }
            else if(analysisAlg == "best")
            {
             //Run best fit algorithm
		cout << "Program name - ";
		cin >> programName;
		cout << '\n' <<"Program Size (KB) - ";
		cin >> programSize;
//The parameters in my worstFit analysis might be erroneous, im not really sure if these values are equivolent to what i expected to put into it in my header file for the algorithm.
	bestFit(programSize/4, freeMemory->getHeadNodeIndex(),freeMemory->getHeadNodeSize(), programName, freeMemory->getHeadNodeIndex(), programSize/4, freeMemory, usedMemory);
             cout << "Debug: yay we did best fit" << endl;
            }

            break;
        case 2:
            cout << "choice- " << choice << endl;
            //Kill Program and return the memory used. Delete the node where the memory is, and add the free pages back into the free memory list
	cout << "Program Name - ";
	cin >> programName;

	    kill(programName, freeMemory, usedMemory);
            break;

        case 3:
            cout << "choice- " << choice << endl;
            //list amount of Fragmentation, do this by finding a way to count and store the amount of fragments in each list. Then just print it out here
            cout << "There are " << checkFragmentation(freeMemory) << " fragment(s)." << endl;
            break;
        case 4:
            cout << "choice- " << choice << endl;
            //Display Linked List of memory being used and what is free, call the print function of one or both lists?
            printMemory(freeMemory, usedMemory);
            break;
        case 5:
            cout << "choice- " << choice << endl;
            //Exit program
            //programActive = false;
            return 0;
            break;
        default:
            cout << "There is no possible way for a default so this is only called if there is some error";

      }
      //DEBUG UNTIL PROGRAM IS COMPLETE, PREVENTS INFINITE LOOP
      programActive = false;



  }
  return 0;
}


