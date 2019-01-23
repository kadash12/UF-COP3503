#ifndef pa2_H
#define pa2_H
#include <string>
#include <climits>


using namespace std;
/*Name: pa2.h
 *	Summary: Fuction of each selction and organizes the memory of the OS.
 *  Author: Johnny Li
 *  COP 3503 Section Number: 128D
 */


/*
 * Node class - create Node object.
 * Taken from COP3503 Lab 3 powerpoint.
 * @param: Name of the program.
 */
class Node{
	public:
	Node* next;
	string data;
	Node(string name){
		data=name;
		next=NULL;
	}
};

/*
 * This class contain components that manages the memory of the OS.
 * LinkedList class - creates link list.
 */
class LinkedList{
	Node* head=NULL;
	Node* curr=NULL;
	Node* temp=NULL;
public:
	// The constructor for initializing the functions.
	int fitChoice(string type); //Pick an algorithm to allocate the memory in the OS.
	int input(int input); //Check if the input is a character.
	void print(); //Print Link list.
	void bestFit(string name, int size);	//Add program, best fit algorithm.
	void worstFit(string name, int size); //Add program, worst fit algorithm.
	int remove(string name); //Remove program
	void fragments();

	LinkedList( ){
		head=NULL;
		curr=NULL;
		temp=NULL;
		}
	/*
	 * Creates a new Linked List object and initializes it to have 32 nodes that store "Free".
	 * Taken from COP3503 Lab 3 powerpoint.
	 */
	void addNode(string name) {
		if (head == NULL) {
			head = new Node(name);
		}
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new Node(name);
	}
};
/*
 * Add program, best fit algorithm.
 * @param: Program name and program size.
 */
void LinkedList::bestFit(string name, int size){
	curr = head;
	int page;
	int test =1; //Test case for error.
	int test2 =0;	//Test case for start of link index.
	int test4=0; //Test case for leftover index.
	int count=32; //Fragment number
	int test3 = 1; //Test case for free.
	int start=0; //Start location of the largest fragment.

	//Number of pages being used by the program.
	if (size%4 == 0){
		page = size/4;
	}
	else{
		page = size/4 + 1;
	}
	//Loop till end.
	for(int t=0;t<32;t++){
		// If the program already exists, return error.
		if (curr->data == name){
			cout << "Error, Program " << name << " already running." << endl;
			test3 =0;
			break;
		}
		//Look for largest fragment.
		if(test3 ==1){
		// Loops until the end of the list
			if (curr != NULL){
				// Checks to see if free.
				if (curr->data == "Free" && test){
					test = false;
					curr = curr->next;
					test4++;
					test2=t+1;
				}
				// Move on to the next node if still free.
				else if (curr->data == "Free" && test == false){
					curr = curr->next;
					test4++;
				}
				// If not free, reset.
				else{
					test4=0;//Reset counter
					test = true;
					curr = curr->next;
				}
				if(test4>=page){
					if (count>test4){
					count=test4;
					start=test2;
					}
				}
			}
		}
	}
	//Pass through the links.
	curr = head;
	for(int j=1; j<=32;j++){
		//Look for free links and store input program.
		if((j>=start)&&(j<start+page)){
			if (curr->data == "Free"){
					curr->data = name;
			}
		}
		curr = curr->next;
	}
	// The algorithm is successful or not enough memory.
	if (test3 !=0){
		cout<< "Program " << name << " added successfully, " << page << " page(s) used." << endl;
	}
}
/*
 * Add program, worst fit algorithm.
 * @param: Program name and program size.
 */
