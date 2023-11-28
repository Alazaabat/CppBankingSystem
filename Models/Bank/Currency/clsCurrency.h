#pragma once
#include<iostream>
#include<fstream>
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsString.h"
using namespace std;
class clsCurrency
{
private:
	enum enCurrnecyMode
	{
		eEmptyNode, eUpdateMode
	};
	string _countryName;
	string _currencyCode;
	string _currencyFullName;
	double _currencyValue;
	enCurrnecyMode _mode;
	static void _addDataToFile(string Line, string path) {
		fstream file;
		file.open(path, ios::app | ios::out);
		if (file.is_open()) {
			file << Line << endl;

			file.close();
		}
		else {
			cout << "Error !! [File doesn't Exist and Can't Create File !! ]";
		}
	}
	static string _convertCurrnecyObjectToLine(clsCurrency Currency, string Dill = "#//#") {
		string result = "";
		result += Currency.GetCountryName() + Dill;
		result += Currency.GetCurrencyCode() + Dill;
		result += Currency.GetCurrencyName() + Dill;
		result += to_string(Currency.CurrencyValue);
		return result;
	}
	static clsCurrency _convertLineToCurrencyObject(string Line) {
		vector< string> CurrencyInfo = clsString::Split(Line, "#//#");
		clsCurrency Currency(eUpdateMode, CurrencyInfo[0], CurrencyInfo[1], CurrencyInfo[2], stod(CurrencyInfo[3]));
		return Currency;
	}
	static vector<clsCurrency> _fromFileToVCurrencies() {
		string path = "Currencies.txt";
		fstream file;
		string line;
		vector<clsCurrency> Currencies;
		file.open(path, ios::in);
		if (file.is_open()) {
			while (getline(file, line))
			{
				clsCurrency Currency = _convertLineToCurrencyObject(line);
				Currencies.push_back(Currency);
			}
			file.close();
			return Currencies;
		}
		else {
			cout << "Error !! The is no file !!!";
			return{ {} };
		}

	}
	static void _fromVCurrenciesToFile(vector<clsCurrency> VCurrencies) {
		string path = "Currencies.txt";
		fstream file;
		file.open(path, ios::out);
		if (file.is_open()) {
			string CurrencyLine;
			for (const clsCurrency& Currency : VCurrencies) {
				CurrencyLine = _convertCurrnecyObjectToLine(Currency);
				file << CurrencyLine << endl;
			}

			file.close();
		}
		else {
			cout << "Error !! The in creating  file !!!";
			return;
		}

	}
	void _update() {
		vector<clsCurrency> Currencies = _fromFileToVCurrencies();
		for (clsCurrency& Currency : Currencies) {
			if (Currency.GetCurrencyName() == this->GetCurrencyName()) {
				Currency = *this;
				break;
			}
		}
		_fromVCurrenciesToFile(Currencies);
	}
public:
	clsCurrency(enCurrnecyMode Mode, string CountryName, string Currencycode, string CurrencyName, double Value) :
		_countryName(CountryName), _currencyCode(Currencycode), _currencyFullName(CurrencyName),
		_currencyValue(Value), _mode(Mode) {}

	string GetCountryName() { return _countryName; }
	string GetCurrencyCode() { return _currencyCode; }
	string GetCurrencyName() { return _currencyFullName; }
	double GetCurrencyValue() { return _currencyValue; }
	void SetCurrencyValue(double CurrencyValue) {
		_currencyValue = CurrencyValue;
		_update();
	}
	_declspec(property(get = GetCurrencyValue, put = SetCurrencyValue))double CurrencyValue;
	static clsCurrency GetEmptyCurrency() {
		return clsCurrency(eEmptyNode, "", "", "", 0);
	}
	bool IsEmpty() {
		return _mode == eEmptyNode;
	}
	static  clsCurrency FindByCountryCode(string CountryCode) {
		CountryCode = clsString::StrToUpper(CountryCode);
		vector< clsCurrency> Currencies = _fromFileToVCurrencies();
		for (clsCurrency& Currency : Currencies) {
			if (Currency.GetCurrencyCode() == CountryCode) {
				return Currency;
			}
		}
		return GetEmptyCurrency();
	}

	static  clsCurrency FindByCountryName(string CountryName) {
		CountryName = clsString::StrToUpper(CountryName);
		vector< clsCurrency> Currencies = _fromFileToVCurrencies();
		for (clsCurrency& Currency : Currencies) {
			if (clsString::StrToUpper(Currency.GetCountryName()) == CountryName) {
				return Currency;
			}
		}
		return GetEmptyCurrency();
	}
	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency Currency = FindByCountryCode(CurrencyCode);
		return  !Currency.IsEmpty();

	}
	static vector<clsCurrency> GetCurrenciesList() {
		return _fromFileToVCurrencies();
	}
	static string  GetCurrencyCodeByCountry(string CountryName) {
		clsCurrency Currency = clsCurrency::FindByCountryName(CountryName);
		return Currency.GetCurrencyCode();

	}
	float CurrnecyConvertToUSD(double Amount) {
		return (float)(Amount / _currencyValue);
	}
	float CurrnecyConvertToAnotherCurrency(clsCurrency Currency2,double Amount) {
		float AmountInUsd = CurrnecyConvertToUSD(Amount);
		return AmountInUsd * Currency2.CurrencyValue;
	}
};	 


