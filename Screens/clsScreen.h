#pragma once
#include <iostream>
#include"Global.h"

using namespace std;

class clsScreen
{
private: 

protected:
    static void _drawScreenHeader(string Title, string SubTitle = "")
    {
 
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________";
        cout << "\n\t\t\t\t\tUser : " << LoginUser.UserName<<endl;
        cout << "\t\t\t\t\tDate : " << clsDate::GetTodayFullDateInString() << "\n\n";


    }
    static bool CheckPermissions(clsUser::enPermissions Permission) {
        if (!((LoginUser.Permissions & Permission) == Permission)) {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else {
            return true;
        }
   }
};

