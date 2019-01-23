#include <string>
#include <climits>
using namespace std;

/*
 * 	Name: pa1.h
 *	Summary: Print magic square for the different cases and sum of the rows, columns, and diagonals.
 *  Author: Johnny Li
 *  COP 3503 Section Number: 128D
 */

/*
 READ ME
 Originality I have planned to create functions and place them in the pa1.h but I could not get it to work by
 the submission deadline so I placed everything into the main method. This code is functional and I have included
 the pa1.h with the nonfunctional code commented out as evidence of my attempt.
 */
/*	class pa1{
	public:
	//Method declarations of print output.
	void Case1(int *magicSquare[][], int N);
	void Case2(int *magicSquare[][], int N);
	void Case3(int *magicSquare[][], int N);
	void Case4(int *magicSquare[][], int N);
	void Case5(int *magicSquare[][], int N);
	void Sums(int *magicSquare[][], int N);
	};

//Case 1: Original Output
void pa1::Case1(int *magicSquare[][], int N){
	int row = N;
	int column = N;
	cout << ("Magic Square #1 is:")<<endl;
	for (row = 0; row < N; row++) {
		for (column = 0; column < N; column++) {
			cout << ("\t") << magicSquare[row][column];
		}
		cout << ("\n");
	}
	Sums(*magicSquare[][], N)
}

//Case 2: Diagonal Top Left Flip
void pa1::Case2(int *magicSquare[][], int N){
	int row = N;
	int column = N;
	cout << ("Magic Square #2 is:")<<endl;
	for (row = N-1; row >= 0; row--) {
		for (column = N-1; column >= 0; column--) {
			cout << ("\t") << magicSquare[row][column];
		}
		cout << ("\n");
	}
	Sums(*magicSquare[][], N)
}

//Case 3: Diagonal Top Right Flip
void pa1::Case3(int *magicSquare[][], int N){
	int row = N;
	int column = N;
	cout << ("Magic Square #3 is:")<<endl;
	for (row = N-1; row >= 0; row--) {
		for (column = N-1; column >= 0; column--) {
			cout << ("\t") << magicSquare[column][row];
		}
		cout << ("\n");
	}
	Sums(*magicSquare[][], N)
}

//Case 4: Flip Top from Left.
void pa1::Case4(int *magicSquare[][], int N){
	int row = N;
	int column = N;
	cout << ("Magic Square #4 is:")<<endl;
		for (row = 0; row < N; row++) {
			for (column = 0; column < N; column++) {
				cout << ("\t") << magicSquare[column][row];
			}
			cout << ("\n");
		}
}

//Case 5: Flip Top from Right.
void pa1::Case5(int *magicSquare[][], int N){
	int row = N;
	int column = N;
	cout << ("Magic Square #5 is:")<<endl;
	for (column = N-1; column >= 0; column--) {
		for (row = 0; row<N; row++) {
		cout << ("\t") << magicSquare[row][column];
	}
	cout << ("\n");
	}
	Sums(*magicSquare[][], N)
}

//--------------------------------
//Prints the sum of the rows, columns, and diagonals.
void pa1::Sums(int *magicSquare[][], int N){

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
	for(int x=0; x<N; x++){
		d2Sum += magicSquare[N-1][x];
		N--;
	}

	cout << "Sums of diagonals: "<< d1Sum << "  " << d2Sum << endl;
}*/


