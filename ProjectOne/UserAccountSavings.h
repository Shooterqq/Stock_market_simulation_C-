#pragma once

#include "UserAccount.h"
#include "game_menu.h"

constexpr int DEPOSIT_INVEST_RATE_4{ 4 };      // float but int is better - less memory
constexpr int DEPOSIT_INVEST_RATE_5{ 5 };
constexpr int DEPOSIT_INVEST_RATE_6{ 6 };

constexpr int DEPOSIT_MONTHS_6{ 6 };
constexpr int DEPOSIT_MONTHS_9{ 9 };
constexpr int DEPOSIT_MONTHS_12{ 12 };

constexpr const char* DDEPOSIT_AT_4 = "DepositAt4";
constexpr const char* DDEPOSIT_AT_5 = "DepositAt5";
constexpr const char* DDEPOSIT_AT_6 = "DepositAt6";

typedef struct Deposit_options {
    int startTurn;     // Tura, w kt�rej rozpocz�to lokat�
    int duration;      // Czas trwania w turach
    float amount;      // Kwota zdeponowana
    float interestRate; // Stopa procentowa
};

typedef enum State_deposit
{
    SM_DEP_IDLE,
    SM_DEP_DEPOSIT_AT_4,
    SM_DEP_DEPOSIT_AT_5,
    SM_DEP_DEPOSIT_AT_6
};

extern const assets typeOfAssets;
extern walletInstruments valueOfAssets;
extern walletGoods course_assets;

class UserAccountSavings : public UserAccount
{
public:
    using UserAccount::UserAccount;
    void updateDeposits(int currentTurn);
    void getSaveClientName() const;
    void generateReport() const override;
    void showGlobalWallet() const override;
    void buyDeposit(static int& actual_turn_nr);      // kup lokate
    void buyGold(void);
    void withdrawMoney(void);
    void showMyWallet() const;
    void addDeposit(int startTurn, int duration, float amount, float interestRate);

private:
    std::vector<Deposit_options> saveAcc_Deposit_List;
    int deposit_Bonus{ 2 };
    int gold_Bonus{ 3 };

};

