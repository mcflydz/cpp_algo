/* Write a program to read a string then print the first letter of each word in that string. */

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

void firstLetterOfWord(string message)
{
	bool isFirstLetter = true;
	for (int i = 0; i <= message.length(); i++)
	{
		if (message[i] != ' ' && isFirstLetter)
		{
			cout << message[i] << endl;
		}
		isFirstLetter = (message[i] == ' ' ? true : false);
	}
}

int main()
{
	firstLetterOfWord(readString());

	return 0;
}