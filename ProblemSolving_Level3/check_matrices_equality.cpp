/* Write a program to compare two matrices and check if they are equal or not. */

#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

enum enCompare { equal = 1, not_equal = 2};

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

short sumOfMatrixNumbers(int matrix[3][3])
{
	short sum = 0;
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}

enCompare compareTwoMatrices(int matrix1[3][3], int matrix2[3][3])
{
	if (sumOfMatrixNumbers(matrix1) == sumOfMatrixNumbers(matrix2))
		return enCompare::equal;
	else
		return enCompare::not_equal;
}

void printCompareResualt(enCompare compare)
{
	if (compare == enCompare::equal)
		cout << "\nMatrices are equal.\n";
	else
		cout << "\nMatrices are not equal.\n";
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

	enCompare compare;
	compare = compareTwoMatrices(matrix1, matrix2);
	printCompareResualt(compare);
	
	return 0;
}