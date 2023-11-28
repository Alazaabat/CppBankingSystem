#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>

#include"clsInputValidate.h"
#include"clsShowClients.h"
#include"clsAddNewClient.h"
#include"clsDeleteClient.h"
#include"clsFindUser.h"
#include"clsUpdateClient.h"
#include"clsFindClient.h"
#include"clsTransactionsMenu.h"
#include"clsManageUsers.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsCommunicationScreen.h"
#include"clsCurrencyExchangeScreen.h"


class clsMainMenu : protected clsScreen
{
private:
    enum enMainMenuChoice
    {
        eShowClients = 1, eAddClients, eDeleteClients, eUpdateClients, eFindClients, eTransactionsMenu, eManageUsersMenu, eLoginRegister,eCommunication,eCurrencyExchange, eLogout
    };


    static enMainMenuChoice _readMainMenuChoice() {
        cout << "Enter Your Choice from 1---->11 : ";
        
        return enMainMenuChoice(clsInputValidate::ReadIntNumberBetween(1, 11, "\nPlease Enter Valid Number Between 1--->11 : "));
    }
    static void _backToMainMenu() {
        cout << "\n \t please enter any key to go bach to Main menu... ";
        system("pause>0");

        MainMenuScreen();

    }
    static void _showClientsScreen() {
        clsShowClients::ShowClientsScreen();

    }
    static void _addClientssScreen() {
        clsAddNewClient::ShowAddNewClientScreen();

    }
    static void _deleteClientsScreen() {
        clsDeleteClient::ShowDeleteClientScreen();

    }
    static void _updateClientsScreen() {
        clsUpdateClient::ShowUpdateClientScreen();

    }
    static void _findClientsScreen() {
        clsFindClient::ShowFindClientScreen();
    }
    static void _transactionsMenuScreen() {
       clsTransactionsMenu::TransactionsMenuScreen();

    }
    static void _manageUsersMenuScreen() {
        clsManageUsersScreen::ManageUsersMenuScreen();
    }
    static void _loginRegisterScreen() {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    static void _communicationScreen() {
        clsCommunicationScreen::ShowCommunicationScreen();
    }
    static void _currencyExchangeScreen() {
        clsCurrencyExchangeScreen::CurrencyExchangeMenuScreen();
    }
    static void _logoutScreen() {
        LoginUser = clsUser::Find("", "");
    }
  
    static void  _performMainMenu(enMainMenuChoice Choice) {
        system("cls");
        switch (Choice)
        {
        case clsMainMenu::eShowClients:
            _showClientsScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eAddClients:
            _addClientssScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eDeleteClients:
            _deleteClientsScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eUpdateClients:
            _updateClientsScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eFindClients:
            _findClientsScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eTransactionsMenu:
            _transactionsMenuScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eManageUsersMenu:
            _manageUsersMenuScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eLoginRegister:
            _loginRegisterScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eCommunication:
            _communicationScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eCurrencyExchange:
            _currencyExchangeScreen();
            _backToMainMenu();
            break;
        case clsMainMenu::eLogout:
            _logoutScreen();
            break;
        default:
            break;
        }

    }

public:
    static void MainMenuScreen() {
        system("cls");
        _drawScreenHeader("\t\tMain Menu");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Communication.\n";
        cout << setw(37) << left << "" << "\t[10] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[11] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _performMainMenu(_readMainMenuChoice());
    }
 

};

