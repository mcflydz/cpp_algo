/* Write a program to read a string and reverse its words. */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string readString()
{
	string message = "";
	cout << "Enter your string:\n";
	getline(cin, message);
	return message;
}

vector <string> splitString(string message, string delimiter)
{
	vector <string> vEachWordInString;
	short postion = 0;
	string word;

	while ((postion = message.find(delimiter)) != string::npos)
	{
		word = message.substr(0, postion);
		if (word != "")
		{
			vEachWordInString.push_back(word);
		}
		message.erase(0, postion + delimiter.length());
	}

	if (message != "")
	{
		vEachWordInString.push_back(message);
	}

	return vEachWordInString;
}

string reverseWords(string message)
{
	string reverseWords = "";
	vector <string> vSplitString = splitString(message, " ");

	for (int i = vSplitString.size() - 1; i >= 0; i--)
	{
		reverseWords += vSplitString.at(i) + " ";
	}
	reverseWords.pop_back();

	return reverseWords;
}

string reverseWordsUsingIterator(string message)
{
	string reverseWords = "";
	vector <string> vSplitString = splitString(message, " ");
	vector <string>::iterator iter = vSplitString.end();

	while (iter != vSplitString.begin())
	{
		--iter;
		reverseWords += *iter + " ";
	}
	reverseWords.pop_back();

	return reverseWords;
}

int main()
{
	string message = readString();
	cout << "\nReverse words:\n" << reverseWords(message) << endl;
	cout << "\nReverse words:\n" << reverseWordsUsingIterator(message) << endl;
	return 0;
}