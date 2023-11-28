#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrency.h"

class clsCurrencyCalculator :public clsScreen
{
private:
	static void _printCurrencyCard(clsCurrency Currency, string Title) {
		cout << "\n---------------------------------";
		cout << "\n\t" << Title<<"\n";
		cout << "---------------------------------\n";
		cout << "\nCountry    :" << Currency.GetCountryName();
		cout << "\nCode       :" << Currency.GetCurrencyCode();
		cout << "\nName       :" << Currency.GetCurrencyName();
		cout << "\nRate(1$) = :" << Currency.GetCurrencyValue();
		cout << "\n---------------------------------\n";
	}
	static clsCurrency _readValidCurrency(string Message = "") {
		cout << Message;
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
	static void _performExchange(float Amount, clsCurrency& Currnecy1, clsCurrency& Currnecy2) {
		_printCurrencyCard(Currnecy1, "Convert From");
		float AmountInUsd = Currnecy1.CurrnecyConvertToUSD(Amount);
		cout << " " << Amount << " " << Currnecy1.GetCurrencyCode();
		cout << " = " << AmountInUsd << " USD \n";
		if (Currnecy1.GetCurrencyCode() == "USD")
			return;
		float AmountInCurrnecy2 = Currnecy1.CurrnecyConvertToAnotherCurrency(Currnecy2, Amount);
		cout << " " << Amount << " " << Currnecy1.GetCurrencyCode();
		_printCurrencyCard(Currnecy2, "Convert To");
		cout << " = " << AmountInCurrnecy2 << " " << Currnecy2.GetCurrencyCode();




	}

public:
	static void ShowCurrencyCalculatorScreen() {
		char answer;
		do {
			string Title = "Currency Calculator";
			_drawScreenHeader(Title);
			clsCurrency Currency1 = _readValidCurrency("\n Please Enter Code of Currency you want to convert from : ");
			clsCurrency Currency2 = _readValidCurrency("\n Please Enter Code of Currency you want to convert to : ");
			cout << "\n Enter Amount of Exchange : ";
			float Amount = clsInputValidate::ReadPositiveNumber("\n Please Enter Positive Amount : ");
			_performExchange(Amount, Currency1, Currency2);
			cout << "\nDo You want to Perform Another Currency Calculation ? Y/N : ";
			 answer = clsInputValidate::ReadCharacter();
			

			system("cls");
		} while (tolower(answer) != 'n');
	}
};

