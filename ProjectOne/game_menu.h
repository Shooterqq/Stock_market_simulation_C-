#pragma once

#include "UserAccount.h"
#include "UserAccountInvest.h"

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <list>
#include <queue>
#include <cstdint>
#include <array>
#include <fstream>
#include <functional>
#include <random>
#include <chrono>
#include <algorithm>
#include <limits>
#include <cctype>
#include <sstream>
#include <filesystem>

constexpr const char* WALLET_KEY = "Money";
constexpr const char* WALLET_GOLD = "Gold";

using assets = const std::map<std::string, std::vector<std::string>>;
using walletInstruments = std::map<std::string, std::vector<float>>;
using walletGoods = std::map<std::string, float>;
using walletHistory = std::multimap<std::string, std::array<float, 2>>;

//-----------------------------------------------------------------------------------------------------------------

void menu_updateAssetPrices(walletGoods& marketPrices);
void menu_saveToCSV(const walletGoods& marketPrices, const std::string& filename);
void menu_runPythonScript(const std::string& scriptName, const std::string& csvFile);
void menu_displayMenu(void);
void menu_displayActualAccount(void);
void menu_changeKnownAccount(std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator& account_Iterator);
void menu_showSaveAccManageMenu(void);
void menu_showInvestAccManageMenu(void);
void menu_gameMenuRutine(void);
void menu_updateAllDeposits(std::unordered_map<std::string, std::shared_ptr<UserAccount>>& accountMap, int currentTurn);
std::string menu_createAccount(void);
void menu_manageAccount(static int turn);
void menu_readAssetsNames(void);
void showRanking(void);

//----------------------------------------------------------------------------------------------------------------------------

template <typename T>
void isEnterValNum(T& enter_Num)
{
    while (true)
    {
        std::string input;
        std::cin >> input;

        // Sprawdzenie, czy ci�g wej�ciowy zawiera tylko cyfry (opcjonalnie dla liczb zmiennoprzecinkowych i ujemnych)
        std::istringstream iss(input);
        iss >> enter_Num;  // Pr�bujemy przekonwertowa� wej�cie na typ T

        if (iss.fail() || !iss.eof()) // Je�li nie uda�o si� przekonwertowa� lub pozosta�y nieprzeczytane znaki
        {
            std::cout << "It is not a number. Please put proper value.\n";

            // Czyszczenie b��d�w i ignorowanie reszty danych w strumieniu
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break; // Wyj�cie z p�tli, gdy liczba jest poprawna
        }
    }
}




