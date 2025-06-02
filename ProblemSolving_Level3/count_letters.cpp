/* Write a program to read a string and read a character then count the character in that string. */

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

char readCharacter()
{
	char character;
	cout << "\nPlease enter a character:\n";
	cin >> character;
	return character;
}

short countCharacterInString(string message, char character)
{
	short count = 0;
	for (short i = 0; i < message.length(); i++)
	{
		if (message[i] == character)
			count++;
	}
	return count;
}


int main()
{
	string message = readString();
	char character = readCharacter();

	printf("\nLetter '%c' count = %d\n", character, countCharacterInString(message, character));

	return 0;
}