void LinkedList::worstFit(string name, int size){
	curr = head;
	int page;
	bool test = true; //Test case for free.
	int test2 = 0;	//Test case for start of link index.
	int test3=1; //Test case for error.
	int test4=0; //Test case for leftover index.
	int count=0; //Fragment number
	int start=0; //Start location of the largest fragment.

	//Number of pages being used by the program.
	if (size%4 == 0){
		page = size/4;
	}
	else{
		page = size/4 + 1;
	}
	//Loop till end.
	for(int t=0;t<32;t++){
		// If the program already exists, return error.
		if (curr->data == name){
			cout << "Error, Program " << name << " already running." << endl;
			test3 =0;
			break;
		}
		//Look for largest fragment.
		if(test3 ==1){
		// Loops until the end of the list
			if (curr != NULL){
				// Checks to see if free.
				if (curr->data == "Free" && test){
					test = false;
					curr = curr->next;
					test4++;
					test2=t+1;
				}
				// Move on to the next node if still free.
				else if (curr->data == "Free" && test == false){
					curr = curr->next;
					test4++;
				}
				// If not free, reset.
				else{
					test4=0;//Reset counter
					test = true;
					curr = curr->next;
				}
				if(test4>= page){
					if (count<test4){
					count=test4;
					start=test2;
					}
				}
			}
		}
	}

	//Pass through the links.
	curr = head;
	for(int j=1; j<=32;j++){
		//Look for free links and store input program.
		if((j>=start)&&(j<start+page)){
			if (curr->data == "Free"){
					curr->data = name;
			}
		}
		curr = curr->next;
	}
	 //The algorithm is successful.
	if (test3 !=0){
		cout<< "Program " << name << " added successfully, " << page << " page(s) used." << endl;
	}
}

/*
 * Remove program.
 * @param: Name of program.
 */
int LinkedList::remove(string name){
	int test3=1;
	int num=0;	//Number of pages.
	curr=head;
	for(int t=0;t<32;t++){
		// If the program already exists, set it to free.
		if (curr->data == name){
			curr->data = "Free";
			num++;
			test3=0;
		}
		curr = curr->next;
	}
	if (test3==0){
		cout<<"Program " <<name<<" successfully killed, "<< num << " page(s) reclaimed." <<endl;
		return (num*4);
	}
	else{
		cout << "Unable to locate program with the provided name.\n";
		return 0;
	}
}

/*
 * Displays number of fragments in OS.
 * Return 2D array of fragment size and index.
 */
void LinkedList::fragments(){
	curr = head;
	bool test = true;
	int fragment = 0; //Number of fragments
	// Loops until the end of the list
	do{
		// Checks to see if free.
		if (curr == NULL) {
			cout << "No free fragments available\n";
			break;
		}
		else if (curr->data == "Free" && test){
			fragment++;
			test = false;
			curr = curr->next;
		}
		// Move on to the next node if still free.
		else if (curr->data == "Free" && test == false){
			curr = curr->next;
		}
		// If not free, reset.
		else{
			test = true;
			curr = curr->next;
		}
	}while(curr != NULL);
	cout << "There are " << fragment << " fragment(s)" << endl;
}


/*
 *Pick an algorithm to allocate the memory in the OS, worst fit =0, best fit = 1.
 *@return: Return choice on best or worst fit.
 */
 int LinkedList::fitChoice(string type) {
		//Pick an algorithm to allocate the memory in the OS, worst fit or best fit.
		cout << "Pick an algorithm to allocate the memory in the OS, best or worst." << endl;
		string fit = type; //Store selected algorithm.
		//Loop till correct value is chosen.
		string str1 = "best";
		string str2 = "worst";

		//Check for invalid user input.
		for (unsigned int i=0; i<fit.length(); i++){
		fit[i] = tolower(fit[i]);
		}
		//Pick Best Fit
		if (fit == str1){
			cout << "Using best fit algorithm." << endl;
			return 1;
		}
		//Pick Worst Fit
		if (fit == str2){
			cout << "Using worst fit algorithm." << endl;
			return 0;
		}
		//None
		else{
			cout << "Invalid input." << endl;
			return 2;
		}
	}
/*
 * Checks if the input is a character.
 * @param: User input.
 * @return: Return valid user input.
 */
int LinkedList::input(int input){
	int test =input; //Test case.
	while ((cin.fail()) || (cin.get()!='\n')) {
		cin.clear(); //Clear the Error Flags that appears.
		cin.ignore(INT_MAX, '\n'); // Skips to the next newline characters and ignore the integer maximum value of character on the same line.
		cout << "Invalid input." << endl;
		cout << "Enter a valid input:"<< endl;
		cin >> test;
	}
	return test;
}
/*
 * Prints the linked list.
 */
void LinkedList::print(){
	int test =1; //Format Output.
	cout << endl;
	curr=head; 	//Start at head of link list.
	do {
		if(test == 8){
			cout << curr->data << "\t" << endl;
			curr = curr->next;
			test = 1; //reset
		}
		else {
			cout << curr->data << "\t";
			curr = curr->next;
			test++;
		}
	} while (curr != NULL); //Stop when no more links.
	cout << endl;
}
#endif
