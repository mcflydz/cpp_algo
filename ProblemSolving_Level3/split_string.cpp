/* Write a program to read a string then make a function to split each word in vector. */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string readString()
{
	string message;
	cout << "Please enter your string:\n";
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

void printVector(vector <string> &vEachWordInString)
{
	cout << "\nWord in vector:\n";
	for (string& word : vEachWordInString)
	{
		cout << word << endl;
	}
}

int main()
{
	string message = readString();
	vector <string> vEachWordInString;

	vEachWordInString = splitString(message, " ");

	printf("\nTokens = %d\n", (int) vEachWordInString.size());

	printVector(vEachWordInString);

	return 0;
}