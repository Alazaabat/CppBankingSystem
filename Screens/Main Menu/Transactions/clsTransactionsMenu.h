#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogList.h"
using namespace std;
class clsTransactionsMenu :protected clsScreen
{
private:
    enum enTransactionsMenu
    {
        eDeposit=1,eWithdraw,eShowTotalBalance,eTransfer,eTrasferList,eMainMenu
    };
    static enTransactionsMenu _readTransactionsMenuChoice() {
        cout << "Enter Your Choice from 1---->6 : ";
        return enTransactionsMenu(clsInputValidate::ReadIntNumberBetween(1, 6, "\nPlease Enter Valid Number Between 1--->5 : "));
    

    }
    static void _backtToTransactionsMenu() {
        cout << "\n \t please enter any key to go bach to Transactions menu... ";
        system("pause>0");
        TransactionsMenuScreen();
    }
    static void _depositScreen() {
        clsDepositScreen::ShowDepositScreen();

    }
    static void _withdrawScreen() {
        clsWithdrawScreen::ShowWithdrawScreen();

    }
    static void _showTotalBalance() {
        clsTotalBalanceScreen::ShowTotalBalanceScreen();

    }
    static void _showTransferScreen() {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _showTransferListScreen() {
        clsTransferLogList::ShowTransferLogScreen();
    }
    static void _performTransactionsMenuChoice(enTransactionsMenu Choice) {
  
        switch (Choice)
        {
        case clsTransactionsMenu::eDeposit:
            system("cls");
            _depositScreen();
            _backtToTransactionsMenu();
            break;
        case clsTransactionsMenu::eWithdraw:
            system("cls");
            _withdrawScreen();
            _backtToTransactionsMenu();
            break;
        case clsTransactionsMenu::eShowTotalBalance:
            system("cls");
            _showTotalBalance();
            _backtToTransactionsMenu();
            break;
        case clsTransactionsMenu::eTransfer:
            system("cls");
            _showTransferScreen();
            _backtToTransactionsMenu();
            break;
        case clsTransactionsMenu::eTrasferList:
            system("cls");
            _showTransferListScreen();
            _backtToTransactionsMenu();

                break;
        case clsTransactionsMenu::eMainMenu:
            
            break;
        default:
            break;
        }

    }
public:
    static void TransactionsMenuScreen() {
        if (!CheckPermissions(clsUser::eTransactions)) {
            return;
        }
        system("cls");
        _drawScreenHeader("\t  Transactions Menu");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Show Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer List.\n";
        cout << setw(37) << left << "" << "\t[6] Back To Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _performTransactionsMenuChoice(_readTransactionsMenuChoice());
    }


};
