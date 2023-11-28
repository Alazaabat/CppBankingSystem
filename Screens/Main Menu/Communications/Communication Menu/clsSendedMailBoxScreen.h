#pragma once
#include<iostream>
#include"clsUser.h"

#include"clsScreen.h"
#include"clsUtil.h"
#include"Global.h"
class clsSendedMailBoxScreen:clsScreen
{
private:
	static void _printEmailStruct(clsUser::stEmailDetails Email) {
		cout << "\t| " << left << setw(25) << Email.Date;
		cout << "| " << left << setw(20) << Email.Dealer;
		cout << "| " << left << setw(15) << Email.Title;
		cout << "| " << left << setw(15) << Email.Body;
	}

public:

	static void ShowSendedMailBoxScreen(){
		vector <clsUser::stEmailDetails> SendedEmails = clsUser::GetSendedEmails(LoginUser.UserName);
	string Title = "\t  Sended Emails Screen";
	string SubTitle = "\t (" + to_string(SendedEmails.size()) + ") " + "Email(s)";
	_drawScreenHeader(Title, SubTitle);

	cout << "\n\t_______________________________________________________";
	cout << "________________________________________________________\n" << endl;

	cout << "\t| " << left << setw(25) << "Date";
	cout << "| " << left << setw(20) << "Receiver (Send To)";
	cout << "| " << left << setw(15) << "Title";
	cout << "| " << left << setw(15) << "Body";
	cout << "\n\t_______________________________________________________";
	cout << "________________________________________________________\n" << endl;


	if (SendedEmails.size() == 0)
		cout << "\t\t\t\tNo Emails Available In the System!";
	else {

		for (clsUser::stEmailDetails Email : SendedEmails)
		{
			_printEmailStruct(Email);
			cout << endl;
		}
	}
	cout << "\n\t_______________________________________________________";
	cout << "________________________________________________________\n" << endl;
}
};

