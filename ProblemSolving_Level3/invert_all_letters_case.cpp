/* Write a program to read a string then invert all its letters case and print it. */

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

char invertCharacterCase(char message)
{
	return isupper(message) ? tolower(message) : toupper(message);
}

string invertingAllLettersCasesOfString(string message)
{
	for (int i = 0; i < message.length(); i++)
	{
		message[i] = invertCharacterCase(message[i]);
	}
	return message;
}

int main()
{
	string message = readString();

	cout << "\nString after inverting all letters case:\n";
	cout << invertingAllLettersCasesOfString(message);
	return 0;
}