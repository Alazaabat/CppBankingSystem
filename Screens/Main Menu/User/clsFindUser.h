#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsFindUser:public clsScreen
{
private:
	static void _printUser(clsUser& User) {
		cout << "\nUser Info:";
		cout << "\n____________________________";
		cout << "\nFirstName      : " << User.FirstName;
		cout << "\nLastName       : " << User.LastName;
		cout << "\nFull Name      : " << User.FullName();
		cout << "\nPhone          : " << User.Phone;
		cout << "\nEmail          : " << User.Email << endl;
		cout << "UserName       : " << User.UserName << endl;
		cout << "Password       : " << User.Password << endl;
		cout << "Permissions    : " << User.Permissions << endl;
		cout << "____________________________\n";

	}

public:
	static void ShowFindUserScreen() {
		string Title = "\t Find User";
		_drawScreenHeader(Title);
		string Username = clsInputValidate::ReadString("Please enter Username you want to Find : ");
		while (!clsUser::IsExist(Username))
		{
			cout << "\n [" << Username << "] Does not exist in the system ! \n";
			Username = clsInputValidate::ReadString("Please enter Username you want to Find : ");
		}
		clsUser User = clsUser::Find(Username);
		if (!User.IsEmpty()) {
			cout << "User Found :-) \n";
				_printUser(User);
		}
		else {
			cout << "User not Found Error !";
		}
	}


};

