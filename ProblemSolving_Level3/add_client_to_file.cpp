/* Write a program to ask you to enter clients and save them to file. */

#include<iostream>
#include<string>
#include<fstream>

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
	getline(cin >> ws, client.accountNumber);
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

string convertClientDataToString(stClientData client, string seperater)
{
	string clientRecord = "";
	clientRecord += client.accountNumber + seperater;
	clientRecord += client.pinCode + seperater;
	clientRecord += client.name + seperater;
	clientRecord += client.phone + seperater;
	clientRecord += to_string(client.accountBalance);
	return clientRecord;
}

void saveDataLineToFile(string fileName, string dataLine)
{
	fstream client_data;
	client_data.open(fileName, ios::out | ios::app);
	if (client_data.is_open())
	{
			client_data << dataLine << endl;
			client_data.close();
	}
}

void addNewClient()
{
	stClientData client = readClientData();
	string dataLine = convertClientDataToString(client, "//#//");
	
	saveDataLineToFile("client_data.txt", dataLine);
}

void addClient()
{
	char addMore;
	do
	{
		system("cls");
		cout << "Adding new client:\n\n";
		addNewClient();
		cout << "\nClient added successfully, do you want to add more? Y or N : ";
		cin >> addMore;
	} while (toupper(addMore) == 'Y');
}

int main()
{
	addClient();
	return 0;
}