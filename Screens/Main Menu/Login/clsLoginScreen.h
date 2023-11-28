#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsMainMenu.h"
#include"Global.h"


class clsLoginScreen:protected clsScreen
{
private:
	static string _convertUserObjectToLine(clsUser User, string Dill) {
		string result = "";
		result += User.UserName + Dill;
		result += User.Password + Dill;
		result += to_string(User.Permissions);
		return result;

	}

	static bool _login() {
		string Username ;
		string Password ;
		const short MAX_LOGIN_TRIALS = 3;
		bool IsLoginFailed = false;
		int LoginTimes = 0;
		do
		{
			Username = clsInputValidate::ReadString("Please Enter User : ");
			Password = clsInputValidate::ReadString("Please Enter Password :");
			LoginUser = clsUser::Find(Username, Password);
			IsLoginFailed = LoginUser.IsEmpty();
			if (IsLoginFailed) {
				LoginTimes++;
				cout << "\n  Invalid Username/Password !! You Have  "<< MAX_LOGIN_TRIALS-LoginTimes <<" Login times remaining \n";

			}
		    if(LoginTimes==MAX_LOGIN_TRIALS) {
				cout << "\n\n\t\tSystem Locked !!\n\n";
				return false;
			}
		
		} while (IsLoginFailed);
		if (!LoginUser.IsEmpty())
			LoginUser.SaveInRegisterLogin();
		clsMainMenu::MainMenuScreen();
		return true;
	}


public:
	static void ShowLoginScreen() {
		string Title = "\t Login Screen ";
		_drawScreenHeader(Title);
		bool IsSuccess=_login();
		if (IsSuccess) {
			ShowLoginScreen();
		}
	}

};

