/* Write a program to replace words in string. */

#include<iostream>
#include<string>

using namespace std;

string replaceWords(string message, string wordToReplace, string replacement)
{
	short position = message.find(wordToReplace);

	while (position != string::npos)
	{
		message.replace(position, wordToReplace.length(), replacement);
		position = message.find(wordToReplace);
	}
	return message;
}

int main()
{
	string message = "Welcome to Algeria, Algeria expresses a warm welcome.";
	string wordToReplace = "Algeria";
	string replacement = "USA";

	cout << "Original message:\n" << message << endl;
	cout << "\nAfter replace:\n" << replaceWords(message, wordToReplace, replacement) << endl;

	return 0;
}