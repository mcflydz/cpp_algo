/* Write a program to read a string then trim left, right, all. */

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

string trimLeft(string message)
{
	short postition = 0;
	while (message[postition] == ' ' && message[postition] != string::npos)
	{
		message.erase(0, 1);
	}
	return message;
}

string trimRight(string message)
{
	int postition = (message.length() - 1);
	while (message[postition] == ' ' && message[postition] != string::npos)
	{
		message.erase(postition - 1, postition);
		postition--;
	}
	return message;
}

string trimAll(string message)
{
	return trimLeft(trimRight(message));
}

int main()
{
	string message = "    Program    ";
	cout << "String     = " << message << endl;
	cout << "Trim Left  = " << trimLeft(message) << endl;
	cout << "Trim Right = " << trimRight(message) << endl;
	cout << "Trim       = " << trimAll(message) << endl;
	return 0;
}