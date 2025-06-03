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

void printEachWordInString(string message)
{
	cout << "\nYour string words are:\n";

	string delimiter = " ";
	short postion = 0;
	string word;

	while ((postion = message.find(delimiter)) != string::npos)
	{
		word = message.substr(0, postion);
		if (word != "")
		{
			cout << word << endl;
		}
		message.erase(0, postion + delimiter.length());
	}

	if (message != "")
	{
		cout << message << endl;
	}
}

int main()
{
	string message = readString();
	printEachWordInString(message);
	return 0;
}