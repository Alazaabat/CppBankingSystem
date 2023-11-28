#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsDeleteUser: public clsScreen
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
	static void ShowDeleteUserScreen() {
		string Title = "\t Delete User";
		_drawScreenHeader(Title);
		string Username = clsInputValidate::ReadString("Please enter Username you want to Delete : ");
		while (!clsUser::IsExist(Username))
		{
			cout << "\n [" << Username << "]  Does not exist system ! \n";
			Username = clsInputValidate::ReadString("Please enter Username you want to Delete : ");
		}
		clsUser User = clsUser::Find(Username);
		_printUser(User);
		cout << "Are you sure you want to delete this user ? Y/N : ";
		char answer;
		cin >> answer;
		if (tolower(answer)!='y') {
			cout << "You choosed to Keep " << "[" << Username << "] User :-) ";
			return;
		}
		if (User.Delete()) {
			cout << "[" << Username << "] Has been Deleted Seccussfully :-) ";
		}
		else {
			cout << "\nError Account was not Deleted";
		}
	}
};

