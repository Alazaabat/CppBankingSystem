#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsBankClient.h"

using namespace std;
class clsShowClients :protected clsScreen
{
private :
    static void _printClientRecordLine(clsBankClient Client)
    {

        cout << "\t| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(7) << left << to_string((int)Client.AccountBalance)+'$' << "|";
        cout << endl;

    }

public:
	static void ShowClientsScreen() {

		if (!CheckPermissions(clsUser::eShowClients)) {
			return;
		}
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t   Client List Screen";
		string SubTitle = "\t   (" + to_string(vClients.size()) + ")" + "Client(s)";

		clsScreen::_drawScreenHeader(Title, SubTitle);
		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "\t| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vClients.size() == 0)
			cout << "\t\t There is no Client Available !!";
		else {
			for (const clsBankClient& Client : vClients)
				_printClientRecordLine(Client);

		}

		cout << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}


};



