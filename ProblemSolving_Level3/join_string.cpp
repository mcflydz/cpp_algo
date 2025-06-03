/* Write a program to join vector of strings into one string with separators. */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string joinVectorOfStrings(vector <string>& vStrings, string delimiter)
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

int main()
{
	vector <string> vString{ {"Problem"},{"solving"},{"level"},{"3"} };

	cout << joinVectorOfStrings(vString, " ") << endl;

	return 0;
}