/* Write a program to read a string and read a character then count the character in that string (match case or not). */

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

short countCharacterMatchCaseInString(string message, char character)
{
	short count = 0;
	for (short i = 0; i < message.length(); i++)
	{
		if (message[i] == character)
			count++;
	}
	return count;
}

short countCharacterInString(string message, char character)
{
	short count = 0;
	for (short i = 0; i < message.length(); i++)
	{
		if (tolower(message[i]) == tolower(character))
			count++;
	}
	return count;
}


int main()
{
	string message = readString();
	char character = readCharacter();

	printf("\nLetter '%c' count = %d\n", character, countCharacterMatchCaseInString(message, character));
	printf("\nLetter '%c' or '%c' count = %d\n", tolower(character),toupper(character), countCharacterInString(message, character));

	return 0;
}