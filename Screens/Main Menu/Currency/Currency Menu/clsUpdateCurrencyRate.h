#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrency.h"
class clsUpdateCurrencyRate:protected clsScreen
{
private:
	static clsCurrency _readValidCurrnecy() {
		string Code = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCountryCode(Code);
		while (Currency.IsEmpty())
		{
			cout << "Currency Code Does not Exist !! \n";
			cout << "Please enter Currency Code : ";
			Code = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCountryCode(Code);
		}
		return Currency;
	}
	static void _PrintCurrencyCard(clsCurrency Currency) {
		cout << "\nCurrency Card:\n";
		cout << "---------------------------------\n";
		cout << "\nCountry    :" << Currency.GetCountryName();
		cout << "\nCode       :" << Currency.GetCurrencyCode();
		cout << "\nName       :" << Currency.GetCurrencyName();
		cout << "\nRate(1$) = :" << Currency.GetCurrencyValue();
		cout << "\n---------------------------------\n";
	}


public:

	static void ShowUpdateCurrenctRateScreen() {
		string Title = "     Update Currency Rate";
		_drawScreenHeader(Title);
		cout << "\n Enter Currency Code you want to update : ";
		clsCurrency Currency = _readValidCurrnecy();
		cout << endl;
		_PrintCurrencyCard(Currency);
		cout << "\n Are You sure you want to update Currency Rate ? Y/N : ";
		char answer = clsInputValidate::ReadCharacter();
		if (tolower(answer) == 'n') {
			cout << "You choosed to keep [ " << Currency.GetCurrencyCode() << " ] at " << "[ " << Currency.GetCurrencyValue() << "]";
			return;
		}
		cout << "\n --------------------\n";
		cout << "Enter New Rate ";
		float NewRate = clsInputValidate::ReadPositiveNumber();
		Currency.CurrencyValue = NewRate;
		cout << "\n Rate Changed Successfully :) \n";
		_PrintCurrencyCard(Currency);
	}
};

