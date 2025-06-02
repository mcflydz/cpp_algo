/* Write a program to read a character then check if it is a vowel or not (Vowels are: a,e,i,o,u). */

#include<iostream>
#include<string>

using namespace std;

char readCharacter()
{
	char character;
	cout << "Please enter a character:\n";
	cin >> character;
	return character;
}

bool isVowel(char character)
{ 
	character = tolower(character);
	return ((character == 'a') || (character == 'e') || (character == 'i') || (character == 'o') || (character == 'u'));
}

int main()
{
	char character = readCharacter();

	if (isVowel(character))
		cout << "\nYes letter '" << character << "' is a vowel\n";
	else
		cout << "\nNo letter '" << character << "' is not a vowel\n";

	return 0;
}