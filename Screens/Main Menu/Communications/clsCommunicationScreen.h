#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"

#include"clsInputValidate.h"
#include"clsSendEmailScreen.h"
#include"clsSendedMailBoxScreen.h"
#include"clsReceivedMailBox.h"
#include"clsClearEmailBox.h"
class clsCommunicationScreen:protected clsScreen
{
   
    enum enCommunicationMenu
    {
        eMailBox=1,eSendedMailHistory ,eSendEmail,eClearSendedBox, eClearReceivedBox,eMainMenu
    };
    static enCommunicationMenu  _readCommunicationMenuChoice() {
        cout << "Please Enter Your choice from 1--->6 : ";
        int Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "\nPlease enter a valid Number from 1---->6 : ");
        return enCommunicationMenu(Choice);
    }
    static void _backToCommunicationMenu() {
        cout << "\n \t please enter any key to go bach to Communication Menu... ";
        system("pause>0");
        ShowCommunicationScreen();

    }
    static void _receivedMailBoxScreen() {
        clsReceivedBoxScreen::ShowReceivedMailBoxScreen();
    }
    static void _sendedMailHistoryScreen() {
     clsSendedMailBoxScreen::ShowSendedMailBoxScreen();
    }
    static void _sendEmailScreen() {
        clsSendEmailScreen::ShowSendEmailScreen();
    }
    static void _clearSendedMailBoxScreen() {
        clsClearEmailBox::ClearEmailScreen(clsUser::eSended);
    }
    static void _clearReceivedMailBoxScreen() {
        clsClearEmailBox::ClearEmailScreen(clsUser::eReceived);
    }
   static void _performCommunicationMenu(enCommunicationMenu MenuChoice) {
     
       switch (MenuChoice)
       {
       case clsCommunicationScreen::eMailBox:
           system("cls");
           _receivedMailBoxScreen();
           _backToCommunicationMenu();
           break;
       case clsCommunicationScreen::eSendedMailHistory:
           system("cls");
           _sendedMailHistoryScreen();
           _backToCommunicationMenu();
           break;
       case clsCommunicationScreen::eSendEmail:
           system("cls");
           _sendEmailScreen();
           _backToCommunicationMenu();
           break;
       case clsCommunicationScreen::eClearSendedBox:
           system("cls");
           _clearSendedMailBoxScreen();
           _backToCommunicationMenu();
           break;
       case clsCommunicationScreen::eClearReceivedBox:
           system("cls");
           _clearReceivedMailBoxScreen();
           _backToCommunicationMenu();

           break;

       case clsCommunicationScreen::eMainMenu:

           break;
       default:
           break;
       }
    }

public:
	static void ShowCommunicationScreen() {
        if (!(CheckPermissions(clsUser::eCommunication))) {
            return ;
        }
        system("cls");
		string Title = "\t Communication Screen";
		_drawScreenHeader(Title);
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCommunication Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Received Mail Box.\n";
        cout << setw(37) << left << "" << "\t[2] Sended Mail Box.\n";
        cout << setw(37) << left << "" << "\t[3] Send Email.\n";
        cout << setw(37) << left << "" << "\t[4] Clear Sended Mail Box.\n";
        cout << setw(37) << left << "" << "\t[5] Clear Received Mail Box.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _performCommunicationMenu(_readCommunicationMenuChoice());
	}
};

