/* Write a program to fill a 3*3 matrix with random numbers, then write a function to sum all numbers in this matrix and print it. */

#include<iostream>
#include<iomanip>
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

int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3];

	fillMatrixWithRandomNumbers(matrix);
	cout << "Matrix:\n";
	printMatrix(matrix);

	short sum = sumOfMatrixNumbers(matrix);
	printf("\nSum of matrix is: %d\n", sum);

	return 0;
}