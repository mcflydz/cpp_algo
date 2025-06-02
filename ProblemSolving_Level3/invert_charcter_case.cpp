/* Write a program to read a character then invert it's case and print it. */

#include<iostream>
#include<string>

using namespace std;

char readCharacter()
{
	char message = 0;
	cout << "Please enter a character:\n";
	cin >> message;
	return message;
}

char invertCharacterCase(char message)
{
	if (message >= 97 && message <= 122)
		return message = toupper(message);
	else if (message >= 65 && message <= 90)
		return message = tolower(message);
	else
		return message;
}

char invertCharacterCaseUsingString(char message)
{
	return isupper(message) ? tolower(message) : toupper(message);
}

int main()
{
	char message = readCharacter();

	cout << "\nCharacter after inverting case:\n";
	cout << invertCharacterCase(message);

	cout << "\nCharacter after inverting case using string:\n";
	cout << invertCharacterCaseUsingString(message);
	return 0;
}