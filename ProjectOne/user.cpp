#include "user.h"


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

walletGoods client_Houses =
{

};

enum State_deposit 
{
    IDLE,
    DEPOSIT_AT_4,
    DEPOSIT_AT_5,
    DEPOSIT_AT_6
};

State_deposit deposit;

assets typeOfAssets =
{
    {"Currencies", {"Dollar", "Euro", "British Pound"}},
    {"Stocks", {"Microsoft", "Apple", "Samsung"}},
    {"Deposits", {"DepositAt4", "DepositAt5", "DepositAt6"}},
    {"Crypto", {"Bitcoin", "Etherium", "Dogecoin"}},
    {"Bonds", {"Bonds3Years", "Bonds5Years", "Bonds10Years"}}
};

// variable worths of assets
walletInstruments valueOfAssets =
{
    {"Currencies", {3.40, 4.25, 5.20}},
    {"Stocks", {0.25, 0.30, 0.35}},
    {"Deposits", {5, 7, 10}},           // in %
    {"Crypto", {100000, 40000, 2}},
    {"Bonds", {7, 10, 14}}              // in %
};

walletGoods course_assets =
{
    {"Cur_Dollar", 3.40},
    {"Cur_Euro", 4.25},
    {"Cur_British_Pound", 5.20},
    {"St_Microsoft", 0.25},
    {"St_Apple", 0.30},
    {"St_Samsung", 0.35},
    {"DepositAt4", 5},
    {"DepositAt5", 7},
    {"DepositAt6", 10},
    {"Cry_Bitcoin", 100000},
    {"Cry_Etherium", 40000},
    {"Cry_Dogecoin", 2},
    {"Bonds3Years", 7},
    {"Bonds5Years", 10},
    {"Bonds10Years", 14},
    {"Gold", 12000},
    {"House_Warsaw", 19000},        // per meter
    {"House_Berlin", 15000},
    {"House_Mexico_City", 2500}
};
 



int UserAccount::client_Id = 0;

UserAccount::UserAccount(const std::string& name, const std::string& surname, float& usd_Start_Val)
    : client_Name(name),
    client_Surname(surname),
    account_Activation_Status(true)
{
    client_Goods["Cur_Dollar"] = {usd_Start_Val};
    client_Id += 1;
}


UserAccount::UserAccount()
    : account_Activation_Status(false)
{
    client_Id += 1;
}

UserAccount::~UserAccount()
{
    client_Id -= 1;
}

void UserAccount::showGlobalWallet() const
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

void UserAccount::depositMoney(std::string& assetType, float& deposit_Amount)
{
    try
    {
        client_Goods.at(assetType) += deposit_Amount; // Increase value if key exists

        float courseOfAsset = course_assets.at(assetType);
        client_History.insert({ assetType, {courseOfAsset, deposit_Amount} });
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: The asset type \"" << assetType << "\" does not exist in client_Goods.\n";
    }
}


double UserAccount::calculateAccountWorth() const
{
    double total_Worth = 0;

    for (const auto& [category, keys] : typeOfAssets) 
    {
        const auto& rates = valueOfAssets.at(category);
        for (size_t i = 0; i < keys.size(); ++i) 
        {
            float multiplier = (category == "Deposits" || category == "Bonds") ? rates[i] / 100 : rates[i];
            total_Worth += client_Goods.at(keys[i]) * multiplier;
        }
    }

    return total_Worth;
}

void UserAccount::showHistory() const
{
    for (const auto& [category, values] : client_History)
    {
        std::cout << "Category: " << category
            << ", Course: " << values.at(0)
            << ", Deposit Amount: " << values.at(1)
            << '\n';
    }
}
void UserAccount::getClientName() const
{
    std::cout << client_Name;
}

void UserAccount::getClientSurname() const
{
    std::cout << client_Surname;
}

void UserAccount::getNumberOfClients() const
{
    std::cout << client_Id;
}

// --------------------------------------------------------------------------------------------------------------------------------------------- //

void UserAccountSavings::getSaveClientName() const
{
    getClientName();
}

void UserAccountSavings::showGlobalWallet() const
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

void UserAccountSavings::generateReport() const
{
    std::cout << "123";
}

void UserAccountSavings::buyDeposit(walletGoods wallet)
{
    std::string key = "Money";

    if(client_Wallet_Money[key] > wallet[key])
    {
        std::cout << "You have too low money in your wallet" << std::endl;
        return;
    }
    std::cout << "Please choose the period and interest rate of your deposit:" << std::endl;
    std::cout << "1. Deposit for 6 months with 4% interest rate" << std::endl;
    std::cout << "2. Deposit for 9 months with 5% interest rate" << std::endl;
    std::cout << "3. Deposit for 12 months with 6% interest rate" << std::endl;

    int userInput;
    std::cin >> userInput;
    deposit = static_cast<State_deposit>(userInput);

    switch (deposit)
    {
    case DEPOSIT_AT_4:
        std::cout << "Chosed 6 months with 4% interest rate." << std::endl;
        client_Goods["DepositAt4"] = { wallet[key] };
        break;

    case DEPOSIT_AT_5:
        std::cout << "Chosed 9 months with 5% interest rate." << std::endl;
        client_Goods["DepositAt5"] = { wallet[key] };
        break;

    case DEPOSIT_AT_6:
        std::cout << "Chosed 12 months with 6% interest rate." << std::endl;
        client_Goods["DepositAt6"] = { wallet[key] };
        break;

    default:
        std::cout << "Invalid choice. Please choose a proper value." << std::endl;
        deposit = IDLE; // Reset to IDLE if input is invalid
        break;
    }
}




void UserAccountSavings::buyGold(walletGoods wallet)
{
    std::string key = "Money";

    if (client_Wallet_Money[key] > wallet[key])
    {
        std::cout << "You have too low money in your wallet" << std::endl;
        return;
    }
    client_Goods["Gold"] = { wallet[key] * (1 / course_assets["Gold"]) };
    std::cout << "Gold purchased. Excellent choice." << std::endl;
}

void UserAccountSavings::withdrawMoney(walletGoods wallet)
{
    std::string key = "Money";

    if (client_Wallet_Money[key] > wallet[key])
    {
        std::cout << "You have too low money in your wallet" << std::endl;
        return;
    }

    client_Wallet_Money[key] -= wallet[key];
    std::cout << "Money withdrawed. Your actual account state is: " << client_Wallet_Money[key] << std::endl;

}

// --------------------------------------------------------------------------------------------------------------------------------------------- //


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
    for (const auto& [category, values] : client_Goods)
    {
        std::cout << category << " - " << values << std::endl;
    }
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

 
