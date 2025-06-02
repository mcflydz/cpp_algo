/* Write a program to read a string then upper all letters, then lowercase all letters, and print them. */

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

string upperAllLettersOfString(string message)
{
	for (int i = 0; i <= message.length(); i++)
	{
		message[i] = toupper(message[i]);
	}
	return message;
}


string lowerAllLettersOfString(string message)
{
	for (int i = 0; i <= message.length(); i++)
	{
			message[i] = tolower(message[i]);
	}
	return message;
}

int main()
{
	string message = readString();

	cout << "\nString after upper:\n";
	cout << upperAllLettersOfString(message) << endl;

	cout << "\nString after lower:\n";
	cout << lowerAllLettersOfString(message) << endl;
	return 0;
}