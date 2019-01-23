#include <iostream>
#include "pa2.h"
using namespace std;

//============================================================================
// Name        : pa2.cpp
// Author      : Johnny Li
// Description : A program that emulate the operating system’s responsibility of allocating
//memory to certain programs. This is very simple page-based view of memory
//management. On startup, your program will have some 32 pages of contiguous, unused
//memory. Each page will be 4 KB long.
//============================================================================


int main(int argc,char**argv) {
	// Takes command line arguments
	string type = argv[1];
	// Creates a new Linked List object and initializes it.
	LinkedList LinkedList;
	int sizeT=0; //Total sizes of all programs.
	int num; //Size of remove program.
	int num2;//Size of added program.
	//Pick an algorithm to allocate the memory in the OS.
	int fit = LinkedList.fitChoice(type);
	//Exit program if invalid algorithm.
	if(fit == 2){
		exit(0);
	}

	//Linked List object initialized to have 32 nodes that store "Free".
	for (int i = 0; i < 31; i++){
		LinkedList.addNode("Free");
	    }

	//Declare value
	int selection = 0; //Store selection choice.
	string name; //Store program name.
	int size; //Store Program size.

	//Selection Menu
	while (selection != 5){
		cout << endl << " 1. Add program\n 2. Kill program\n 3. Fragmentation\n 4. Print memory\n 5. Exit\n" << endl;
		cin >> selection;
		//Check user input
		 selection =LinkedList.input( selection);
		cout << "choice - "<< selection << endl;
			switch (selection){
			//1. Add program
			case(1) :
				cout << "Program name - ";
				cin >> name;
				cout << "Program size (KB) - ";
				//Loop till valid user input.
				cin >> size;
				size =LinkedList.input(size);
				//Size of program
				if (size%4 == 0){
					num2 = (size/4)*4;
				}
				else{
					num2= (size/4 + 1)*4;
				}
				//Check if not enough memory.
				sizeT=sizeT+num2;
				if(128<sizeT){
					cout<< "Error, Not enough memory for Program " << name << endl;
					sizeT=sizeT-size;
				}
				//Best fit algorithm.
				else if(fit==1){
					LinkedList.bestFit(name, size);
				}
				//Worst fit algorithm.
				else if(fit==0){
					LinkedList.worstFit(name, size);
				}
				break;
			//2. Kill program
			case(2) :
				cout << "Program name - ";
				cin >> name;
				num=LinkedList.remove(name);
				sizeT=sizeT-num;
				break;
			//3. Fragmentation
			case(3) :
				LinkedList.fragments();
				break;
			//4. Print memory
			case(4) :
				LinkedList.print();
				break;
			//5. Exit
			case(5) :
				exit(0);
				break;
			//Invalid input.
			default:
				cout << "Invalid choice. Please try again." << endl;
			}
	}
	return 0;
}
