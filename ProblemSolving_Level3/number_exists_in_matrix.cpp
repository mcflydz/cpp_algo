/* Write a program to check if a given number exists in matrix or not. */

#include<iostream>
#include<cstdlib>

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
			printf(" %d   ", matrix[i][j]);
		}
		cout << "\n";
	}
}

short readNumber()
{
	short number = 0;
	do {
		cout << "\nEnter a number to look for in matrix? ";
		cin >> number;
	} while (number < 0 || number > 99);
	return number;
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

void printCheckResult(bool status)
{
	if (status == true)
		cout << "\nYes it is there.\n";
	else
		cout << "\nNot in matrix.\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3];
	fillMatrixWithRandomNumbers(matrix);
	cout << "Matrix1:\n";
	printMatrix(matrix);

	printCheckResult(checkNumberInMatrix(matrix, readNumber()));

	return 0;
}