/* Write a program to remove all punctuations from string. */

#include<iostream>
#include<string>

using namespace std;

string removePunctuations(string message)
{
	string afterRemove = "";
	for (int i = 0; i < message.length(); i++)
	{
		if (!ispunct(message[i]))
			afterRemove += message[i];
	}
	return afterRemove;
}

int main()
{
	string message = "Welcome to Algeria,..; Algeria expresses a warm welcome.";

	cout << "Original message:\n" << message << endl;
	cout << "\nPaunctuations removed:\n" << removePunctuations(message) << endl;

	return 0;
}
