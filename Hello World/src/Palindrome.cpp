/*
 * Palindrome.cpp
 *
 *  Created on: Sep 14, 2017
 *      Author: Johnny Li
 */
//A palindrome number is equal to its reverse.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string n;
	cin >> n;
	string m = ("");

	for(int i = n.length() - 1; i >= 0; i--)
	{
		m.append(n, i, 1);
	}

	if( m == n)
		cout << "Palindrome!" << endl;
	else
		cout << "Not a palindrome!" << endl;

}
