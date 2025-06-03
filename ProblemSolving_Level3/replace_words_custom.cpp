/* Write a program to replace words in string using custom function. */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

enum enCase { matchCase = 1, dontMatchCase = 2 };

vector <string> splitStringIntoVector(string message)
{
	vector <string> vString;
	short position = 0;
	string word = "";
	while ((position = message.find(' ')) != string::npos)
	{
		word = message.substr(0, position);
		if (word != "")
			vString.push_back(word);
		message.erase(0, position + 1);
	}
	if (message != "")
		vString.push_back(message);
	return vString;
}

string lowerAllString(string message)
{
	for (short i = 0; i < message.length(); i++)
	{
		message[i] = tolower(message[i]);
	}
	return message;
}


string replaceWords(string message, string wordToReplace, string replacement, enCase match)
{
	string afterReplace = "";
	vector <string> vString = splitStringIntoVector(message);

	for (string& word : vString)
	{
		if (match == enCase::matchCase)
		{
			if (word == wordToReplace)
				afterReplace += replacement + " ";
			else
				afterReplace += word + " ";
		}
		if (match == enCase::dontMatchCase)
		{
			if (lowerAllString(word) == lowerAllString(wordToReplace))
				afterReplace += replacement + " ";
			else
				afterReplace += word + " ";
		}
	}

	afterReplace.pop_back();
	return afterReplace;
}

int main()
{
	string message = "Welcome to algeria , Algeria expresses a warm welcome.";
	string wordToReplace = "Algeria";
	string replacement = "USA";

	cout << "Original message:\n" << message << endl;
	cout << "\nAfter replace with match case:\n" << replaceWords(message, wordToReplace, replacement, enCase::matchCase) << endl;
	cout << "\nAfter replace with dont match case:\n" << replaceWords(message, wordToReplace, replacement, enCase::dontMatchCase) << endl;

	return 0;
}