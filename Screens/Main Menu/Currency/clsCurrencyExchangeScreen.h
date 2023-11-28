#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsListCurrencies.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculator.h"
class clsCurrencyExchangeScreen:clsScreen
{
private:
    enum enCurrencyMenuChoice
    {   eListCurrencies=1,
        eFindCurrency,
        eUpdateCurrency,
        eCurrencyCalculator,
        eBackToMainMenu,
    };
    static void _backToCurrencyMenu() {
        cout << "\n \t please enter any key to go bach to Currency Menu ... ";
        system("pause>0");

        CurrencyExchangeMenuScreen();

    }
    static enCurrencyMenuChoice _readCurrencyExchangeMenuChoice() {
        cout << "Enter Your Choice from 1---->5 : ";
        return enCurrencyMenuChoice(clsInputValidate::ReadIntNumberBetween(1, 5, "\nPlease Enter Valid Number Between 1--->5 : "));
    }
    static void _listCurrenciesScreen() {
        clsListCurrencies::ShowListCurrenciesScreen();
    }
    static void _findCurrencyScreen() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _updateCurrencyScreen() {
        clsUpdateCurrencyRate::ShowUpdateCurrenctRateScreen();
    }
    static void _currencyCalculatorScreen() {
        clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
    }
    static void _performCurrencyMenuChoice(enCurrencyMenuChoice Choice) {
        switch (Choice)
        {
        case clsCurrencyExchangeScreen::eListCurrencies:
            system("cls");
            _listCurrenciesScreen();
            _backToCurrencyMenu();
            break;
        case clsCurrencyExchangeScreen::eFindCurrency:
            system("cls");
            _findCurrencyScreen();
            _backToCurrencyMenu();
            break;
        case clsCurrencyExchangeScreen::eUpdateCurrency:
            system("cls");
            _updateCurrencyScreen();
            _backToCurrencyMenu();
            break;
        case clsCurrencyExchangeScreen::eCurrencyCalculator:
            system("cls");
            _currencyCalculatorScreen();
            _backToCurrencyMenu();
            break;
        case clsCurrencyExchangeScreen::eBackToMainMenu:

            break;
        default:
            break;
        }
    }
public:

    static void CurrencyExchangeMenuScreen() {
        if (!CheckPermissions(clsUser::eTransactions)) {
            return;
        }
        system("cls");
        string Title = "\t Currency Exchange Screen";
        _drawScreenHeader(Title);
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Back To Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _performCurrencyMenuChoice(_readCurrencyExchangeMenuChoice());
    }
};

