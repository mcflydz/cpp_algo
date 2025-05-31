/* Write a program to check if the matrix is sparse or not. */

#include<iostream>

using namespace std;

void printMatrix(int matrix[3][3])
{
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			printf(" %d   ", matrix[i][j]);
		}
		cout << "\n";
	}
}

bool checkSparseMatrix(int matrix[3][3])
{
	short zerosCount = 0;
	short numbersCount = 0;
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			if (matrix[i][j] == 0)
				zerosCount++;
			if (matrix[i][j] != 0)
				numbersCount++;
		}
	}
	return (zerosCount > numbersCount) ? true : false;
}

void printSparseCheckResult(bool status)
{
	if (status == true)
		cout << "\nMatrix is sparse.\n";
	else
		cout << "\nMatrix is not sparse.\n";
}

int main()
{
	int matrix[3][3] = { {0,2,2},{0,0,1},{0,0,3} };
	cout << "Matrix1:\n";
	printMatrix(matrix);

	printSparseCheckResult((checkSparseMatrix(matrix)));

	return 0;
}