#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

#include"clsInputValidate.h"
#include"clsMainMenu.h"
#include"Global.h"

class clsLoginRegisterScreen: protected clsScreen
{
private:
	static void _printLoginRecord(clsUser::stLoginDetails sLogin) {
		cout << "\t      | " << left << setw(30) << sLogin.Date;
		cout << "| " << left << setw(20) << sLogin.Username;
		cout << "| " << left << setw(10) << sLogin.Password;
		cout << "| " << left << setw(12) << sLogin.Permissions;
	}

	
	

public:
	static void ShowLoginRegisterScreen() {
		if (!CheckPermissions(clsUser::eLoginRegister)) {
			return;
		}
		vector< clsUser::stLoginDetails> VLoginDetails=clsUser::GetLoginRegisterList();
		string Title = "\tLogin Register Screen";
		string SubTitle = "\t       (" + to_string(VLoginDetails.size()) + ")" + " Login";
		_drawScreenHeader(Title, SubTitle);


		cout << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << "\t      | " << left << setw(30) << "Date";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permessions";
		cout << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;


		if (VLoginDetails.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else {

			for (clsUser::stLoginDetails Login : VLoginDetails)
			{
				_printLoginRecord(Login);
				cout << endl;
			}
		}
		cout << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

	}


};

