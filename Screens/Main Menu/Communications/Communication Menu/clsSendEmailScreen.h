#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
class clsSendEmailScreen :protected clsScreen
{
private:

public:
	static void ShowSendEmailScreen() {
		string Title = "\t Send Email Screen";
		_drawScreenHeader(Title);
		cout << "\nPlease enter User You want to send him the Email : ";
		string ReceiverUsername = clsInputValidate::ReadString();
		while (!clsUser::IsExist(ReceiverUsername)|| ReceiverUsername==LoginUser.UserName)
		{
			cout << "\n Error [" << ReceiverUsername << "] Does not exist !";
		  ReceiverUsername = clsInputValidate::ReadString("\nPlease Enter an existant User : ");
		}
		clsUser Receiver = clsUser::Find(ReceiverUsername);
		cout << "\n Please enter Title of Mail : ";
		Title = clsInputValidate::ReadString();
		cout << "\n Please enter Body of Mail : ";
		string Body = clsInputValidate::ReadString();
		cout << "\nAre u sure you want to send email to [ " << ReceiverUsername << " ] ? Y/N :";
		char ansewr = clsInputValidate::ReadCharacter();
		if (tolower(ansewr) == 'n') {
			cout << "\n \tYou choosed to no send email :( ";
			return;
		}
		LoginUser.SendMail(Title, Body, Receiver);

		cout << "\n \tEmail Sended Successfully :-)";


	}
};

