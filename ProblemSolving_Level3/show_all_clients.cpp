/* Write a program to read clients file and show them on the screen. */

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

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

void printClientData()
{
	vector <stClientData> vClients = loadDataFromFile();
	cout << setw(55) << "Client List (" << vClients.size() << ") Client(s)." << endl;
	cout << string(111, '-') << endl;
	cout << "| " << setw(15) << left << "Account Number";
	cout << "| " << setw(15) << left << "Pin Code";
	cout << "| " << setw(40) << left << "Client Name";
	cout << "| " << setw(15) << left << "Phone";
	cout << "| " << setw(15) << left << "Balance" << setw(1) << '|' << endl;
	cout << string(111, '-') << endl;
	for (stClientData& client : vClients)
	{
		cout << "| " << setw(15) << left << client.accountNumber;
		cout << "| " << setw(15) << left << client.pinCode;
		cout << "| " << setw(40) << left << client.name;
		cout << "| " << setw(15) << left << client.phone;
		cout << "| " << setw(15) << left << std::setprecision(12) << client.accountBalance << setw(1) << '|' << endl;
	}
	cout <<  string(111, '-') << endl;
}

int main()
{
	printClientData();
	return 0;
}