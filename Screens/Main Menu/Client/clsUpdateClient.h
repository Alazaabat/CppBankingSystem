#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
class clsUpdateClient:protected clsScreen
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
	static void _readClientInfo(clsBankClient& Client) {

		cout << "\nClinet Info:";
		cout << "\n____________________________";
		cout << "\nFirstName      : ";
		Client.SetFirstName(clsInputValidate::ReadString());
		cout << "LastName       : ";
		Client.SetLastName(clsInputValidate::ReadString());
		cout << "Email          : ";
		Client.SetEmail(clsInputValidate::ReadString());
		cout << "Phone          : ";
		Client.SetPhone(clsInputValidate::ReadString());
		cout << "Pin Code       : ";
		Client.SetPinCode(clsInputValidate::ReadString());
		cout << "Account Balance: ";
		Client.SetAccountBalance(clsInputValidate::ReadDblNumber());
		cout << "____________________________\n";


	}

public:
	static void ShowUpdateClientScreen() {
		if (!CheckPermissions(clsUser::eUpdateClient)) {
			return;
		}
		string Title = "\t  Update Client Screen";
		clsScreen::_drawScreenHeader(Title);
	

	
	string AccountNumber= clsInputValidate::ReadString("Please Enter Account Number of Person you want to Update : ");
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nClinet Doesn't exist !! : Please reEnter tThe Account Number : ";
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
	_readClientInfo(Client);


	clsBankClient::enSaveResults SaveResult = Client.Save();
	switch (SaveResult)
	{
	case clsBankClient::eSaveSucceeded:
		cout << "Save Done Successfully :-) For Account Number : [" << Client.GetAccountNumber() << "]";
		cout << endl;
		_printClient(Client);

		break;
	case clsBankClient::eSaveFailed:
		cout << "\nAccount was not saved because it was empty :(  ";
		break;
	default:
		break;
	}
	
	}

};

