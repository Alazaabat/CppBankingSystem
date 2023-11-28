#pragma once
#pragma warning(disable :4996)
#include<iostream>
#include<string>
#include"clsString.h"
#include<math.h>
#include<cstdlib>
class clsUtil {
	

public:
	enum enCharType
	{
		Small_Letter, Capital_Letter, Digit, Mix
	};
	static void Srand() {
		srand((unsigned)time(NULL));
	}
	static bool IsPrime(int Number) {
		for (int i = 2; i <= Number / 2; i++)
		{
			if ((Number % i) == 0)
			{

				return true;
			}
		}
		return false;;

	}
	static int RandomNumber(int from, int To) {
		return (rand() % (To - from + 1) + from);
	}
	static char GetRandomCharacter(enCharType Type) {
		if (Type == Mix)
			Type = enCharType(RandomNumber(0, 2));
		switch (Type)
		{
		case Small_Letter:
			return char(RandomNumber(97, 122));
			break;
		case Capital_Letter:
			return (char)RandomNumber(int('A'), int('Z'));
			break;;
		case Digit:
			return (char)RandomNumber(int('0'), int('9'));

			break;
		default:
			break;
		}

	}
	static string GenerateWord(enCharType Type, int size) {
		string word = "";
		for (int i = 0; i < size; i++)
		{
			word += GetRandomCharacter(Type);
		}
		return word;
	}
	static string  GenerateKey(enCharType CharType = Mix)
	{

		string Key = "";


		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);


		return Key;
	}
	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{

		for (int i = 1; i <= NumberOfKeys; i++)

		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}

	}

	static void Swap(int& Number1, int& Number2) {
		int C = Number1;
		Number1 = Number2;
		Number2 = C;
	}
	static void Swap(double& Number1, double& Number2) {
		double C = Number1;
		Number1 = Number2;
		Number2 = C;
	}
	static void Swap(string& str1, string& str2) {
		string C = str1;
		str1 = str2;
		str2 = C;
	}
	static void ShuffleArray(int T[], int size) {

		int H, B;
		for (int i = 0; i < 50; i++)
		{
			H = RandomNumber(0, size - 1);
			B = RandomNumber(0, size - 1);
			Swap(T[H], T[B]);
		}

	}
	static void CopyReversed(int arrSource[], int arrDestination[], int arrLength) {

		for (int i = 0; i < arrLength; i++)
		{
			arrDestination[i] = arrSource[arrLength - i - 1];
		}

	}
	static int ReadPositiveNumber(string Message) {
		cout << Message;
		int Number;
		cin >> Number;
		cout << endl;
		return Number;

	}
	static void FillArrayWithRandomNumbers(int T[], int& Length) {
		Length = ReadPositiveNumber("Please Enter lenght of array");
		for (int i = 0; i < Length; i++)
		{
			T[i] = RandomNumber(1, 100);
		}
	}
	static void ReadArray(int T[], const int& length) {
		cout << " Please enter the  elements array :" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << " T[" << i << "] : ";
			cin >> T[i];

		}


	};
	static void PrintArray(int T[], int length) {

		cout << "\n   The  elements array :" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << "T[" << i << "] = " << T[i] << endl;
		}
		cout << endl;


	}
	static int MaxOfArray(int Arr[], int Length) {
		int Max = Arr[0];
		for (int i = 0; i < Length; i++)
		{
			if (Max > Arr[i])
			{
				Max = Arr[i];
			}
		}
		return Max;
	}
	static void CopyArray(int arrSource[], int arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++) {
			arrDestination[i] = arrSource[i];
		}
	}
	static int copyPrime(int arrSource[], int arrDestination[], int arrLength) {
		int contor = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (IsPrime(arrSource[i]) == true)
			{
				arrDestination[contor] = arrSource[i];
				contor++;
			}
		}
		return contor;
	}
	void FillArrayWithRandomWords(string Arr[], int Length, enCharType Type, int WordLength) {

		for (int i = 0; i < Length; i++)
		{
			Arr[i] = GenerateWord(Type, 4);
		}

	}
	void FillArrayWithRandomKeys(string Arr[], int Length, enCharType Type, int WordLength) {

		for (int i = 0; i < Length; i++)
		{
			Arr[i] = GenerateKey(Type);
		}

	}
	static int FindNumberIndex(int Arr[], int Length, int Check) {
		for (int i = 0; i < Length; i++)
		{
			if (Arr[i] == Check)
			{
				return i;
			}
		}
		return -1;
	}
	static bool isFound(int Arr[], int Length, int Number) {
		return ((FindNumberIndex(Arr, Length, Number) >= 0));
	}
	static bool IsPalindrome(int Arr[], int Length) {
		for (int i = 0; i < Length / 2; i++)
		{
			if (Arr[i] != Arr[Length - 1 - i])
			{
				return false;
			}
		}
		return true;
	}
	static int OddCounterInArr(int Arr[], int Length) {
		int counter = 0;
		for (int i = 0; i < Length; i++)
		{
			if (Arr[i] % 2 != 0)
			{
				counter++;
			}
		}
		return counter;
	}
	static int EvenCounterInArr(int Arr[], int Length) {
		return (Length - OddCounterInArr(Arr, Length));
	}
	static int PositiveCounterInArr(int Arr[], int Length) {
		int counter = 0;
		for (int i = 0; i < Length; i++)
		{
			if (Arr[i] >= 0)
			{
				counter++;
			}
		}
		return counter;
	}
    static int NegativeCounterInArr(int Arr[], int Length) {

		return (Length - PositiveCounterInArr(Arr, Length));
	}
	static string EncryptText(string Text, int Key) {
		for (char &ch : Text)
			ch += Key;
		return  Text;
	}
	static string DecryptText(string Text, int Key) {
		return EncryptText(Text, -1 * Key);
	}
	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}
	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "0";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}



};

