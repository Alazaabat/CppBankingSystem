#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsUserList.h"
#include"clsAddNewUser.h"
#include"clsDeleteUser.h"
#include"clsUpdateUser.h"
#include"clsFindUser.h"
using namespace std;
class clsManageUsersScreen:clsScreen
{
private:
    enum enManageUsersMenu
    {
        ShowUsers=1,AddUser, DeleteUser, UpdateUser, FindUser,MainMenu
    };
    static  enManageUsersMenu _readManageUsersMenuChoice() {
        cout << "Enter Your Choice from 1---->6 : ";
        return enManageUsersMenu(clsInputValidate::ReadIntNumberBetween(1, 6, "\nPlease Enter Valid Number Between 1--->6 : "));
     }
    static void _backToMangeUsersScreen() {
        cout << "\n \t please enter any key to go bach to Transactions menu... ";
        system("pause>0");
        ManageUsersMenuScreen();
        
    }
    static void _showUserScreen() {
        clsUserList::UserListScreen();
    }
    static void _addNewUserScreen() {
        clsAddNewUser::ShowAddNewUserScreen();
    }
    static void _deleteUserScreen() {
        clsDeleteUser::ShowDeleteUserScreen();
    }
    static void _updateUserScreen() {
        clsUpdateUser::ShowUpdateUserScreen();
    }
    static void _findUserScreen() {
        clsFindUser::ShowFindUserScreen();
    }
    
    static void _performManageUsersMenuChoice(enManageUsersMenu Choice) {
   
        switch (Choice)
        {
        case clsManageUsersScreen::ShowUsers:
            system("cls");
            _showUserScreen();
            _backToMangeUsersScreen();
            break;
        case clsManageUsersScreen::AddUser:
            system("cls");
            _addNewUserScreen();
            _backToMangeUsersScreen();
            break;
        case clsManageUsersScreen::DeleteUser:
            system("cls");
            _deleteUserScreen();
            _backToMangeUsersScreen();
            break;
        case clsManageUsersScreen::UpdateUser:
            system("cls");
            _updateUserScreen();
            _backToMangeUsersScreen();
            break;
        case clsManageUsersScreen::FindUser:
            system("cls");
            _findUserScreen();
            _backToMangeUsersScreen();
            break;
        case clsManageUsersScreen::MainMenu:
            //empty its auto backing
            break;
        default:
            break;
        }
    }
public:
    static void ManageUsersMenuScreen() {
        if (!CheckPermissions(clsUser::eManageUsers)) {
            return;
        }
        system("cls");
        _drawScreenHeader("\t  Manage Users Menu");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _performManageUsersMenuChoice(_readManageUsersMenuChoice());
    }

};

