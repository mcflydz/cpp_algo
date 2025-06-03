/* Write a program to join vector of strings into one string with separators. */
/* Write a program to join array of string into one string with separators. */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string joinString(vector <string>& vStrings, string delimiter)
{
	string allInString;
	for (string& word : vStrings)
	{
		allInString.append(word);
		allInString.append(delimiter);
	}
	allInString.erase(allInString.length() - delimiter.length(), string::npos);
	return allInString;
}

string joinString(string arrStrings[], short arrayLength, string delimiter)
{
	string allInString;
	for (short i = 0; i < arrayLength ; i++)
	{
		allInString.append(arrStrings[i]);
		allInString.append(delimiter);
	}
	allInString.erase(allInString.length() - delimiter.length(), string::npos);
	return allInString;
}

int main()
{
	vector <string> vString{ {"Problem"},{"solving"},{"level"},{"3"} };
	string arrString[] = { "Problem","solving","level","3" };

	cout << "Vector after join:\n";
	cout << joinString(vString, " ") << endl;

	cout << "\nArray after join:\n";
	cout << joinString(arrString, 4, " ") << endl;

	return 0;
}