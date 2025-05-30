/* Write a program to fill a 3*3 matrix with random numbers, then sum each row in a seperate array and print the results. */

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

void printArray(int arr[3][3])
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

void sumEachRowInSeparateArray(int arr[3][3], int sumArray[3])
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3;j++)
		{
			sum += arr[i][j];
		}
		sumArray[i] = sum;
		sum = 0;
	}
}

void printResult(int sumArray[3])
{
	for (int i = 0; i < 3; i++)
	{
		printf("Row %d Sum = %d\n", i + 1, sumArray[i]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3], sumArray[3];
	fillMatrixWithRandomNumbers(arr);
	cout << "The followin is a 3*3 random matrix:\n";
	printArray(arr);

	sumEachRowInSeparateArray(arr, sumArray);
	cout << "The followin are the sum of each row in the matrix:\n";
	printResult(sumArray);

	return 0;
}