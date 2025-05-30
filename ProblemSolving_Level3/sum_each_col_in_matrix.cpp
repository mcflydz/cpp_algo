/* Write a program to fill a 3*3 matrix with random numbers, then print each col sum. */

#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

int randomNumber(int from, int to)
{
	int random = 0;
	random = rand() % (to - from + 1) + from;
	return random;
}

void fillMatrixWithRandomNumbers(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			arr[i][j] = randomNumber(1, 100);
		}
	}
}

void printMatrix(int arr[3][3])
{
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			cout << setw(6) << left << arr[i][j];
		}
		cout << endl;
	}
}

void sumOfEachColInMatrix(int arr[3][3])
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum += arr[j][i];
		}
		printf("Col %d Sum = %d\n", i + 1, sum);
		sum = 0;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	fillMatrixWithRandomNumbers(arr);
	cout << "The following is a 3*3 random matrix:\n";
	printMatrix(arr);

	cout << "\nThe following are the sum of each col in matrix:\n";
	sumOfEachColInMatrix(arr);

	return 0;
}