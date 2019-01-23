#include "pa3.h"

using namespace std;

//============================================================================
// Name        : pa3.cpp
// Author      : Johnny Li
// Description : A program that emulate the lexical analysis task for a limited version
//of a programming language. C++ code should input a text file from user, which contains the expression
//he/she wants the compilers to analyze. Then, your code should parse the input, detect
//the tokens, classify them, and print out the results with the stack implementation.
//============================================================================

//Global value counters
int nestCount =0;
int numFOR = 0;
int numBEGIN = 0;
int numEND = 0;

//Boolean for the operators delimiter
char del[] = {'+', '-', '/', '*', ',', '=', ';'};
bool plus0 = false;
bool minus0 = false;
bool divide = false;
bool mult = false;
bool com = false;
bool equal0 = false;
bool semicolon = false;
bool minusminus = false;
bool plusplus = false;
bool equalequal = false;


/*
 * Check if char is lowercase letter. If it is then it is a identifier.
 * @param: char line[i]
 */
bool testID (char line){
	if(islower(line)){
		return true;
	}
	return false;
}

/*
 * Check if char is uppercase letter. If it is then it is a keyword.
 * @param: char line[i]
 */
bool testKW (char line){
	if(isupper(line)){
		return true;
	}
	return false;
}

int main() {
	//Initialized stacks
	Stack0 identifiers;
	Stack0 constants;
	Stack0 syntaxs;

	//Initialized variables
	int error = 0; //Error counter
	bool test = true;
	bool test1 = true;
	bool test2 = true;

	//Taking the input file as "code.txt”, code taken in parts from http://www.cplusplus.com/doc/tutorial/files/
	string line;
	string fileName;
	cout << "Please enter the name of the input file: ";
	cin >> fileName;
	ifstream file(fileName);
	//Open valid file input
	if(file.is_open()){
		//Loop to check code
		while(getline(file, line)){
			line = line + " "; //check final value of each line

			//Find parenthesis
			for (unsigned int i = 0; i < line.length(); i++) {
				if(line[i] == '('){
					error++;
				}
				if(line[i] == ')'){
					error--;
				}
			}

			//Finds identifiers
			for (unsigned int i = 0; i < line.length(); i++) {
				//Test if char is lowercase.
				if (testID(line[i])==true) {
					unsigned int j = 0;
					//check for a set of lowercase letters/ word.
					while ((i+j < line.length()) && (testID(line[i+j])==true)) {
						j++;
					}
					//Extract word/variable
					string indentifier = line.substr(i,j);
					//Store word/variable
					identifiers.push(indentifier);
					i = i+j;
					}

				//Finds keywords, similar to identifiers.
				//Test if char is uppercase.
				if (testKW(line[i])==true) {
					unsigned int j = 0;
					//check for a set of uppercase letters/ word.
					while ((i+j < line.length()) && (testKW(line[i+j])==true)) {
						j++;
					}
					//Extract word/variable
					string keyword = line.substr(i,j);
					//Store word/variable
					if (keyword == "BEGIN"){
						numBEGIN++;
						nestCount++;
					}
					if (keyword == "END"){
						numEND++;
						nestCount--;
					}
					if (keyword == "FOR"){
						numFOR++;
					}
					i = i+j;
					}

					//Finds delimiters
					if(line[i] == del[6]){
						semicolon = true;
					}
					if(line[i] == del[4]){
						com = true;
					}
					if (line[i] == del[3]){
						mult = true;
					}
					if(line[i] == del[2]){
						divide = true;
					}
					if(line[i] == del[0]){
						if(line.find("++") != string::npos){
							plusplus = true;
						}
						else {
							plus0 = true;
						}
					}
					if(line[i] == del[1]){
						if(line.find("--") != string::npos){
							minusminus = true;
						}
						else {
							minus0 = true;
						}
					}
					if(line[i] == del[5]){
						if(line.find("==") != string::npos){
							equalequal = true;
						}
						else {
							equal0 = true;
						}
					}
			}

			//Find constants
			for (unsigned int a = 0; a < line.length(); a++) {
				//Find digits in line of code
				if (isdigit(line[a])) {
					unsigned int b= 0;
					//Check for set of numbers
					while (isdigit(line[a+b]) && ((a+b) < line.length())) {
						b++;
					}
					//Retrieve value
					string constant = line.substr(a,b);
					a = a+b;
					//Store Constant
					constants.push(constant);
				}
			}

			//Find syntax error, same as pattern code above
	        for (unsigned i = 0; i < line.length(); i++) {
	        	//Check if uppercase letter
				if (testKW(line[i])==true) {
					unsigned j = 0;
					//Get word/set of letter
					while (((i+j) < line.length()) && testKW(line[i+j])==true) {
						j++;
					}
					//Retrieve error
					string syntax = line.substr(i,j);
					//Store error
					if (!((syntax == "BEGIN")||(syntax == "END")||(syntax == "FOR"))){
						syntaxs.push(syntax);
					}
					i = i+j;
				}
			}
		}
	}

	// Invalid file input
	else{
		cout << "Error: Invalid File.";
		exit(0);
	}

	//Print depth
	if (nestCount<0){
		nestCount =0;
	}
	cout << "The depth of the nested loop(s) is " << nestCount << "\n";

	//Print keywords
    cout << "Keywords: ";
	if(numBEGIN>0){
		cout << "BEGIN ";
	}
	if(numEND>0){
		cout << "END ";
	}
	if(numFOR>0){
		cout << "FOR ";
	}
	cout << "\n";

	//Print Identifier
	cout << "Identifier: ";
	//Organize vector.
	identifiers.remove();
	//Loop to print out identifiers
	//Code obtained from stack Overflow "c++ - how to print out all elements in a std::stack"
	//https://stackoverflow.com/questions/4523178/how-to-print-out-all-elements-in-a-stdstack-or-stdqueue-conveniently
	while (identifiers.size()>0){
		cout << identifiers.pop() + " ";
	}
	cout << "\n";

	//Organize vector.
	constants.remove();
	//Print Constant
	cout << "Constant: ";
	while (constants.size()>0){
		cout << constants.pop() + " ";
	}
	cout << "\n";

	//Print Operators
	cout << "Operators: ";
	    if(plus0){
	        cout << "+ ";
	    }
	    if(minus0){
	        cout << "- ";
	    }
	    if(mult){
	        cout << "* ";
	    }
	    if(divide){
	        cout << "/ ";
	    }
	    if(minusminus){
	        cout << "-- ";
	    }
	    if(plusplus){
	        cout << "++ ";
	    }
	    if(equal0){
	        cout << "= ";
	    }
	    if(equalequal){
	        cout << "== ";
	    }
	    cout << "\n";

	    //Print Delimiters
	    cout << "Delimiter: ";
	    if(semicolon){
	        cout << "; ";
	    }
	    if (com){
	        cout << ", ";
	    }
	    cout << "\n";

	    //Print Errors
	    cout << "Syntax Error(s): ";
	    if(error<0){
		   cout << ") ";	//Missing )
	       }
	    else if(error>0){
		   cout << "( ";	//Missing (
		}
	    else{
	    	test = false;
	    }

		//Organize vector.
		syntaxs.remove();
		if (syntaxs.size()==0){
			test2=false;
		}
		else {
			while (syntaxs.size()>0){
			cout << syntaxs.pop() + " ";
			}
		}

		if(test2==false){
			if(numBEGIN>numEND){
			   cout << "END ";	//Missing END
			}
			else if(numBEGIN<numEND){
			   cout << "BEGIN ";	//Missing BEGIN
			}
			else if(numFOR<numEND){
			   cout << "FOR ";		//Missing FOR
			}
			else if(numFOR>numEND){
			   cout << "END ";	//Missing END
			}
			else{
				test1 = false;
			}
		}
		if((test == false) && (test1 == false) && (test2 == false)){
			cout<<"NA";
		}
	return 0;
}



