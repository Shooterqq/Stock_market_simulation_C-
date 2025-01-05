#pragma once

#include "UserAccount.h"
#include "game_menu.h"

extern const assets typeOfAssets;
extern walletInstruments valueOfAssets;
extern walletGoods course_assets;


constexpr int DEPOSIT_INVEST_RATE_4{ 4 };      // float but int is better - less memory
constexpr int DEPOSIT_INVEST_RATE_5{ 5 };
constexpr int DEPOSIT_INVEST_RATE_6{ 6 };

constexpr int DEPOSIT_MONTHS_6{ 6 };
constexpr int DEPOSIT_MONTHS_9{ 9 };
constexpr int DEPOSIT_MONTHS_12{ 12 };

constexpr const char* DDEPOSIT_AT_4 = "DepositAt4";
constexpr const char* DDEPOSIT_AT_5 = "DepositAt5";
constexpr const char* DDEPOSIT_AT_6 = "DepositAt6";

class UserAccountSavings : public UserAccount
{
public:
    using UserAccount::UserAccount;

    void updateDeposits(int currentTurn, float& client_Wallet_Money);
    void getSaveClientName() const;
    void generateReport() const override;
    void showGlobalWallet() const override;
    void buyDeposit(walletGoods& wallet, static int& actual_turn_nr);      // kup lokate
    void buyGold(walletGoods wallet);
    void withdrawMoney(walletGoods wallet);
    void showMyWallet() const;
    void addDeposit(int startTurn, int duration, float amount, float interestRate);

private:
    std::vector<Deposit_options> saveAcc_Deposit_List;
    int deposit_Bonus{ 2 };
    int gold_Bonus{ 3 };
};

