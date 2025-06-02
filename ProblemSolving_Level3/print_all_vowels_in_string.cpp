/* Write a program to read a string then print all vowels in that string (Vowels are: a,e,i,o,u). */

#include<iostream>
#include<string>
#include<iomanip>

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

void printVowelsInString(string message)
{
	cout << "\nVowels in string are: ";
	for (short i = 0; i < message.length(); i++)
	{
		if (isVowel(message[i]))
			cout << setw(3) << left << message[i];
	}
}

int main()
{
	string message = readString();

	printVowelsInString(message);

	return 0;
}