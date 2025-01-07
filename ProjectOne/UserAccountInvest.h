#pragma once

#include "UserAccount.h"
#include "game_menu.h"

constexpr const char* ST_MICROSOFT = "St_Microsoft";
constexpr const char* ST_APPLE = "St_Apple";
constexpr const char* ST_SAMSUNG = "St_Samsung";

constexpr const char* DEV_HS_WARSAW = "House_Warsaw";
constexpr const char* DEV_HS_BERLIN = "House_Berlin";
constexpr const char* DEV_HS_MEXICO_CITY = "House_Mexico_City";

constexpr const char* CUR_DOLLAR = "Cur_Dollar";
constexpr const char* CUR_EURO = "Cur_Euro";
constexpr const char* CUR_BRITISH_POUND = "Cur_British_Pound";

constexpr const char* CRY_BITCOIN = "Cry_Bitcoin";
constexpr const char* CRY_ETHERIUM = "Cry_Etherium";
constexpr const char* CRY_DOGECOIN = "Cry_Dogecoin";

typedef enum State_shares
{
    SM_ST_IDLE,
    SM_ST_MICROSOFT,
    SM_ST_APPLE,
    SM_ST_SAMSUNG
};

typedef enum State_houses
{
    SM_DEV_IDLE,
    SM_DEV_HOUSE_WARSAW,
    SM_DEV_HOUSE_BERLIN,
    SM_DEV_HOUSE_MEXICO_CITY
};

typedef enum State_currenties
{
    SM_CUR_IDLE,
    SM_CUR_DOLLAR,
    SM_CUR_EURO,
    SM_CUR_BRITISH_POUND
};

typedef enum State_crypto
{
    SM_CR_IDLE,
    SM_CR_BITCOIN,
    SM_CR_ETHERIUM,
    SM_CR_DOGECOIN
};

extern const assets typeOfAssets;
extern walletInstruments valueOfAssets;
extern walletGoods course_assets;

class UserAccountInvest : public UserAccount
{
public:
    using UserAccount::UserAccount;
    void buyShares();
    void buyHouses();
    void showGlobalWallet() const;
    void showMyWallet() const;
    void generateReport() const;
    void buyCurrencies();
    void buyCrypto();

private:
    int shares_Bonus{ 4 };
    int crypto_Bonus{ 2 };

};
