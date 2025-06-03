/* Write a program to read a string then print each word in that string. */

#include<iostream>
#include<string>

using namespace std;

string readString()
{
	string message;
	cout << "Please enter your string:\n";
	getline(cin, message);
	return message;
}

void printEachWordInStringUsingLogic(string message)
{
	cout << "\nYour string words are:\n";
	bool canEndLine = false;
	for (short i = 0; i < message.length(); i++)
	{
		if (message[i] != ' ')
		{
			cout << message[i];
			canEndLine = true;
		}
		if (message[i] == ' ' && canEndLine == true)
		{
			cout << "\n";
			canEndLine = false;
		}
	}
}

int main()
{
	string message = readString();
	printEachWordInStringUsingLogic(message);
	return 0;
}