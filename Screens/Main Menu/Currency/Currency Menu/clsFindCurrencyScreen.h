#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsUser.h"

#include"clsCurrency.h"
class clsFindCurrencyScreen:protected clsScreen
{
private:
	static void _printCurrencyCard(clsCurrency Currency) {
		cout << "\nCurrency Card:\n";
		cout << "---------------------------------\n";
		cout << "\nCountry    :" << Currency.GetCountryName();
		cout << "\nCode       :" << Currency.GetCurrencyCode();
		cout << "\nName       :" << Currency.GetCurrencyName();
		cout << "\nRate(1$) = :" << Currency.GetCurrencyValue();
		cout << "\n---------------------------------\n";
	}

	enum enFindType
	{
		eCode = 1,eCountry
	};
	static clsCurrency _readCodeChoice() {
		cout << "Please enter Currency Code : ";
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
	static clsCurrency _readCountryNameChoice() {
		cout << "Please enter Country  : ";
		string Country = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCountryName(Country);
		while (Currency.IsEmpty())
		{
			cout << "Country Code Does not Exist !! \n";
			cout << "Please enter Country  : ";
			Country = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCountryName(Country);
		}
		return Currency;
	}
public:
	static void ShowFindCurrencyScreen() {
		string Title = "\t Find Currency";
		_drawScreenHeader(Title);
		clsCurrency Currency = clsCurrency::GetEmptyCurrency();
		cout << "Find By : [1] Code , [2] Country : ";
		enFindType FindChoice = enFindType(clsInputValidate::ReadIntNumberBetween(1, 2, "\nPlease Enter a Valid Number Between 1-->2 : "));
		switch (FindChoice)
		{
		case clsFindCurrencyScreen::eCode:
			Currency = _readCodeChoice();


			break;
		case clsFindCurrencyScreen::eCountry:
			Currency = _readCountryNameChoice();
			break;
		default:
			break;
		}
		cout << "\n \t Currency Founded :-) \n";
		_printCurrencyCard(Currency);

	}
};

