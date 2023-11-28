#pragma once
#include <iostream>
#include <string>
#include<vector>
#include"clsPerson.h"
#include"clsString.h"
#include<fstream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;
class clsTransferScreen:public clsScreen
{
	static void _printClient(clsBankClient& Client) {
		cout << "\nInfo:";
		cout << "\n____________________________";
		cout << "\nFirstName      : " << Client.FirstName;
		cout << "\nLastName       : " << Client.LastName;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone << endl;
		cout << "Account Number : " << Client.GetAccountNumber() << endl;
		cout << "Pin Code       : " << Client.PinCode << endl;
		cout << "Account Balance: " << Client.AccountBalance << "$" << endl;
		cout << "____________________________\n";

	}

public:
	static void ShowTransferScreen() {
		string Title = "Transfer Screen";
		_drawScreenHeader(Title);
		cout << "Please enter Account you want to transfer from :";
		string WithdrawFrom = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(WithdrawFrom))
		{
			cout << "\n Client Does not exist in the system !! \n";
			cout << "Please enter Account you want to transfer from :";
		    WithdrawFrom = clsInputValidate::ReadString();
		}
		clsBankClient Transferor = clsBankClient::Find(WithdrawFrom);
		_printClient(Transferor);
		cout << endl;
		cout << "Please enter Account you want to transfer to :";
		string WithdrawTo = clsInputValidate::ReadString();
		cout << endl;
		while ((!clsBankClient::IsClientExist(WithdrawTo)) || (WithdrawTo == WithdrawFrom))
		{
			cout << "\n Client Does not exist in the system !! \n";
			cout << "Please enter Account you want to transfer to :";
			WithdrawTo = clsInputValidate::ReadString();
		}
		clsBankClient Recipient = clsBankClient::Find(WithdrawTo);
		_printClient(Recipient);
		cout << "Enter Transfer amount : ";
		double Amount = clsInputValidate::ReadDblNumber();
		while (Transferor.AccountBalance<Amount)
		{
			cout << "This Amount Exeecds Transfer Balance your ,Enter Another Amount :";
			Amount = clsInputValidate::ReadDblNumber();
			
		}
		cout << "\n Are Sure you want to perform this opeartion ? Y/N : ";
		char answer = clsInputValidate::ReadCharacter();
		if (tolower(answer) == 'n') {
		cout << "You choosed to Keep " << "[" << Transferor.GetAccountNumber() << "] Account Balance :-) ";
			return;
		}
		Transferor.Transfer(Amount, Recipient);
		cout << "Transfer Done Successfully  :-) ";
		_printClient(Transferor);
		_printClient(Recipient);


	}

};

