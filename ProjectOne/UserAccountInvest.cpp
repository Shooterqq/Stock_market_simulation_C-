#include "UserAccountInvest.h"

extern State_deposit deposit;          // TODO usunac to i naprawic bledy, zrobic typedefy

void UserAccountInvest::buyShares(walletGoods wallet)
{
    std::string key = "Money";

    if (client_Wallet_Money[key] > wallet[key])
    {
        std::cout << "You have too low money in your wallet" << std::endl;
        return;
    }
    std::cout << "Please choose type of stocks:" << std::endl;
    std::cout << "1. Microsoft" << std::endl;
    std::cout << "2. Apple" << std::endl;
    std::cout << "3. Samsung" << std::endl;

    int userInput;
    std::cin >> userInput;
    deposit = static_cast<State_deposit>(userInput);

    switch (deposit)
    {
    case DEPOSIT_AT_4:
        std::cout << "Chosed St_Microsoft" << std::endl;
        client_Goods["St_Microsoft"] = { wallet[key] * (1 / course_assets["St_Microsoft"]) };
        break;

    case DEPOSIT_AT_5:
        std::cout << "Chosed St_Apple" << std::endl;
        client_Goods["St_Apple"] = { wallet[key] * (1 / course_assets["St_Apple"]) };
        break;

    case DEPOSIT_AT_6:
        std::cout << "Chosed St_Samsung" << std::endl;
        client_Goods["St_Samsung"] = { wallet[key] * (1 / course_assets["St_Samsung"]) };
        break;

    default:
        std::cout << "Invalid choice. Please choose a proper value." << std::endl;
        deposit = IDLE; // Reset to IDLE if input is invalid
        break;
    }
}

void UserAccountInvest::buyHouses(walletGoods wallet)
{
    std::string key = "Money";

    if (client_Wallet_Money[key] > wallet[key])
    {
        std::cout << "You have too low money in your wallet" << std::endl;
        return;
    }

    int userInputCity;
    float userMeters;

    switch (deposit)
    {
    case IDLE:
        std::cout << "Please choose city, where you want to buy house:" << std::endl;
        std::cout << "1. Warsaw" << std::endl;
        std::cout << "2. Berlin" << std::endl;
        std::cout << "3. Mexico City" << std::endl;

        std::cin >> userInputCity;
        deposit = static_cast<State_deposit>(userInputCity);
        break;

    case DEPOSIT_AT_4:
        std::cout << "Chosed Warsaw - grey, dark and cold piece of hell" << std::endl;
        //userMeters = chooseMeters();
        client_Goods["House_Warsaw"] = { wallet[key] / course_assets["House_Warsaw"] };
        break;

    case DEPOSIT_AT_5:
        std::cout << "Chosed House_Berlin" << std::endl;
        //userMeters = chooseMeters();
        client_Goods["House_Berlin"] = { wallet[key] / course_assets["House_Berlin"] };
        break;

    case DEPOSIT_AT_6:
        std::cout << "Chosed House_Mexico_City" << std::endl;
        //userMeters = chooseMeters();
        client_Goods["House_Mexico_City"] = { wallet[key] / course_assets["House_Mexico_City"] };
        break;

    default:
        std::cout << "Invalid choice. Please choose a proper value." << std::endl;
        deposit = IDLE; // Reset to IDLE if input is invalid
        break;
    }
}

float chooseMeters(void)
{
    float userInputMeters;

    std::cout << "Chow much meters?:" << std::endl;
    std::cin >> userInputMeters;

    return userInputMeters;
}


void UserAccountInvest::showGlobalWallet() const
{
    for (const auto& assetType : typeOfAssets)
    {
        std::cout << assetType.first << ":" << std::endl;

        // For each item in the asset type
        for (size_t i = 0; i < assetType.second.size(); ++i)
        {
            // Listing the name of the asset and its value
            std::cout << "  " << assetType.second[i] << " - " \
                << valueOfAssets.at(assetType.first)[i] << std::endl;
        }
        std::cout << std::endl;
    }
}

void UserAccountInvest::generateReport() const
{
    std::cout << "123";
}

//const auto& [category, values]
void UserAccountInvest::showMyWallet() const
{
    std::cout << "\nAccount: " << this->getClientName() << " " << this->getClientSurname() << "\n";
    for (const auto& [category, values] : client_Goods)
    {
        std::cout << category << " - " << values << "\n";
    }
    std::cout << "\n";
}

//{ "Cur_Dollar", 3.40 },
//{ "Cur_Euro", 4.25 },
//{ "Cur_British Pound", 5.20 },
void UserAccountInvest::buyCurrencies(walletGoods wallet)
{
    std::string key = "Money";

    if (client_Wallet_Money[key] > wallet[key])
    {
        std::cout << "You have too low money in your wallet" << std::endl;
        return;
    }

    int userInputCurrienties;
    float userMeters;

    switch (deposit)
    {
    case IDLE:
        std::cout << "Please choose currienties to buy:" << std::endl;
        std::cout << "1. Dollar" << std::endl;
        std::cout << "2. Euro" << std::endl;
        std::cout << "3. British Pound" << std::endl;

        std::cin >> userInputCurrienties;
        deposit = static_cast<State_deposit>(userInputCurrienties);
        break;

    case DEPOSIT_AT_4:
        std::cout << "Chosed Dollar" << std::endl;
        client_Goods["Cur_Dollar"] = { wallet[key] / course_assets["Cur_Dollar"] };

        break;

    case DEPOSIT_AT_5:
        std::cout << "Chosed Euro" << std::endl;
        client_Goods["Cur_Euro"] = { wallet[key] / course_assets["Cur_Euro"] };
        break;

    case DEPOSIT_AT_6:
        std::cout << "Chosed British Pound" << std::endl;
        client_Goods["Cur_British_Pound"] = { wallet[key] / course_assets["Cur_British_Pound"] };
        break;

    default:
        std::cout << "Invalid choice. Please choose a proper value." << std::endl;
        deposit = IDLE; // Reset to IDLE if input is invalid
        break;
    }
}

void UserAccountInvest::buyCrypto(walletGoods wallet)
{
    std::string key = "Money";

    if (client_Wallet_Money[key] > wallet[key])
    {
        std::cout << "You have too low money in your wallet" << std::endl;
        return;
    }

    int userInputCurypto;

    switch (deposit)
    {
    case IDLE:
        std::cout << "Please choose crypto to buy:" << std::endl;
        std::cout << "1. Bitcoin" << std::endl;
        std::cout << "2. Etherium" << std::endl;
        std::cout << "3. Dogecoin" << std::endl;

        std::cin >> userInputCurypto;
        deposit = static_cast<State_deposit>(userInputCurypto);
        break;

    case DEPOSIT_AT_4:
        std::cout << "Chosed Bitcoin" << std::endl;
        client_Goods["Cry_Bitcoin"] = { wallet[key] / course_assets["Cry_Bitcoin"] };
        break;

    case DEPOSIT_AT_5:
        std::cout << "Chosed Etherium" << std::endl;
        client_Goods["Cry_Etherium"] = { wallet[key] / course_assets["Cry_Etherium"] };
        break;

    case DEPOSIT_AT_6:
        std::cout << "Chosed Dogecoin" << std::endl;
        client_Goods["Cry_Dogecoin"] = { wallet[key] / course_assets["Cry_Dogecoin"] };
        break;

    default:
        std::cout << "Invalid choice. Please choose a proper value." << std::endl;
        deposit = IDLE; // Reset to IDLE if input is invalid
        break;
    }
}