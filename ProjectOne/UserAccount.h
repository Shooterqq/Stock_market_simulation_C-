#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <list>
#include <queue>
#include <cstdint>
#include <unordered_map>
#include <array>
#include <fstream>
#include <memory>
//#include <matplotlibcpp.h>        // later for charts



float chooseMeters(void);

// --------------------------------------------------------------------------------------------------------------------------------------------- //

using assets = const std::map<std::string, std::vector<std::string>>;
using walletInstruments = std::map<std::string, std::vector<float>>;
using walletGoods = std::map<std::string, float>;
using walletHistory = std::multimap<std::string, std::array<float, 2>>;



class UserAccount
{
private:
    std::string client_Name;
    std::string client_Surname;
    static int client_Id;
    int client_Account_Num;
    std::map<walletInstruments, walletGoods> client_Wallet;     // course, quantity owned
    bool account_Activation_Status;
    walletHistory client_History;

public:
    UserAccount();
    UserAccount(const std::string &name, const std::string &surname, float &usd_Start_Val);
    ~UserAccount();
    std::string getClientName() const;
    std::string getClientSurname() const;
    void getNumberOfClients() const;
    virtual void showGlobalWallet() const = 0;        // inne wyswietlane aktywa dla kazdego 
    virtual void showHistory() const;
    void depositMoney(std::string assetType, float deposit_Amount);
    virtual double calculateAccountWorth() const;
    virtual void generateReport() const = 0;
    virtual void showMyWallet() const;
    void sellAsset(void);

protected:
    int deposit_Bonus{ 100 };

    walletGoods client_Wallet_Money =
    {
        {"Money", 1000000.0}
    };

    walletGoods client_Goods =
    {
        {"Cur_Dollar", 0.0},
        {"Cur_Euro", 0.0},
        {"Cur_British Pound", 0.0},
        {"St_Microsoft", 0.0},
        {"St_Apple", 0.0},
        {"St_Samsung", 0.0},
        {"DepositAt4", 0.0},
        {"DepositAt5", 0.0},
        {"DepositAt6", 0.0},
        {"Cry_Bitcoin", 0.0},
        {"Cry_Etherium", 0.0},
        {"Cry_Dogecoin", 0.0},
        {"Bonds3Years", 0.0},
        {"Bonds5Years", 0.0},
        {"Bonds10Years", 0.0},
        {"Gold", 0.0 },
        {"House_Warsaw", 0.0},
        {"House_Berlin", 0.0},
        {"House_Mexico_City", 0.0}
    };
};


