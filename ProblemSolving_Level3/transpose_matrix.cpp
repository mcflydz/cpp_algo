/* Write a program to fill a 3*3 matrix with ordered numbers and print it, then transpose matrix and print it. */

#include<iostream>
#include<iomanip>

using namespace std;

void fillMatrixWithOrderedNumbers(int arr[3][3])
{
	int number = 1;
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			arr[i][j] = number;
			number++;
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

void transposeMatrix(int arr[3][3], int arrT[3][3])
{
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			arrT[j][i] = arr[i][j];
		}
	}
}

int main()
{
	int arr[3][3], arrT[3][3];

	fillMatrixWithOrderedNumbers(arr);
	cout << "The following is a 3*3 ordered matrix:\n";
	printMatrix(arr);

	transposeMatrix(arr, arrT);
	cout << "\nThe following is the transposed matrix:\n";
	printMatrix(arrT);

	return 0;
}