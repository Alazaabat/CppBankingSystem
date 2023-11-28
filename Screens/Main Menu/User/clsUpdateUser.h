#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

#include"clsInputValidate.h"
class clsUpdateUser:protected clsScreen
{
private:
	static int ReadPermissions() {
		cout << "Do you Want to have all Permissions Y/N : ";
		char answer;
		cin >> answer;
		if (tolower(answer) == 'y')
			return -1;
		else {
			const int PERMISSIONS_SIZE = 9;
			string Permissions[PERMISSIONS_SIZE] = { "Show Clients","Add Client","Delete Client","Update Client","Find Client"
				,"Transactions","Manage Users","Login Register","Communication" };
			clsUser::enPermissions enPermissions[PERMISSIONS_SIZE] = { clsUser::eShowClients ,clsUser::eAddClient ,
			clsUser::eDeleteClient,clsUser::eUpdateClient,clsUser::eFindClient,clsUser::eTransactions,
			clsUser::eManageUsers,clsUser::eLoginRegister,clsUser::eCommunication };
			int PermissionValue = 0;
			cout << "Do you want give access to : \n";

			for (int i = 0;i < PERMISSIONS_SIZE;i++) {
				cout << Permissions[i] << " ? Y/N : ";
				cin >> answer;
				(tolower(answer) == 'y') ? PermissionValue += enPermissions[i] : PermissionValue;
			}
			return PermissionValue;
		}
	}
	static void ReadUserInfo(clsUser& User) {
		cout << "\nUpdate User Info:";
		cout << "\nFirstName      : ";
		User.SetFirstName(clsInputValidate::ReadString());
		cout << "LastName       : ";
		User.SetLastName(clsInputValidate::ReadString());
		cout << "Email          : ";
		User.SetEmail(clsInputValidate::ReadString());
		cout << "Phone          : ";
		User.SetPhone(clsInputValidate::ReadString());
		cout << "Password       : ";
		User.SetPassword(clsInputValidate::ReadString());
		cout << "Enter Permissions: ";
		User.SetPermissions(ReadPermissions());
	}
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
	static void ShowUpdateUserScreen() {
		string Title = "Update User";
		_drawScreenHeader(Title);
		string Username = clsInputValidate::ReadString("Please enter username you want to update : ");
		while (!clsUser::IsExist(Username))
		{
			cout << "\nError [ " + Username + " ]" << "Does not exist in the system !" << endl;
		  Username = clsInputValidate::ReadString("Please enter username you want to update : ");
		}
		clsUser User = clsUser::Find(Username);
		_printUser(User);
		cout << "Are you sure you want to delete this user ? Y/N : ";
		char answer;
		cin >> answer;
		if (tolower(answer) != 'y') {
			cout << "You choosed to Keep " << "[" << Username << "] User :-) ";
			return;
		}
		ReadUserInfo(User);
		clsUser::enSaveResult SaveResult = User.Save();
		switch (SaveResult)
		{
		case clsUser::eSaveSucceeded:
		cout << "[" << Username << "] Has been Updated Seccussfully :-) \\n";
		_printUser(User);

     	break;
		case clsUser::eSaveFailed:
		cout << "Updatin Failed " << "User [" << Username << "] is Empty ";
		break;
		default:
			break;
		}
	}
};

