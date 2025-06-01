/* Write a program to print the minimum and maximum numbers in matrix. */

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
			printf(" %0*d   ", 2, matrix[i][j]);
		}
		cout << "\n";
	}
}

void printMinMaxNumbersInMatrix(int matrix[3][3])
{
	short min = matrix[0][0];
	short max = matrix[0][0];

	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			if (matrix[i][j] < min)
				min = matrix[i][j];
			if (matrix[i][j] > max)
				max = matrix[i][j];
		}
	}

	printf("\nMinimum number is: %d\n", min);
	printf("\nMaximum number is: %d\n", max);
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3];
	fillMatrixWithRandomNumbers(matrix);
	cout << "Matrix:\n";
	printMatrix(matrix);

	printMinMaxNumbersInMatrix(matrix);

	return 0;
}