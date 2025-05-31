/* Write a program to check if the matrix is identity or not. */

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

bool checkIdentityMatrix(int matrix[3][3])
{
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			if (i == j && matrix[i][j] != 1)
				return false;
			if (i != j && matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}

void printIndentityCheckResult(bool status)
{
	if (status == true)
		cout << "\nMatrix is identity.\n";
	else
		cout << "\nMatrix is not identity.\n";
}

int main()
{
	int matrix[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
	cout << "Matrix1:\n";
	printMatrix(matrix);

	printIndentityCheckResult((checkIdentityMatrix(matrix)));

	return 0;
}