#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsUser.h"

#include"clsCurrency.h"
using namespace std;
class clsListCurrencies:protected clsScreen
{
private:
	static void _printCurrencyObject(clsCurrency Currency) {
		cout << "\t| " << left << setw(25) << Currency.GetCountryName();
		cout << "| " << left << setw(10) << Currency.GetCurrencyCode();
		cout << "| " << left << setw(40) << Currency.GetCurrencyName();
		cout << "| " << Currency.GetCurrencyValue()<<" "+ Currency.GetCurrencyCode();
	}


public:
	static void ShowListCurrenciesScreen() {
		vector <clsCurrency> Currencies = clsCurrency::GetCurrenciesList();
		string Title = "\t  Sended Emails Screen";
		string SubTitle = "\t (" + to_string(Currencies.size()) + ") " + "Currency(s)";
		_drawScreenHeader(Title, SubTitle);


		cout << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;

		cout << "\t| " << left << setw(25) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;


		if (Currencies.size() == 0)
			cout << "\t\t\t\tNo Currency Available In the System!";
		else {

			for (clsCurrency Currency : Currencies)
			{
				_printCurrencyObject(Currency);
				cout << endl;
			}
		}
		cout << "\n\t_______________________________________________________";
		cout << "________________________________________________________\n" << endl;
	}


};

