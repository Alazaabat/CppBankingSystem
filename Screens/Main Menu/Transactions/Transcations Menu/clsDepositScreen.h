#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

#include"clsInputValidate.h"

using namespace std;
class clsDepositScreen:clsScreen
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
	static void ShowDepositScreen() {
		string Titile = "\t  Deposit Client Screen";
		_drawScreenHeader(Titile);
		string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Account Number you want to Deposit in : ");
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Error !! " << "[ " << AccountNumber << " ] does not exist in the system !";
			AccountNumber = clsInputValidate::ReadString("\nPlease Enter Another Account Number : ");
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_printClient(Client);
		cout << "Please Enter Deposit Amount : ";
		float DepositAmount = clsInputValidate::ReadPositiveNumber("Please Enter a Positive Number :");
		cout << "Are you sure you want to deposit " << DepositAmount << "$ in Account [ " << AccountNumber << "] ? Y/N : ";
		char answer = clsInputValidate::ReadCharacter();
		if (tolower(answer) == 'n') {
			cout << "You choosed to Keep " << "[" << AccountNumber << "] Account :-) ";
			return;
		}
		Client.Deposit(DepositAmount);
		cout << "\nDeposit Successded :) Your New Balance is :" << Client.AccountBalance<<"$";

	

	}

};

