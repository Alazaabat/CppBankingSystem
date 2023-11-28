#pragma once
#include"clsUser.h"
#include"clsInputValidate.h"
#include<iostream>
#include"clsScreen.h"
#include"Global.h"
using namespace std;

class clsClearEmailBox :clsScreen
{
private:

	
public:
	void static ClearEmailScreen(clsUser::enClearBox Choice) {
		string Titles[] = { "Clear Received Mail Box","Clear Sended Mail Box" };
		string Title = Titles[Choice];
		_drawScreenHeader(Title);

		cout << "Enter User Password to clear the Mail Box : ";
		string Password = clsInputValidate::ReadString();
		while (Password!=LoginUser.Password)
		{
			cout << " \nIvalid Password !! \nEnter User Password to clear the Mail Box : ";
			Password = clsInputValidate::ReadString();

		}
		cout << "\nAre Your sure You want to Clear Email Box Y/N :: ";
		char answer = clsInputValidate::ReadCharacter();
		if (tolower(answer) == 'n') {
			cout << "\n You choosed to keep Mail Box :) ";
			return;
		}
		LoginUser.Clear(Choice);
		cout << "\n \t Clear Done Successfully :-) \n";
	}


};

