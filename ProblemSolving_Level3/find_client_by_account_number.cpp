/* Write a program to find client by account number and print it to the screen. */

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

bool boolFindClientByAccounNumber(string accNumber, stClientData &client)
{
	vector <stClientData> vClients = loadDataFromFile();
	for (stClientData &fClient : vClients)
	{
		if (fClient.accountNumber == accNumber)
		{
			client = fClient;
			return true;
		}
	}
	return false;
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

void findClientByAccounNumber()
{
	string clientNum = ReadClientAccountNumber();
	stClientData client;
	if (boolFindClientByAccounNumber(clientNum, client) == true)
	{
		printClientCard(client);
	}
	else
		cout << "\nClient with Account Number (" << clientNum << ") is Not Found!";
}

int main()
{
	findClientByAccounNumber();
	return 0;
}
