/* Write a program to check if a given number exists in matrix or not. */

#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

short randomNumber(short from, short to)
{
	short random = 0;
	random = rand() % (to - from + 1) + from;
	return random;
}

void fillMatrixWithRandomNumbers(int matrix[3][3])
{
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			matrix[i][j] = randomNumber(1, 99);
		}
	}
}

void printMatrix(int matrix[3][3])
{
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			printf(" %0*d   ", 2, matrix[i][j]);
		}
		cout << "\n";
	}
}

bool checkNumberInMatrix(int matrix[3][3], short number)
{
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			if (matrix[i][j] == number)
				return true;
		}
	}
	return false;
}

void printIntersectedNumbers(int matrix1[3][3], int matrix2[3][3])
{
	short number = 0;
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			number = matrix1[i][j];
			if (checkNumberInMatrix(matrix2, number) == true)
				cout << setw(6) << left << number;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix1[3][3], matrix2[3][3];
	fillMatrixWithRandomNumbers(matrix1);
	cout << "Matrix1:\n";
	printMatrix(matrix1);

	fillMatrixWithRandomNumbers(matrix2);
	cout << "\nMatrix2:\n";
	printMatrix(matrix2);

	cout << "\nIntersected numbers are:\n";
	printIntersectedNumbers(matrix1, matrix2);

	return 0;
}