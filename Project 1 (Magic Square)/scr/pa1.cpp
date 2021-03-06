#include <iostream>
#include "pa1.h"

/**
 Name: pa1.cpp
 Project Summary: The program create FIVE(5) different N*N magic squares. A square matrix arrange based on the
 value of N^2, in which the sum of rows, columns, and diagonals are the same. The users (TAs) will specify the
 size of the square matrix: N. The value N must be an odd number between 3 and 15.
 @author Johnny Li
 COP 3503 Section Number: 128D
 */

/*
 READ ME
 Originality I have planned to create functions and place them in the pa1.h but I could not get it to work by
 the submission deadline so I placed everything into the main method. This code is functional and I have included
 the pa1.h with the nonfunctional code commented out as evidence of my attempt.
 */
int main() {
	//User input value of the square matrix size.
	int N;
	cout << "Enter the size of a magic square:"<< endl;
	cin >> N;

	//Check if N is a character.
	while ((cin.fail()) || (cin.get()!='\n')) {
		cin.clear(); //Clear the Error Flags that appears.
		cin.ignore(INT_MAX, '\n'); // Skips to the next newline characters and ignore the integer maximum value of character on the same line.

		cout << "Invalid input." << endl;
		cout << "Enter the size of a magic square (an odd number between 3 and 15):"<< endl;
		cin >> N;

		//Check if N is an odd number between 3 and 15.
		//If not the program will ask to user to input a correct value.
		while ((N < 3) || (N > 15) || (N % 2 == 0)) {
			cout << "Invalid input." << endl;
			cout << "Enter the size of a magic square (an odd number between 3 and 15):" << endl;
			cin >> N;
		}
	}

	//Form a NxN square matrix.
	//Set all slots in array to 0.
	int magicSquare[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			magicSquare[i][j] = 0;
		}
	}

	//--------------------------------
	//Use to initialize positions of value 1 in matrix.
	int row = N / 2; //The value of 1 will be placed in the row of the quotient value.
	int column = N - 1; //The value of 1 will be placed in the column of the difference value.

	//Put all the values in the magic square
	for (int value = 1; value <= N * N;) {

		//If the row move out of bound, move to next column.
		if (row == -1 && column == N) {
			column = N - 2;
			row = 0;
		}
		else {
			//If the row move out of bound, transfer row.
					if (row < 0){
						row = N - 1;
					}
			//If the column move out of bound, reset column.
			if (column == N){
				column = 0;
			}
		}

		//If if there is a number at that position, transfer location to next row and reset column.
		if (magicSquare[row][column]) {
			column -= 2;
			row++;
			continue;
		} else
			magicSquare[row][column] = value++; //Set the value into the matrix.

		//Increment values
		column++;
		row--;
	}

	//Case 1: Original Output
	cout << ("Magic Square #1 is:")<<endl;
	for (row = 0; row < N; row++) {
		for (column = 0; column < N; column++) {
			cout << ("\t") << magicSquare[row][column];
		}
		cout << ("\n");
	}
	cout << endl;
	//1111111111111111111111111111111111111111111111111111111111111111111
	//Prints the sum of the rows, columns, and diagonals.
	//Sum the row and column print it.
	int rSum = 0;
	int cSum = 0;

	//Loop that adds each value in each row.
	cout << "Sums of rows:";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rSum += magicSquare[i][j];
		}
		cout << " " << rSum;
		rSum = 0;	//Reset the sum to 0 for next row.
	}
	cout << endl;

	//Loop that adds each value in each column.
	cout << "Sums of columns:";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cSum += magicSquare[j][i];
		}
		cout << " " << cSum;
		cSum = 0;	//Reset the sum to 0 for next row.
	}
	cout << endl;

	//Sum the diagonals and print it.
	int d1Sum = 0;
	int d2Sum = 0;

	//Loop that adds each value in the diagonal 1.
	for(int x=0; x<N; x++){
		d1Sum += magicSquare[x][x];
	}

	//Loop that adds each value in the diagonal 2.
	int y=N-1;
	for(int x=0; x<N+1; x++){
		if(y>-1){
		d2Sum += magicSquare[y][x];
		y--;
		}
	}

	cout << "Sums of diagonals: "<< d1Sum << "  " << d2Sum << endl;
	cout << endl;

	//222222222222222222222222222222222222222222222222222222222222222222222222
	//Case 2: Diagonal Top Left Flip
	cout << ("Magic Square #2 is:")<<endl;
	for (row = N-1; row >= 0; row--) {
		for (column = N-1; column >= 0; column--) {
			cout << ("\t") << magicSquare[row][column];
		}
		cout << ("\n");
	}
	cout << endl;
	//222222222222222222222222222222222222222222222222222222222222222222222222
	//Prints the sum of the rows, columns, and diagonals.
	//Sum the row and column print it.
	rSum = 0;
	cSum = 0;

	//Loop that adds each value in each row.
	cout << "Sums of rows:";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rSum += magicSquare[i][j];
		}
		cout << " " << rSum;
		rSum = 0;	//Reset the sum to 0 for next row.
	}
	cout << endl;

	//Loop that adds each value in each column.
	cout << "Sums of columns:";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cSum += magicSquare[j][i];
		}
		cout << " " << cSum;
		cSum = 0;	//Reset the sum to 0 for next row.
	}
	cout << endl;

	//Sum the diagonals and print it.
	d1Sum = 0;
	d2Sum = 0;

	//Loop that adds each value in the diagonal 1.
	for(int x=0; x<N; x++){
		d1Sum += magicSquare[x][x];
	}

	//Loop that adds each value in the diagonal 2.
	y=N-1;
	for(int x=0; x<N+1; x++){
		if(y>-1){
		d2Sum += magicSquare[y][x];
		y--;
		}
	}

	cout << "Sums of diagonals: "<< d1Sum << "  " << d2Sum << endl;
	cout << endl;
	//333333333333333333333333333333333333333333333333333333333333333333333
	//Case 3: Diagonal Top Right Flip
	cout << ("Magic Square #3 is:")<<endl;
	for (row = N-1; row >= 0; row--) {
		for (column = N-1; column >= 0; column--) {
			cout << ("\t") << magicSquare[column][row];
		}
		cout << ("\n");
	}
	cout << endl;
	//333333333333333333333333333333333333333333333333333333333333333333333
		//Prints the sum of the rows, columns, and diagonals.
		//Sum the row and column print it.
		rSum = 0;
		cSum = 0;

		//Loop that adds each value in each row.
		cout << "Sums of rows:";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				rSum += magicSquare[i][j];
			}
			cout << " " << rSum;
			rSum = 0;	//Reset the sum to 0 for next row.
		}
		cout << endl;

		//Loop that adds each value in each column.
		cout << "Sums of columns:";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cSum += magicSquare[j][i];
			}
			cout << " " << cSum;
			cSum = 0;	//Reset the sum to 0 for next row.
		}
		cout << endl;

		//Sum the diagonals and print it.
		d1Sum = 0;
		d2Sum = 0;

		//Loop that adds each value in the diagonal 1.
		for(int x=0; x<N; x++){
			d1Sum += magicSquare[x][x];
		}

		//Loop that adds each value in the diagonal 2.
		y=N-1;
		for(int x=0; x<N+1; x++){
			if(y>-1){
			d2Sum += magicSquare[y][x];
			y--;
			}
		}

		cout << "Sums of diagonals: "<< d1Sum << "  " << d2Sum << endl;
		cout << endl;
	//4444444444444444444444444444444444444444444444444444444444444444444444444
	//Case 4: Flip Top from Left.
	cout << ("Magic Square #4 is:")<<endl;
	for (row = 0; row < N; row++) {
		for (column = 0; column < N; column++) {
			cout << ("\t") << magicSquare[column][row];
		}
		cout << ("\n");
	}
	cout << endl;
	//4444444444444444444444444444444444444444444444444444444444444444444444444
		//Prints the sum of the rows, columns, and diagonals.
		//Sum the row and column print it.
		rSum = 0;
		cSum = 0;

		//Loop that adds each value in each row.
		cout << "Sums of rows:";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				rSum += magicSquare[i][j];
			}
			cout << " " << rSum;
			rSum = 0;	//Reset the sum to 0 for next row.
		}
		cout << endl;

		//Loop that adds each value in each column.
		cout << "Sums of columns:";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cSum += magicSquare[j][i];
			}
			cout << " " << cSum;
			cSum = 0;	//Reset the sum to 0 for next row.
		}
		cout << endl;

		//Sum the diagonals and print it.
		d1Sum = 0;
		d2Sum = 0;

		//Loop that adds each value in the diagonal 1.
		for(int x=0; x<N; x++){
			d1Sum += magicSquare[x][x];
		}

		//Loop that adds each value in the diagonal 2.
		y=N-1;
		for(int x=0; x<N+1; x++){
			if(y>-1){
			d2Sum += magicSquare[y][x];
			y--;
			}
		}

		cout << "Sums of diagonals: "<< d1Sum << "  " << d2Sum << endl;
		cout << endl;
	//5555555555555555555555555555555555555555555555555555555555555
	//Case 5: Flip Top from Right.
	cout << ("Magic Square #5 is:")<<endl;
	for (column = N-1; column >= 0; column--) {
		for (row = 0; row<N; row++) {
			cout << ("\t") << magicSquare[row][column];
		}
		cout << ("\n");
	}
	cout << endl;
	//5555555555555555555555555555555555555555555555555555555555555
		//Prints the sum of the rows, columns, and diagonals.
		//Sum the row and column print it.
		rSum = 0;
		cSum = 0;

		//Loop that adds each value in each row.
		cout << "Sums of rows:";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				rSum += magicSquare[i][j];
			}
			cout << " " << rSum;
			rSum = 0;	//Reset the sum to 0 for next row.
		}
		cout << endl;

		//Loop that adds each value in each column.
		cout << "Sums of columns:";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cSum += magicSquare[j][i];
			}
			cout << " " << cSum;
			cSum = 0;	//Reset the sum to 0 for next row.
		}
		cout << endl;

		//Sum the diagonals and print it.
		d1Sum = 0;
		d2Sum = 0;

		//Loop that adds each value in the diagonal 1.
		for(int x=0; x<N; x++){
			d1Sum += magicSquare[x][x];
		}

		//Loop that adds each value in the diagonal 2.
		y=N-1;
		for(int x=0; x<N+1; x++){
			if(y>-1){
			d2Sum += magicSquare[y][x];
			y--;
			}
		}

		cout << "Sums of diagonals: "<< d1Sum << "  " << d2Sum << endl;
		cout << endl;
		//--------------------------------------------------------------------
	return 0;
}
