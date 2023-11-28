#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
class clsFindClient:protected clsScreen
{
private:
	static void _printClient( clsBankClient& Client)  {
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
	static void ShowFindClientScreen() {
		if (!CheckPermissions(clsUser::eFindClient)) {
			return;
		}
		string Title = "\t  Find Client Screen";
		_drawScreenHeader(Title);
		string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Account Number you want to Find : ");
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Error !! " << "[ " << AccountNumber << " ] does not exist in the system !";
		    AccountNumber = clsInputValidate::ReadString("\nPlease Enter Another Account Number : ");
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_printClient(Client);


	}



};

