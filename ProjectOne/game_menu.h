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

using assets = const std::map<std::string, std::vector<std::string>>;
using walletInstruments = std::map<std::string, std::vector<float>>;
using walletGoods = std::map<std::string, float>;
using walletHistory = std::multimap<std::string, std::array<float, 2>>;

//-----------------------------------------------------------------------------------------------------------------

void menu_updateAssetPrices(walletGoods& marketPrices);
void menu_displayMenu(void);
void menu_displayActualAccount(void);
void menu_changeKnownAccount(std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator& account_Iterator);
void menu_showSaveAccManageMenu(void);
void menu_showInvestAccManageMenu(void);
void menu_gameMenuRutine(void);
void menu_updateAllDeposits(std::unordered_map<std::string, std::shared_ptr<UserAccount>>& accountMap, int currentTurn);
std::string menu_createAccount(void);
void menu_manageAccount(static int turn);

//----------------------------------------------------------------------------------------------------------------------------

template <typename T>
void isEnterValNum(T& enter_Num)
{
    while (true)
    {
        std::string input;
        std::cin >> input;

        // Sprawdzenie, czy ci¹g wejœciowy zawiera tylko cyfry (opcjonalnie dla liczb zmiennoprzecinkowych i ujemnych)
        std::istringstream iss(input);
        iss >> enter_Num;  // Próbujemy przekonwertowaæ wejœcie na typ T

        if (iss.fail() || !iss.eof()) // Jeœli nie uda³o siê przekonwertowaæ lub pozosta³y nieprzeczytane znaki
        {
            std::cout << "It is not a number. Please put proper value.\n";

            // Czyszczenie b³êdów i ignorowanie reszty danych w strumieniu
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break; // Wyjœcie z pêtli, gdy liczba jest poprawna
        }
    }
}




