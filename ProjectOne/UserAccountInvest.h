#pragma once

#include "UserAccount.h"
#include "game_menu.h"

extern const assets typeOfAssets;
extern walletInstruments valueOfAssets;
extern walletGoods course_assets;

class UserAccountInvest : public UserAccount
{
public:
    using UserAccount::UserAccount;
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
