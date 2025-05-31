/* Write a program to check if the matrix is scalar or not. */

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

bool checkScalarMatrix(int matrix[3][3])
{
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			if (i == j && matrix[i][j] != matrix[0][0])
				return false;
			if (i != j && matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}

void printScalarCheckResult(bool status)
{
	if (status == true)
		cout << "\nMatrix is scalar.\n";
	else
		cout << "\nMatrix is not scalar.\n";
}

int main()
{
	int matrix[3][3] = { {3,0,0},{0,3,0},{0,0,3} };
	cout << "Matrix1:\n";
	printMatrix(matrix);

	printScalarCheckResult((checkScalarMatrix(matrix)));

	return 0;
}