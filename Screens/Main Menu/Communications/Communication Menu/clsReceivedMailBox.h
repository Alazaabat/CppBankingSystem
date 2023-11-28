#pragma once
#include<iostream>
#include"clsUser.h"

#include"clsScreen.h"
#include"clsUtil.h"
#include"Global.h"
class clsReceivedBoxScreen :clsScreen
{
private:
	static void _printEmailStruct(clsUser::stEmailDetails Email) {
		cout << "\t| " << left << setw(25) << Email.Date;
		cout << "| " << left << setw(20) << Email.Dealer;
		cout << "| " << left << setw(15) << Email.Title;
		cout << "| " << left << setw(15) << Email.Body;
	}

public:

	static void ShowReceivedMailBoxScreen() {
		vector <clsUser::stEmailDetails> ReceivedEmails = clsUser::GetReceivedEmails(LoginUser.UserName);
		string Title = "\t  Received Emails Screen";
		string SubTitle = "\t (" + to_string(ReceivedEmails.size()) + ") " + "Email(s)";
		_drawScreenHeader(Title, SubTitle);

		cout << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;

		cout << "\t| " << left << setw(25) << "Date";
		cout << "| " << left << setw(20) << "Sender (Sended From)";
		cout << "| " << left << setw(15) << "Title";
		cout << "| " << left << setw(15) << "Body";
		cout << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;


		if (ReceivedEmails.size() == 0)
			cout << "\t\t\t\tNo Emails Available In the System!";
		else {

			for (clsUser::stEmailDetails Email : ReceivedEmails)
			{
				_printEmailStruct(Email);
				cout << endl;
			}
		}
		cout << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;
	}
};

