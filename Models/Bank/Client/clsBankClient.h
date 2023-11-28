#pragma once
#include <iostream>
#include <string>
#include<vector>
#include"clsPerson.h"
#include"clsString.h"
#include<fstream>
#include<iomanip>
#include"clsInputValidate.h"
#include"Global.h"
class clsBankClient :public clsPerson
{
private:
	enum enMode
	{
		eEmptyMode, eUpdateMode,eAddMode
	};
   string _accountNumber;
	string _pinCode;
	float  _accountBalance;
	enMode _mode;
	bool _markForDelete = false;
	static clsBankClient _convertLinetoClientObject(string Line) {
		vector<string> ClientInfo = clsString::Split(Line,"#//#");
		return clsBankClient(eUpdateMode, ClientInfo[0], ClientInfo[1], ClientInfo[2], ClientInfo[3], ClientInfo[4], ClientInfo[5],stod( (ClientInfo[6])));
	}
	static  string _convertClientObjectToLine(clsBankClient Client,string Dil) {
		return
			Client.FirstName + Dil+
			Client.LastName + Dil+
			Client.Email + Dil+
			Client.Phone + Dil+
			Client.GetAccountNumber() + Dil +
			Client.PinCode + Dil+
			to_string(Client.AccountBalance);
	}
    static clsBankClient _getEmptyClientObject() {
		return clsBankClient(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}
	static vector< clsBankClient> _fromFileToVectorOfClient() {
		string Line;
		fstream file;
		vector< clsBankClient> Clients;
		file.open("MyClients.txt", ios::in);
		if (file.is_open()) {

			while (getline(file, Line))
			{
				Clients.push_back(_convertLinetoClientObject(Line));
			}
			file.close();
			return Clients;

		}
		else {
			cout << "Error !! [File doesn't Exist !! ]";
			clsBankClient empty = _getEmptyClientObject();
			return { {empty} };
		}

	}
	static  bool _fromVClientsToFile(vector<clsBankClient>& Vclients) {
		string Line;
		fstream file;
		file.open("MyClients.txt", ios::out);
		if (file.is_open()) {
			for (clsBankClient& Client : Vclients) {
				if (!Client.IsMarkForDelete())
					file << _convertClientObjectToLine(Client, "#//#") << endl;
				
			}
			file.close();
			return true;
		}
		else {
			cout << "Error !! [File doesn't Exist !! ]";
			return false;
		}

	}
	static void _addDataToFile(string Line,string path) {;
		fstream file;
		file.open(path, ios::app|ios::out);
		if (file.is_open()) {
			file << Line<<endl;

			file.close();
		}
		else {
			cout << "Error !! [File doesn't Exist and Can't Create File !! ]";
		}
	}
	void _update() {
		vector< clsBankClient> Clients = _fromFileToVectorOfClient();
		for (clsBankClient &DummyClient : Clients) {
			if (DummyClient.GetAccountNumber() ==this->_accountNumber ) {
			DummyClient = *this;
				break;
			}
		}
		_fromVClientsToFile(Clients);
	}
	void _add() {
		string Line = _convertClientObjectToLine(*this, "#//#");
		_addDataToFile(Line,"MyClients.txt");
		return;
	}
	bool _perfromDelete() {
		vector< clsBankClient> Clients = _fromFileToVectorOfClient();
		for (clsBankClient& DummyClient : Clients) {
			if (DummyClient.GetAccountNumber() == this->_accountNumber) {
				DummyClient.MarkForDelete();
				break;
			}
		}
		*this = _getEmptyClientObject();
		if (_fromVClientsToFile(Clients)) 			
			return true;
		return false;
	}
	struct stTransferLog;
	static stTransferLog _convertLinetostTransferLog(string Line) {
		vector<string> Info = clsString::Split(Line, "#//#");
		stTransferLog TransferLog;
		TransferLog.Date = Info[0];
		TransferLog.Transferor = Info[1];
		TransferLog.Recipient = Info[2];
		TransferLog.TransferAmount = stof(Info[3]);
		TransferLog.TransferorBalance = stof(Info[4]);
		TransferLog.RecipientBalance = stof(Info[5]);
		TransferLog.Login = Info[6];
		return TransferLog;
	}
	string _getTransferLine(double Amount, clsBankClient Destination, string Username,string Dill="#//#") {
		string result = "";
		result += clsDate::GetTodayFullDateInString() + Dill;
		result += _accountNumber + Dill;
		result += Destination.GetAccountNumber() + Dill;
		result += to_string(Amount) + Dill;
		result += to_string(_accountBalance) + Dill;
		result += to_string(Destination.AccountBalance) + Dill;
		result += Username;
		return result;

	}
	void _saveTransferInRegister(double Amount, clsBankClient Destination, string Username) {
		string stTransfer = _getTransferLine(Amount, Destination, Username);
		_addDataToFile(stTransfer, "TransferRegister.txt");
	}
	static vector<stTransferLog> _fromFileToVectorOfstTransferLog() {
		string Line;
		fstream file;
		vector< stTransferLog> Logs;
		file.open("TransferRegister.txt", ios::in);
		if (file.is_open()) {

			while (getline(file, Line))
			{
				Logs.push_back(_convertLinetostTransferLog(Line));
			}
			file.close();
			return Logs;

		}
		else {
			cout << "Error !! [File doesn't Exist !! ]";
			return { {} };
		}



	}
public:
	struct stTransferLog {
		string Date;
		string Transferor;
		string Recipient;
		double TransferAmount;
		double TransferorBalance;
		double RecipientBalance;
		string Login;

	};
	void Deposit(float Amount) {
		_accountBalance += Amount;
		Save();
	}
	bool Withdraw(float Amount) {
		if (Amount > _accountBalance)
			return false;
		_accountBalance -= Amount;
		Save();
		return true;
	}
	bool Transfer(float Amount, clsBankClient& Destination) {
		Withdraw(Amount);
		Destination.Deposit(Amount);
		_saveTransferInRegister(Amount, Destination,LoginUser.UserName);
		return true;
	}
	clsBankClient(enMode Mode,string FirstName, string LastName, string Email,
		string Phone, string AccountNumber, string PinCode, float Balance) : clsPerson(FirstName,LastName,Email,Phone),
		_accountNumber(AccountNumber),_pinCode(PinCode), _accountBalance(Balance),_mode(Mode){}
	string GetAccountNumber() const  { return _accountNumber; }
	string GetPinCode() { return _pinCode; }
	void SetPinCode(string Pincode) { _pinCode = Pincode; }
	__declspec(property(get= GetPinCode, put = SetPinCode))string PinCode;
	float GetAccountBalance() const { return _accountBalance; }
		void SetAccountBalance(float balance) { _accountBalance = balance; }
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;
	enMode GetClientMode() { return _mode; }
	static clsBankClient Find(string AccountNumber) {
		string Line;
		fstream file;
		file.open("MyClients.txt", ios::in);
		if (file.is_open()) {

			while (getline(file, Line))
			{
				clsBankClient Client = _convertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
					return Client;
			}
			file.close();
			return _getEmptyClientObject();

		}
		else {
			cout << "Error !! [File doesn't Exist !! ]";
			return _getEmptyClientObject();
		}

	}
	static clsBankClient Find(string AccountNumber,string PinCode) {

		clsBankClient Client = Find(AccountNumber);
		if (Client.PinCode == PinCode) return Client;
		
		return _getEmptyClientObject();
	}
	bool IsEmpty() {
		return _mode == eEmptyMode;
	}
    static  bool IsClientExist(string AccountNumber) {
		clsBankClient Dummy = clsBankClient::Find(AccountNumber);
		return !Dummy.IsEmpty();
	}
	enum enSaveResults {
		eSaveSucceeded, eSaveFailed,eSaveFaildAccountExist
	};
    enSaveResults Save() {
		switch (_mode)
		{
		case clsBankClient::eEmptyMode:
			return eSaveFailed;

			break;
		case clsBankClient::eUpdateMode:
			_update();
			return eSaveSucceeded;
			break;
		case clsBankClient::eAddMode:
			if (clsBankClient::IsClientExist(_accountNumber))
				return eSaveFaildAccountExist;
			else {
				_add();
				return eSaveSucceeded;
			}
			break;
		default:
			break;
		}

		
	}
	void MarkForDelete() {
		_markForDelete = true;
	}
	bool IsMarkForDelete() { return _markForDelete; }
	bool Delete() {
		return _perfromDelete();
	}
	static vector<clsBankClient> GetClientsList() {
		return _fromFileToVectorOfClient();
	}
	static double GetTotalBalances() {
		vector<clsBankClient> vClients = GetClientsList();
		double Result=0;
		for (const clsBankClient& Client : vClients)
			Result += Client.AccountBalance;
		return Result;
	}
	static clsBankClient GetAddNewClientObject(string accName) {
		return clsBankClient(eAddMode, "", "", "", "", accName, "", 0);
	}

	static vector<stTransferLog> GetTransferLogList() {
		return _fromFileToVectorOfstTransferLog();
	}

};

