#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsMainMenu.h"
#include"Global.h"
using namespace std;
class clsTransferLogList:protected clsScreen
{
private:
	static void _printTransferLogRecord(clsBankClient::stTransferLog sTransferLog) {
		cout << "\t| " << left << setw(25) << sTransferLog.Date;
		cout << "| " << left << setw(10) << sTransferLog.Transferor;
		cout << "| " << left << setw(10) << sTransferLog.Recipient;
		cout << "| " << left << setw(15) << sTransferLog.TransferAmount;
		cout << "| " << left << setw(15) << sTransferLog.TransferorBalance;
		cout << "| " << left << setw(15) << sTransferLog.RecipientBalance;
		cout << "| " << left << setw(15) << sTransferLog.Login;

	}
public:
	static void ShowTransferLogScreen() {
		vector< clsBankClient::stTransferLog> VTransferLogs = clsBankClient::GetTransferLogList();
		string Title = "\Transfer Log List Screen";
		string SubTitle = "\t       (" + to_string(VTransferLogs.size()) + ")" + " Transfer";
		_drawScreenHeader(Title, SubTitle);


		cout << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;

		cout << "\t| " << left << setw(25) << "Date";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(10) << "d.Acct";
		cout << "| " << left << setw(15) << "Amount";
		cout << "| " << left << setw(15) << "s.Balance";
		cout << "| " << left << setw(15) << "d.Balance";
		cout << "| " << left << setw(15) << "Login";

		cout << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;


		if (VTransferLogs.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else {

			for (clsBankClient::stTransferLog TransferLog:VTransferLogs)
			{
				_printTransferLogRecord(TransferLog);
				cout << endl;
			}
		}
		cout << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;

	}


};

