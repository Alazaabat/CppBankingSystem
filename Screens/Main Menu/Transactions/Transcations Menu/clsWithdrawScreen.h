#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
class clsWithdrawScreen :clsScreen
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
	static void ShowWithdrawScreen() {
		string Titile = "\t  Withdraw Client Screen";
		_drawScreenHeader(Titile);
		string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Account Number you want to Withdraw from : ");
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Error !! " << "[ " << AccountNumber << " ] does not exist in the system !";
			AccountNumber = clsInputValidate::ReadString("\nPlease Enter Another Account Number : ");
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_printClient(Client);
		cout << "Please Enter Withdraw Amount : ";
		float DepositAmount = clsInputValidate::ReadPositiveNumber("Please Enter a Positive Number :");
		cout << "Are you sure you want to Withdraw " << DepositAmount << "$ from Account [ " << AccountNumber << "] ? Y/N : ";
		char answer = clsInputValidate::ReadCharacter();
		if (tolower(answer) == 'n') {
			cout << "You choosed to Keep " << "[" << AccountNumber << "] Account :-) ";
			return;
		}
		if (Client.Withdraw(DepositAmount))
		cout << "\Withdraw Successded :) Your New Balance is :" << Client.AccountBalance << "$";
		else {
			cout << "This Amount " << DepositAmount << "$ Exceed's your balance !";
			cout << "\n You are able to withdraw up to : " << Client.AccountBalance << "$";
			
		}

	}


};

