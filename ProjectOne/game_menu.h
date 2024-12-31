#pragma once

#include "user.h"

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
#include <memory>
#include <algorithm>

using assets = const std::map<std::string, std::vector<std::string>>;
using walletInstruments = std::map<std::string, std::vector<float>>;
using walletGoods = std::map<std::string, float>;
using walletHistory = std::multimap<std::string, std::array<float, 2>>;

void updateAssetPrices(walletGoods& marketPrices);
void displayMenu(void);
void displayActualAccount(void);
void changeKnownAccount(std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator& account_Iterator);
void showSaveAccManageMenu(void);
void showInvestAccManageMenu(void);





