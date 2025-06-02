/* Write a program to read a string then count small & capital letters in that string. */

#include<iostream>
#include<string>

using namespace std;

string readString()
{
	string message = "";
	cout << "Please enter your string:\n";
	getline(cin, message);
	return message;
}

short countSmallLettersInString(string message)
{
	short count = 0;
	for (short i = 0; i < message.length(); i++)
	{
		if (islower(message[i]))
			count++;
	}
	return count;
}

short countCapitalLettersInString(string message)
{
	short count = 0;
	for (short i = 0; i < message.length(); i++)
	{
		if (isupper(message[i]))
			count++;
	}
	return count;
}

int main()
{
	string message = readString();

	cout << "\nSmall letters count:\n";
	cout << countSmallLettersInString(message);

	cout << "\nCapital letters count:\n";
	cout << countCapitalLettersInString(message);

	return 0;
}