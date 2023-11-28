#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsAddNewUser :public clsScreen
{
private:
	
	static int ReadPermissions() {
		cout << "Do you Want to have all Permissions Y/N : ";
		char answer;
		cin >> answer;
		if (tolower(answer)== 'y')
			return -1;
		else {
			const int PERMISSIONS_SIZE = 9;
			string Permissions[PERMISSIONS_SIZE] = { "Show Clients","Add Client","Delete Client","Update Client","Find Client"
				,"Transactions","Manage Users","Login Register","Communication"};
		clsUser::enPermissions enPermissions[PERMISSIONS_SIZE] = { clsUser::eShowClients ,clsUser::eAddClient ,
		clsUser::eDeleteClient,clsUser::eUpdateClient,clsUser::eFindClient,clsUser::eTransactions,
		clsUser::eManageUsers,clsUser::eLoginRegister,clsUser::eCommunication };
		int PermissionValue = 0;
		cout << "Do you want give access to : \n";

		for (int i = 0;i <PERMISSIONS_SIZE;i++) {
				cout << Permissions[i] << " ? Y/N : ";
				cin >> answer;
				(tolower(answer) == 'y') ? PermissionValue += enPermissions[i] : PermissionValue;
		}
		return PermissionValue;
		}
	}
	static void ReadUserInfo(clsUser& User) {
		cout << "\nUser Info:";
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
		cout << "\nEmail          : " << User.Email<<endl;
		cout << "UserName       : " << User.UserName<< endl;
		cout << "Password       : " << User.Password << endl;
		cout << "Permissions    : " << User.Permissions << endl;
		cout << "____________________________\n";

	}
public:
	static void ShowAddNewUserScreen() {
		string Title = "\t Add New User";
		_drawScreenHeader(Title);
		string Username = clsInputValidate::ReadString("Please enter Username you want to add : ");
		while (clsUser::IsExist(Username))
		{
			cout << "\n [" << Username << "] is Already exist in the system ! \n";
			Username = clsInputValidate::ReadString("Please enter Username you want to add : ");
		}
		clsUser User = clsUser::GetAddNewUserObject(Username);
		ReadUserInfo(User);
		clsUser::enSaveResult SaveResult = User.Save();
		switch (SaveResult)
		{
		case clsUser::eSaveSucceeded:
			cout << "\nUser [" << Username << "] Addeded Successfully :-) ";
			_printUser(User);
			cout << endl;
			break;
		case clsUser::eSaveFailed:
			cout << "Adding Failed " << "User [" << Username << "] is Empty ";
			break;
		case clsUser::eSaveFaildAccountExist:
			cout << "Adding Failed " << "User [" << Username << "] is Already Exist ";
			break;
		default:
			break;
		}

	}
	



};

