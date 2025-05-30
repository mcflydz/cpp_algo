/* Write a program to fill two 3*3 matrix with random numbers, then multiply them into a 3rd matrix and print it. */

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
			printf(" %0*d   ", 2,matrix[i][j]);
		}
		cout << "\n";
	}
}

void multiplyTwoMatrices(int matrix1[3][3], int matrix2[3][3], int matrixMulti[3][3])
{
	short sum = 0;
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			for (short k = 0; k < 3; k++)
			{
				sum += matrix1[i][k] * matrix2[k][j];
			}
			matrixMulti[i][j] = sum;
			sum = 0;
		}
	}
}

void printResultOfMultipliction(int matrix[3][3])
{
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			printf(" %0*d   ", 5, matrix[i][j]);
		}
		cout << "\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix1[3][3], matrix2[3][3], matrixMulti[3][3];

	fillMatrixWithRandomNumbers(matrix1);
	cout << "Matrix1:\n";
	printMatrix(matrix1);

	fillMatrixWithRandomNumbers(matrix2);
	cout << "\nMatrix2:\n";
	printMatrix(matrix2);

	multiplyTwoMatrices(matrix1, matrix2, matrixMulti);
	cout << "\nResults:\n";
	printResultOfMultipliction(matrixMulti);

	return 0;
}