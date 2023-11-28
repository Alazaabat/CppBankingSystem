#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"

class clsDeleteClient: protected clsScreen
{
private:
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
	static void ShowDeleteClientScreen() {
		if (!CheckPermissions(clsUser::eDeleteClient)) {
			return;
		}
		string Title = "\t  Delete Client ";
		clsScreen::_drawScreenHeader(Title);
	
				cout << "Please Enter Account Number of The Account you want to Delete  : ";
				string AccountNumber = clsInputValidate::ReadString();
				while (!clsBankClient::IsClientExist(AccountNumber))
				{
					cout << "[ " << AccountNumber << " ] doesn't Exist in The System !" << endl;
					cout << "Please Enter Another Account Number : ";
					AccountNumber = clsInputValidate::ReadString();
				}
				clsBankClient Client = clsBankClient::Find(AccountNumber);
				_printClient(Client);
				cout << "\n Are you sure you want to delete " << "[" << AccountNumber << "] Y/N : ";
				char answer = clsInputValidate::ReadCharacter();
				if (tolower(answer) == 'n') {
					cout << "You choosed to Keep " << "[" << AccountNumber << "] Account :-) ";
					return;
				}
			
				if (Client.Delete()) {
					_printClient(Client);
					cout << "\n \t[" << AccountNumber << "] is Deleted Successfully :-) " << endl;
			
				}
				else
					cout << "\nError Account was not Deleted";
					
			
			
	}
};

