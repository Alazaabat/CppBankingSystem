#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUtil.h"
class clsTotalBalanceScreen:protected clsScreen
{
private:
	static void _printClientRecordBalanceLine(clsBankClient Client)
{

	cout << "\t| " << setw(15) << left << Client.GetAccountNumber();
	cout << "| " << setw(40) << left << Client.FullName();
	cout << "| " << setw(35) << left << to_string(Client.AccountBalance) + "$" << "|";

}


public:
	static void ShowTotalBalanceScreen() {
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t  Total Balance";
		string SubTitle= "\t (" + to_string(vClients.size()) + ") " + "Client(s)";
		_drawScreenHeader(Title,SubTitle);

		
			cout << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;
		
			cout << "\t| " << left << setw(15) << "Accout Number";
			cout << "| " << left << setw(40) << "Client Name";
			cout << "| " << left << setw(12) << "Balance";
			cout << "\n\t_______________________________________________________";
			cout << "_________________________________________\n" << endl;
		
			double TotalBalances = clsBankClient::GetTotalBalances();
		
			if (vClients.size() == 0)
				cout << "\t\t\t\tNo Clients Available In the System!";
			else {
		
				for (clsBankClient Client : vClients)
				{
					_printClientRecordBalanceLine(Client);
					cout << endl;
				}
			}
				cout << "\n\t_______________________________________________________";
				cout << "_________________________________________\n" << endl;
				cout << "\t\t\t\t\t   Total Balances = " <<std::fixed<< TotalBalances << "$" << endl;
				cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances)+"$$" << ")"<<endl;

	}

};

