/* Write a program to count given number in matrix. */

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

short readNumber()
{
	short number = 0;
	do {
		cout << "\nEnter a number to count in matrix? ";
		cin >> number;
	} while (number < 0 && number > 99);
	return number;
}

short countNumberInMatrix(int matrix[3][3], short number)
{
	short count = 0;
	for (short i = 0;i < 3;i++)
	{
		for (short j = 0;j < 3;j++)
		{
			if (matrix[i][j] == number)
				count++;
		}
	}
	return count;
}

void printCount(short number, short count)
{
	printf("\nNumber %d count in matrix is %d\n", number, count);
}

int main()
{
	srand((unsigned)time(NULL));

	int matrix[3][3];
	fillMatrixWithRandomNumbers(matrix);
	cout << "Matrix1:\n";
	printMatrix(matrix);

	short number = readNumber();
	short count = countNumberInMatrix(matrix, number);
	printCount(number, count);

	return 0;
}