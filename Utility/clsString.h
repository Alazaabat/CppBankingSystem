#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class clsString
{
private:
    string _stringValue;


    static char invert(char letter) {
        return (tolower(letter) == letter) ? toupper(letter) : tolower(letter);
    }
    static string invert(string str) {
        for (int i = 0; i < str.length(); i++) {
            str[i] = invert(str[i]);
        }

        return str;
    }
    static bool isvowel(char letter) {
        char vowels[] = "AIOEU";
        for (const char& vowel : vowels) {
            if (tolower(vowel) == tolower(letter))
                return true;
        }
        return false;
    }


public:
    clsString(string Str) : _stringValue(Str){}
    void SetString(const string& NewStr) { _stringValue = NewStr; }
    string GetString() { return _stringValue; }
    __declspec(property(get = GetString, put = SetString))string String;
    static string Invert(string str) { return invert(str); }
    string Invert() { return invert(_stringValue); }
    static int NumberOfCapitalLetters(const string& str) {
        int counter = 0;
        for (const char& i : str) {
            isupper(i) ? counter++ : counter;
        }
        return counter;
    }
    int NumberOfCapitalLetters() { return NumberOfCapitalLetters(_stringValue); }
    static int NumberOfSmallLetters(const string& str) {
        int counter = 0;
        for (const char& i : str) {
            islower(i) ? counter++ : counter;
        }
        return counter;
    }
    int NumberOfSmallLetters() { return NumberOfSmallLetters(_stringValue); }
    static int NumberOfLetterX(string str, char letter, bool sens = true) {
        int counter = 0;
        for (const char& i : str) {
            if (sens) {
                letter == i ? counter++ : counter;
            }
            else {
                tolower(letter) == tolower(i) ? counter++ : counter;
            }

        }
        return counter;

    }
    int NumberOfLetterX(char letter, bool sens=true) { return NumberOfLetterX(_stringValue, letter, sens); }
    static int NumberOfLetters(string str) {
        int counter=0;
        for (const char& i : str)
            isalpha(i) ? counter++ : counter;

        return counter;
    }
    int NumberOfLetters() { return NumberOfLetters(_stringValue); }
    static int NumberOfVowels(string str) {
        int counter = 0;
        for (const char& i : str)
            isvowel(i) ? counter++ : counter;

        return counter;
    }
    int NumberOfVowels() { return NumberOfVowels(_stringValue); }
    static int NumberOfConsonants(const string & Str){
        return NumberOfLetters(Str) - NumberOfVowels(Str);
    }
    int NumberOfConsonants() { return NumberOfConsonants(_stringValue); }

    static int NumberOfWords(string str) {
        string dil = " ";
        int pos;
        string sword;
        int counter = 0;
        while (( pos = str.find(dil)) != std::string::npos)
        {
            if ((sword = str.substr(0, pos)) != "") {
                counter++;

            }
            str.erase(0, pos + dil.length());


        }
        if (str != "")
            counter++;

        return counter;
    }
    int NumberOfWords() { return NumberOfWords(_stringValue); }
    static vector<string> Split(string S1, string dil)
    {
        int pos;
        vector<string> tmp;
        string sword;
        while ((pos = S1.find(dil)) != std::string::npos)
        {
            if ((sword = S1.substr(0, pos)) != "") {
                tmp.push_back(sword);

            }
            S1.erase(0, pos + dil.length());


        }
        if (S1 != "")
            tmp.push_back(S1);

        return tmp;

    }
    vector<string> Split(string dil) { return Split(_stringValue, dil); }
    static string TrimLeft(string Str) {
      for (int i = 0; i < Str.length(); i++)
      {
          if (Str[i] != ' ')
              return Str.substr(i, Str.length() - i);
      }
      return "";
  }
    void TrimLeft() { _stringValue = TrimLeft(_stringValue); }
    static string TrimRight(string S1){
        for (int i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
                return S1.substr(0, i + 1);
        }
        return "";
    }
    void TrimRight() { _stringValue = TrimRight(_stringValue); }
    static string Trim(string Str) {
        Str = TrimLeft(Str);
        Str = TrimRight(Str);
        return Str;
    }
    void Trim() { _stringValue = Trim(_stringValue); }
    static string Join(vector<string> Vstrings, string dil) {
        string result = "";
        auto StringIter = Vstrings.begin();
        for (;StringIter != Vstrings.end()-1;StringIter++)
        {
            result += *(StringIter);
            result += dil;
        }
        result += *(StringIter);
        return result;
    }
    static string Reverse(string Str) {
        vector<string> myvec;
        string result;
        myvec = Split(Str, " ");
        auto iter = myvec.end() - 1;
        for (; iter != myvec.begin(); iter--)
        {
            result += *(iter);
            result += " ";
        }
        result += *(iter);
        return result;
    }
    void Reverse() { _stringValue = Reverse(_stringValue); }
    static string StrToLow(string Str) {
        for (int i = 0; i < Str.length(); i++)
        {
            Str[i] = tolower(Str[i]);
        }
        return Str;
    }
    void StrToLow() { _stringValue = StrToLow(_stringValue); }
    static string StrToUpper(string Str) {
        for (int i = 0; i < Str.length(); i++)
        {
            Str[i] = toupper(Str[i]);
        }
        return Str;
    }
    void StrToUpper() { _stringValue = StrToUpper(_stringValue); }
    static string Replace(string Str, string old_str, string new_str) {
        int pos;
        while ((pos = Str.find(old_str)) != Str.npos)
        {
            Str.replace(pos, old_str.length(), new_str);
        }
        return Str;
    }
    void Replace(string old_str, string new_str) { _stringValue = Replace(_stringValue, old_str, new_str); }
    static string RemovePunct(string S1) {
        string Sword = "";

        for (int i = 0; i < S1.length(); i++)
        {
            if (ispunct(S1[i])) {
                Sword += S1.substr(0, i);
                S1.erase(0, i +1);
                i = -1;
            }
        }
        if (S1 != "")
            Sword += S1;
        return Sword;
    }
    void RemovePunct() { _stringValue = RemovePunct(_stringValue); }

    static int Length(string Str) { return Str.length(); }
    int Length() { return _stringValue.length();}
    static string UpperFirstOfLetterEachWord(string Str) {
        bool isFirstWord = true;

            for (int i = 0; i < Str.length(); i++)
            {
                if (Str[i] != ' ' && isFirstWord&&Str[i] != ',')
                    Str[i] = toupper(Str[i]);

                isFirstWord=(Str[i] == ' ' || Str[i] == ',' ? true : false);
            }
            return Str;
    }
    void UpperFirstOfLetterEachWord() { _stringValue = UpperFirstOfLetterEachWord(_stringValue); }
    static string LowerFirstOfLetterEachWord(string Str) {
        bool isFirstWord = true;

        for (int i = 0; i < Str.length(); i++)
        {
            if (Str[i] != ' ' && isFirstWord && Str[i] != ',')
                Str[i] = tolower(Str[i]);

            isFirstWord = (Str[i] == ' ' || Str[i] == ',' ? true : false);
        }
        return Str;
    }
    void LowerFirstOfLetterEachWord() { _stringValue = LowerFirstOfLetterEachWord(_stringValue); }

};



