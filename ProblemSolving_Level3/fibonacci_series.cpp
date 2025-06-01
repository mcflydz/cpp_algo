/* Write a program to print Fibonacci series of 10. */

#include<iostream>
#include<vector>

using namespace std;

void fibonacciSeriesUsingRecurrsionOf(short count)
{
	static short intialValue = 1;
	if (intialValue == 1)
	{
		printf(" 1   ");
	}
	intialValue++;

	static short prev1 = 1;
	static short prev2 = 0;
	static short sum = 0;
	sum = prev1 + prev2;
	prev2 = prev1;
	prev1 = sum;
	printf(" %d   ", sum);
	count--;
	if (count > 1) fibonacciSeriesUsingRecurrsionOf(count);
}

void fibonacciSeriesUsingVector(short number, vector <short>& vFibonacciSeries)
{
	short prev1 = 1;
	short prev2 = 1;
	short sum = 0;
	vFibonacciSeries = { 1, 1 };
	for (short i = 1; i < number - 1; i++)
	{
		sum = prev1 + prev2;
		prev2 = prev1;
		prev1 = sum;
		vFibonacciSeries.push_back(sum);
	}
}

void printFibonacciVector(vector <short>& vFibonacciSeries)
{
	for (short& number : vFibonacciSeries)
	{
		printf(" %d   ", number);
	}
}

int main()
{
	cout << "Fibonacci series of 10 using recurrsion:\n";
	fibonacciSeriesUsingRecurrsionOf(10);

	vector <short> vFibonacciSeries;
	fibonacciSeriesUsingVector(10, vFibonacciSeries);
	cout << "\nFibonacci series of 10 using vector:\n";
	printFibonacciVector(vFibonacciSeries);

	return 0;
}