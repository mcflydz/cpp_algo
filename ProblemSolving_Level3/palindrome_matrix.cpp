/* Write a program to check if the matrix is palindrome or not. */

#include<iostream>

using namespace std;

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

bool palindromeCheck(int matrix[3][3])
{
	short half = 3 / 2;
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			if (matrix[i][j] != matrix[i][3 - 1 - j])
				return false;
		}
	}
	return true;
}

void printPalindromeCheckResult(bool status)
{
	if (status == true)
		cout << "\nMatrix is palindrom.\n";
	else
		cout << "\nMatrix is not palindrom.\n";
}

int main()
{
	int matrix[3][3] = { { 1,2,1 }, { 2,1,2 }, { 1,1,1 } };
	cout << "Matrix:\n";
	printMatrix(matrix);

	printPalindromeCheckResult(palindromeCheck(matrix));

	return 0;
}