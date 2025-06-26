/* Write a program to delete client by account number. */

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;
const string clientsFileName = "client_data.txt";

struct stClientData
{
	string accountNumber;
	string pinCode;
	string name;
	string phone;
	double accountBalance;
	bool markForDelete = false;
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
	client.accountNumber = vClientData[0];
	client.pinCode = vClientData[1];
	client.name = vClientData[2];
	client.phone = vClientData[3];
	client.accountBalance = stod(vClientData[4]);
	return client;
}

string convertRecordToLine(stClientData client, string seperater)
{
	string clientRecord = "";
	clientRecord += client.accountNumber + seperater;
	clientRecord += client.pinCode + seperater;
	clientRecord += client.name + seperater;
	clientRecord += client.phone + seperater;
	clientRecord += to_string(client.accountBalance);
	return clientRecord;
}

vector <stClientData> loadDataFromFile()
{
	vector <stClientData> vClients;
	fstream myFile;
	myFile.open(clientsFileName, ios::in);
	if (myFile.is_open())
	{
		stClientData client;
		string line;
		string delimiter = "//#//";
		while (getline(myFile, line))
		{
			client = convertLineToRecord(line, delimiter);
			vClients.push_back(client);
		}
		myFile.close();
	}
	return vClients;
}

void markClientForDeleteByAccounNumber(string accNumber, stClientData &client)
{
	if (client.accountNumber == accNumber)
	{
		client.markForDelete = true;
	}
}

void printClientCard(stClientData client)
{
	
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number  : " << client.accountNumber;
	cout << "\nPin Code       : " << client.pinCode;
	cout << "\nName           : " << client.name;
	cout << "\nPhone          : " << client.phone;
	cout << "\nAccount Balance: " << client.accountBalance << endl;
}

string ReadClientAccountNumber()
{
	string accountNumber = "";
	cout << "Enter AccountNumber: ";
	cin >> accountNumber;
	return accountNumber;
}

bool findClientByAccounNumber(string accountNumber, vector <stClientData> &vClients)
{
	for (stClientData& client : vClients)
	{
		if (client.accountNumber == accountNumber)
		{
			printClientCard(client);
			return true;
		}
	}
	return false;
}

void deleteAndSaveToFileAfterDelete(vector <stClientData> &vClients, stClientData &client, string accountNumber)
{
	fstream myFile;
	myFile.open(clientsFileName, ios::out);
	if (myFile.is_open())
	{
		string delimiter = "//#//";
		for (stClientData& client : vClients) 
		{
			markClientForDeleteByAccounNumber(accountNumber, client);
			if (client.markForDelete == false)
			{
				string line = convertRecordToLine(client, delimiter);
				myFile << line << endl;
			}
		}
		myFile.close();
	}
}

void deleteClient(vector <stClientData> &vClients)
{
	stClientData client;
	string accountNumber = ReadClientAccountNumber();
	bool findClient = findClientByAccounNumber(accountNumber, vClients);
	char confirmeDeletion;
	if (findClient == true)
	{
		do {
			cout << "\nAre you sure you want to delete this client? y/n? ";
			cin >> confirmeDeletion;
		} while (tolower(confirmeDeletion) != 'y' && tolower(confirmeDeletion) != 'n');

		if (confirmeDeletion == 'y')
		{
			deleteAndSaveToFileAfterDelete(vClients, client, accountNumber);
			vClients = loadDataFromFile();
			cout << "\nClient deleted successfully.\n";
		}
	}
	if (findClient == false)
	{
		cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!\n";
	}
}

int main()
{
	vector <stClientData> vClients = loadDataFromFile();
	deleteClient(vClients);
	return 0;
}
