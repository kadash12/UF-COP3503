#ifndef pa3_H
#define pa3_H
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
/*
 * pa3.h
 * Summary: Contain stack and constructors.
 * Author: Johnny Li
 * COP 3503 Section Number: 128D
 */

/*
 * Stack class - create Stack using vectors
 */
class Stack0{
private:
    vector<string> stacking;
    int max = 0;
    int current = 0;
public:
    Stack0();
    void push(string element);
    string pop();
    int size();
    int nestCount();
    void remove();
};

//Constructor
Stack0::Stack0(){}

/*
   * Push elements to stack
   * @param: string line
   */
  void Stack0::push(string element) {
  	//Done with assistance of TA
		stacking.push_back(element);
		current++;
		if(max < current)
		 max++;
   }

  /*
   * Pop elements to stack
   */
  string Stack0::pop() {
  	if(!stacking.empty()){
  	//Done with assistance of TA
		string element = stacking.back();
		stacking.pop_back();
		current--;
		return element;
  	}

		else{
			current--;
			return "The Stack is Empty";
		}
	}

  /*
   * Return stack size.
   */
  int Stack0::size(){
		return stacking.size();
	}

  /*
   * Return number of nested loop
   */
  int Stack0::nestCount(){
  	  int count = max - stacking.size();
  	  return count;
	}

  /*
   * Remove repetition of elements.
   * Code obtained from stack Overflow "What's the most efficient way to erase duplicates and sort a vector?"
   * https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector
   */
  void Stack0::remove(){
  	sort(stacking.begin(), stacking.end());
  	stacking.erase(unique(stacking.begin(),stacking.end()), stacking.end());
     }

//Constructor for Functions
bool testKW (char line);
bool testID (char line);

#endif
