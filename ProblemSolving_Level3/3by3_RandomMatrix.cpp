/* Write a program to fill a 3*3 matrix with random numbers */


#include <iostream>
#include <iomanip>

using namespace std;

int randomNumber(int from, int to)
{
	int random = 0;
	random = rand() % (to - from + 1) + from;
	return random;
}

void fillMatrix(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			arr[i][j] = randomNumber(1, 100);
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

int main()
{
	srand((unsigned) time(NULL));
	int arr[3][3];

	cout << "The following is a 3 * 3 random matrix:\n";
	fillMatrix(arr);
	printMatrix(arr);

	return 0;
}
