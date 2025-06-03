/* Write a program to read a string then count each word in that string. */

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

short countEachWordInString(string message)
{
	string delimiter = " ";
	short postion = 0;
	string word;
	short count = 0;

	while ((postion = message.find(delimiter)) != string::npos)
	{
		word = message.substr(0, postion);
		if (word != "")
		{
			count++;
		}
		message.erase(0, postion + delimiter.length());
	}

	if (message != "")
	{
		count++;
	}

	return count;
}

int main()
{
	string message = readString();
	printf("\nThe number of words in your string is: %d\n", countEachWordInString(message));
	return 0;
}