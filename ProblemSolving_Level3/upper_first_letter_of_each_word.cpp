/* Write a program to read a string then uppercase the first letter of each word in that string. */

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

string upperFirstLetterOfWord(string message)
{
	bool isFirstLetter = true;
	for (int i = 0; i <= message.length(); i++)
	{
		if (message[i] != ' ' && isFirstLetter)
		{
			message[i] = toupper(message[i]);
		}
		isFirstLetter = (message[i] == ' ' ? true : false);
	}
	return message;
}

int main()
{
	string message = upperFirstLetterOfWord(readString());
	cout << message;

	return 0;
}