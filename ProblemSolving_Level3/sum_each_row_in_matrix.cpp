/* Write a program to fill a 3*3 matrix with random numbers, then print each row sum. */

#include<iostream>
#include<iomanip>
#include<cstdlib>

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
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = randomNumber(1, 100);
		}
	}
}

void printMatrix(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << setw(6) << left << arr[i][j];
		}
		cout << endl;
	}
}

void sumOfEachRowInMatrix(int arr[3][3])
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum += arr[i][j];
		}
		printf("Row %d Sum = %d\n", i + 1, sum);
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

	cout << "\nThe following are the sum of each row in matrix:\n";
	sumOfEachRowInMatrix(arr);

	return 0;
}