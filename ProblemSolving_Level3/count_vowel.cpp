/* Write a program to read a string then count all vowels in that string (Vowels are: a,e,i,o,u). */

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

bool isVowel(char character)
{
	character = tolower(character);
	return ((character == 'a') || (character == 'e') || (character == 'i') || (character == 'o') || (character == 'u'));
}

short countVowels(string message)
{
	short count = 0;
	for (short i = 0; i < message.length(); i++)
	{ 
		if (isVowel(message[i]))
			count++;
	}
	return count;
}

int main()
{
	string message = readString();

	printf("\nNumber of vowels is: %d\n", countVowels(message));

	return 0;
}