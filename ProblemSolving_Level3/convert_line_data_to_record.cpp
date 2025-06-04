/* Write a program to convert line data to record and print it. */

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct stClientData
{
	string accountNumber;
	string pinCode;
	string name;
	string phone;
	double accountBalance;
};

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

stClientData convertLineToRecord(string message, string delimiter)
{
	vector <string> vClientData = splitString(message, delimiter);
	stClientData client;
	client.accountNumber = vClientData.at(0);
	client.pinCode = vClientData.at(1);
	client.name = vClientData.at(2);
	client.phone = vClientData.at(3);
	client.accountBalance = stod (vClientData.at(4));
	return client;
}

void printClientData(stClientData client)
{
	cout << "Account number : " << client.accountNumber << endl;
	cout << "Pin Code       : " << client.pinCode << endl;
	cout << "Name           : " << client.name << endl;
	cout << "Phone          : " << client.phone << endl;
	cout << "Account Balance: " << client.accountBalance << endl;
}

int main()
{
	string lineRecord = "A150#//#1234#//#Lakhdar Chettouh#//#0123456789#//#1234.56";
	cout << "Line Record is:\n" << lineRecord << endl;
	
	cout << "\nThe following is the extracted client record:\n";
	printClientData(convertLineToRecord(lineRecord, "#//#"));

	return 0;
}