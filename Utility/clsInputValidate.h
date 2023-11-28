#pragma once
#pragma warning(disable :4996)
#include<iostream>
#include<string>
#include"clsString.h"
#include"clsDate.h"
#include<math.h>
#include<cstdlib>

class clsInputValidate {
public:
	static bool IsNumberBetween(int Number1, int From, int To) {
		return !(Number1 < From || Number1>To);
	}
	static bool IsNumberBetween(double Number1, double From, double To) {
		return !(Number1 < From || Number1>To);
	}
	static bool IsDateBetween(clsDate Date1, clsDate From, clsDate To) {
		clsPeriod Period(From, To);
		clsPeriod Peroid2(To, From);
		return Period.IsDateInPeriod(Date1)||Peroid2.IsDateInPeriod(Date1);
	}
	static int ReadIntNumber(string FaildMessage = "Please Enter Valid Int Number",string ReadMessage="") {
		cout << ReadMessage;
		int Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << FaildMessage;
			cin >> Number;
			
		}
		return Number;
	}
	static double ReadDblNumber(string FaildMessage = "Please Enter Valid Int Number", string ReadMessage = "") {
		cout << ReadMessage;
		double Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << FaildMessage;
			cin >> Number;

		}
		return Number;
	}
	static int ReadIntNumberBetween(int From,int To,string FaildMessage = "Please Enter Valid Int Number", string ReadMessage = "") {
		cout << ReadMessage;
		int Result;
		Result = ReadIntNumber(FaildMessage, ReadMessage);
		while (!IsNumberBetween(Result,From,To)) {
			cout << FaildMessage;
			Result = ReadIntNumber(FaildMessage, ReadMessage);
		 }
		return Result;
	}
	static double ReadDblNumberBetween(double From, double To, string FaildMessage = "Please Enter Valid Int Number", string ReadMessage = "") {
		cout << ReadMessage;
		double Result;
		Result = ReadDblNumber(FaildMessage, ReadMessage);
		while (!IsNumberBetween(Result, From, To)) {
			cout << FaildMessage;
			Result = ReadDblNumber(FaildMessage, ReadMessage);
		}
		return Result;
	}
	static bool IsValidDate(const clsDate &Date) {
		return clsDate::IsValidDate(Date);
	}
	static string ReadString(string Message="") {
		cout << Message;
		string c;
		getline(cin >> ws, c);
		return c;
	}
	static char ReadCharacter() {
		char i;
		cin >> i;
		return i;
	}
	static float ReadPositiveNumber(string FaildMessage="") {
		float number;
		cin >> number;
		while (number<0)
		{
			cout << "\n" << FaildMessage;
			cin >> number;
		}
		return number;
	}
};