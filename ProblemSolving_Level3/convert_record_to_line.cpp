/* Write a program to read bank client data record and convert it to one line. */

#include<iostream>
#include<string>

using namespace std;

struct stClientData
{
	string accountNumber;
	string pinCode;
	string name;
	string phone;
	double accountBalance;
};

stClientData readClientData()
{
	stClientData client;
	cout << "Enter account number: ";
	getline(cin, client.accountNumber);
	cout << "Enter PinCode: ";
	getline(cin, client.pinCode);
	cout << "Enter Name: ";
	getline(cin, client.name);
	cout << "Enter phone: ";
	getline(cin, client.phone);
	cout << "Enter AccountBalance: ";
	cin >> client.accountBalance;

	return client;
}

string clientRecord(stClientData client, string seperater)
{
	string clientRecord = "";
	clientRecord += client.accountNumber + seperater;
	clientRecord += client.pinCode + seperater;
	clientRecord += client.name + seperater;
	clientRecord += client.phone + seperater;
	clientRecord += to_string(client.accountBalance);
	return clientRecord;
}

int main()
{
	cout << "Please Enter Client Data:\n\n";
	stClientData client;
	client = readClientData();
	cout << "\n\nClient Record for Saving is:\n";
	cout << clientRecord(client, "#//#");
	
	return 0;
}