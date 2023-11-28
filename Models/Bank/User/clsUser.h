#pragma once
#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsPerson.h"
#include"clsInputValidate.h"
#include<fstream>
#include"clsString.h"
#include"clsUtil.h"

using namespace std;
class clsUser:public clsPerson
{
private:
	enum enUserMode
	{
		eEmptyUser,eUpdateUser,eAddUser
	};
	string _userName;
	string _password;
	int _permissions;
	enUserMode _mode;
	bool _markForDelete = false;
	static string _convertUserObjectToLine(clsUser User,string Dill) {
		string result = "";
		result += User.FirstName + Dill;
		result += User.LastName + Dill;
		result += User.Email + Dill;
		result += User.Phone + Dill;
		result += User.UserName + Dill;
		result += clsUtil::EncryptText(User.Password,3) + Dill;
		result += to_string(User.Permissions);
		return result;

	}
	static clsUser _convertLinetoUserObject(string Line) {
		vector<string> UserInfo = clsString::Split(Line, "#//#");
		return clsUser(eUpdateUser, UserInfo[0], UserInfo[1], UserInfo[2], UserInfo[3], UserInfo[4], clsUtil::DecryptText(UserInfo[5],3), stoi(UserInfo[6]));
	}
	static clsUser _getEmptyClientObject() {
		return clsUser(eEmptyUser, "", "", "", "", "", "", 0);
	}
	static vector<clsUser> _fromFileToVUsers() {
		string Line;
		fstream file;
		vector< clsUser> Vusers;
		file.open("MyUsers.txt", ios::in);
		if (file.is_open()) {

			while (getline(file, Line))
			{
				Vusers.push_back(_convertLinetoUserObject(Line));
			}
			file.close();
			return Vusers;

		}
		else {
			cout << "Error !! [File doesn't Exist !! ]";
			clsUser empty = _getEmptyClientObject();
			return { {empty} };
		}



	}
	static void _addDataToFile(string Line,string path) {
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
	static bool _fromVUsersToFile( vector<clsUser>& VUsers) {
		string Line;
		fstream file;

		file.open("MyUsers.txt", ios::out);
		if (file.is_open()) {
			for ( clsUser& User : VUsers)
				if(!User.IsMarkForDelete())
				file << _convertUserObjectToLine(User,"#//#")<<endl;

			file.close();
			return true;
			

		}
		else {
			cout << "Error !! [File doesn't Exist !! ]";
			return false;
		}

	}
    void _update() {
		vector< clsUser> VUsers = _fromFileToVUsers();
		for (clsUser& User : VUsers) {
			if (User.UserName == this->_userName) {
				User = *this;
				break;
			}
		}
		_fromVUsersToFile(VUsers);
	}
	void _add() {
		string Line = _convertUserObjectToLine(*this, "#//#");
		_addDataToFile(Line, "MyUsers.txt");
		return;
	}
	clsUser _getEmptyUser() {
		return clsUser(enUserMode::eEmptyUser, "", "", "", "", "","",0);

	}
	bool _perfromDelete() {
		vector< clsUser> VUsers = _fromFileToVUsers();
		for (clsUser& User : VUsers) {
			if (User.UserName == this->_userName) {
				User.MarkForDelete();
				break;
			}
		}
		(*this) = _getEmptyUser();
		if (_fromVUsersToFile(VUsers)) {
			return true;
		}
		return false;
			
	}
	string _convertLoginStructToLine(string dill="#//#") {
		string result = clsDate::GetTodayFullDateInString();
		result += dill;
		result += _userName + dill;
		result += clsUtil::EncryptText(_password,3) + dill;
		result += to_string(_permissions) ;
		return result;
	}
	struct stLoginDetails;
	static stLoginDetails _convertLinetoLoginStruct(string Line) {
		vector<string> Details = clsString::Split(Line, "#//#");
		return { Details[0],Details[1],clsUtil::DecryptText(Details[2],3),stoi(Details[3]) };
	}
	struct stEmailDetails;

	static void _createEmptyFile(string path) {
		fstream file;
		file.open(path, ios::out);
		if (file.is_open()) {
			return;
		}
		else {
			cout << "Error !! [File doesn't Exist and Can't Create File !! ]";
			return;
		}

	}
	string _fromStuctEmailToLine(stEmailDetails Email,string Dill="#//#") {
		string Result = "";
		Result += Email.Date + Dill;
		Result += Email.Dealer + Dill;
		Result += Email.Title + Dill;
		Result += Email.Body;
		return Result;
	}
	void _addInSendBox(stEmailDetails Email) {
		string SendInfo = _fromStuctEmailToLine(Email,"#//#");
		string path = "SendedMailBox\\" + _userName + "SendedBox.txt";
		_addDataToFile(SendInfo, path);
	}
	void _sendMail(string Title, string Body, clsUser Receiver) {
		stEmailDetails EmailInfo(clsDate::GetTodayFullDateInString()
		, Receiver.UserName, Title, Body);
		_addInSendBox(EmailInfo);
	 }
	void _addInReceiveBox(stEmailDetails Email) {
		string SendInfo = _fromStuctEmailToLine(Email,"#//#");
		string path = "ReceivedMailBox\\" + _userName + "ReceivedBox.txt";
		_addDataToFile(SendInfo, path);
	}
	void _receiveMail(string Title, string Body, clsUser Sender) {
		stEmailDetails EmailInfo(clsDate::GetTodayFullDateInString(),
			Sender.UserName, Title, Body);
		_addInReceiveBox(EmailInfo);
	}
	void _createSendedMailBox() {
	string path="SendedMailBox\\"+_userName + "SendedBox.txt";
	_createEmptyFile(path);

	}
	void _createReceivedMailBox() {
		string path = "ReceivedMailBox\\" + _userName + "ReceivedBox.txt";
		_createEmptyFile(path);
	}
	static stEmailDetails _convertLinToEmail(string line) {
		vector<string> EmailInfo = clsString::Split(line, "#//#");
		stEmailDetails Email;
		Email.Date = EmailInfo[0];
		Email.Dealer = EmailInfo[1];
		Email.Title = EmailInfo[2];
		Email.Body = EmailInfo[3];

		return Email;
	}
	static vector<stEmailDetails> _getEmailsFromFile(string path) {
		string line;
		fstream file;
		vector<stEmailDetails> VEmails;
		file.open(path, ios::in);
		if (file.is_open()) {
			while (getline(file,line))
			{
				VEmails.push_back(_convertLinToEmail(line));
			}
			file.close();
			return VEmails;
		}
		else {
			_createEmptyFile(path);
			return _getEmailsFromFile(path);

		}


	}
public:
	enum enClearBox
	{
		eReceived, eSended
	};
	struct stLoginDetails
	{
		string Date;
		string Username;
		string Password;
		int Permissions;
	};
	struct stEmailDetails
	{
		string Date;
		string Dealer;
		string Title;
		string  Body;
		stEmailDetails(){}
		stEmailDetails(string Date, string Dealer, string Title, string Body) {
			this->Date = Date;
			this->Dealer = Dealer;
			this->Title = Title;
			this->Body = Body;
		}
	};
	enum enPermissions
	{
		eShowClients = 1, eAddClient = 2, eDeleteClient = 4, eUpdateClient = 8, eFindClient = 16, eTransactions = 32, eManageUsers = 64,eLoginRegister=128,eCommunication=256
	};
	clsUser(enUserMode Mode,string FirstName,string LastName,string Phone,string Email,string Username
		,string Password,int Permissions): clsPerson(FirstName,LastName,Phone,Email),
		_userName(Username),_password(Password),_permissions(Permissions), _mode(Mode) {}
    string  GetUserName() { return _userName; }
	void  SetUserName(string UserName) {  _userName=UserName; }
	_declspec(property(get = GetUserName, put = SetUserName))string UserName;

	string GetPassword() { return _password; }
	void SetPassword(string Password) { _password = Password; }
	_declspec(property(get = GetPassword, put = SetPassword))string Password;
	int  GetPermissions() { return _permissions; }
	void SetPermissions(int Permissions) { _permissions = Permissions; }
	_declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;
	static clsUser Find(string Username) {
		vector< clsUser> VUsers = _fromFileToVUsers();
		for ( clsUser& Dummy : VUsers) {
			if (Dummy.UserName == Username)
				return Dummy;
		}
		return _getEmptyClientObject();
	}
	static clsUser Find(string Username, string Password) {
		clsUser User = Find(Username);
		return (User.Password == Password) ? User : _getEmptyClientObject();
	}
	bool IsEmpty() {
		return _mode == eEmptyUser;
	}
	static bool IsExist(string username) {
		clsUser user = Find(username);
		return !user.IsEmpty();
	}
	static bool IsExist(string username,string Password) {
		clsUser user = Find(username,Password);
		return !user.IsEmpty();
	}

	enum enSaveResult {
		eSaveSucceeded,eSaveFailed, eSaveFaildAccountExist
	};
	enSaveResult Save() {
		switch (_mode)
		{
		case clsUser::eEmptyUser:
			return eSaveFailed;
			break;
		case clsUser::eUpdateUser:
			if (_mode == eUpdateUser) {
				_update();
			}
			else {
				return eSaveFailed;
			}
			break;
		case clsUser::eAddUser:
			if (clsUser::IsExist(_userName)) {
				return eSaveFaildAccountExist;
			}
			else {
				_add();
				_createReceivedMailBox();
				_createSendedMailBox();
				_mode = eUpdateUser;
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
	static vector<clsUser> GetUsersList() {
		return _fromFileToVUsers();
	}
	static clsUser GetAddNewUserObject(string Username) {
		return clsUser(eAddUser, "", "", "", "", Username, "", 0);
	}
    void SaveInRegisterLogin() {
		if (this->IsEmpty())
			return;
		string LoginData = _convertLoginStructToLine();
		_addDataToFile(LoginData,"LoginRegister.txt");
	}
	static vector< stLoginDetails>GetLoginRegisterList() {
		string Line;
		fstream file;
		vector< stLoginDetails> Vusers;
		file.open("LoginRegister.txt", ios::in);
		if (file.is_open()) {

			while (getline(file, Line))
			{
				Vusers.push_back(_convertLinetoLoginStruct(Line));
			}
			file.close();
			return Vusers;

		}
		else {
			cout << "Error !! [File doesn't Exist !! ]";
			return{ {} };
		}



	}
    void ReceiveMail(string Title,string Body,clsUser Sender){
		_receiveMail(Title,Body,Sender);
	}
	void SendMail(string Title, string Body, clsUser& Receiver) {
	_sendMail(Title, Body, Receiver);
	clsUser Sender = *this;
	Receiver.ReceiveMail(Title, Body, Sender);
	}
	static vector<stEmailDetails> GetSendedEmails(string Username) {
		string path = "SendedMailBox\\" + Username + "SendedBox.txt";
		return _getEmailsFromFile(path);
	}
	static vector<stEmailDetails> GetReceivedEmails(string Username) {
		string path = "ReceivedMailBox\\" + Username + "ReceivedBox.txt";
		return _getEmailsFromFile(path);
	}
	void Clear(enClearBox  ClearChoice) {
		switch (ClearChoice)
		{
		case clsUser::eReceived:
			_createReceivedMailBox();
			break;
		case clsUser::eSended:
			_createSendedMailBox();
			break;
		default:
			break;
		}
	}
};

