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
    virtual void depositMoney(std::string& assetType, float& deposit_Amount);
    virtual double calculateAccountWorth() const;
    virtual void generateReport() const = 0;

protected:
    walletGoods client_Wallet_Money =
    {
        {"Money", 0.0}
    };
    int deposit_Bonus{ 100 };
};

// --------------------------------------------------------------------------------------------------------------------------------------------- //

class UserAccountSavings : public UserAccount
{
public:
    using UserAccount::UserAccount;
    void getSaveClientName() const;
    void generateReport() const override;
    void showGlobalWallet() const override;
    void buyDeposit(walletGoods wallet);       // kup lokate
    void buyGold(walletGoods wallet);          
    void withdrawMoney(walletGoods wallet);    

private:
    int deposit_Bonus{ 2 };
    int gold_Bonus{ 3 };
};

// --------------------------------------------------------------------------------------------------------------------------------------------- //

class UserAccountInvest : public UserAccount
{
public:
    void buyShares(walletGoods wallet);
    void buyHouses(walletGoods wallet);
    void showGlobalWallet() const;
    void showMyWallet() const;
    void generateReport() const;
    void buyCurrencies(walletGoods wallet);     // kup walluty
    void buyCrypto(walletGoods wallet);

private:
    int shares_Bonus{ 4 };
    int crypto_Bonus{ 2 };
};

// --------------------------------------------------------------------------------------------------------------------------------------------- //

































