#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;
class clsAddNewClient:protected clsScreen
{
private:
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
	static void _printClient(clsBankClient& Client) {
		cout << "\nInfo:";
		cout << "\n____________________________";
		cout << "\nFirstName      : " << Client.FirstName;
		cout << "\nLastName       : " << Client.LastName;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " <<Client.Email ;
		cout << "\nPhone          : " << Client.Phone << endl;
		cout << "Account Number : " << Client.GetAccountNumber() << endl;
		cout << "Pin Code       : " << Client.PinCode << endl;
		cout << "Account Balance: " << Client.AccountBalance << "$" << endl;
		cout << "____________________________\n";

	}

public:
	static void ShowAddNewClientScreen() {
		if (!CheckPermissions(clsUser::eAddClient)) {
			return;
		}
		string Title = "\t  Add Client Screen ";
		clsScreen::_drawScreenHeader(Title);
		cout << "Please Enter Account Number of The Account you want to add : ";
		string AccoutnNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccoutnNumber))
		{
			cout << "[ " << AccoutnNumber << " ] is Already Exist in The System !" << endl;
			cout << "Please Enter Another Account Number : ";
			AccoutnNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::GetAddNewClientObject(AccoutnNumber);
		_readClientInfo(Client);
		clsBankClient::enSaveResults SaveResult = Client.Save();
		switch (SaveResult)
		{
		case clsBankClient::eSaveSucceeded:
			cout << "\n[" << AccoutnNumber << "] Sussefully Added :-)\n Here is the Client Infi : \n  ";
			_printClient(Client);
			break;
		case clsBankClient::eSaveFailed:
			cout << "\nAccount was not saved because it was empty :(  ";
			break;
		case clsBankClient::eSaveFaildAccountExist:
			cout << "\n[" << AccoutnNumber << "] Is Already Exist in The System  :-(  ";
		default:
			break;
		}

	}


};

