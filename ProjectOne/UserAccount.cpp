#include "UserAccount.h"
#include "game_menu.h"

const assets typeOfAssets =
{
    {"Currencies", {"Dollar", "Euro", "British Pound"}},
    {"Stocks", {"Microsoft", "Apple", "Samsung"}},
    {"Deposits", {"DepositAt4", "DepositAt5", "DepositAt6"}},
    {"Crypto", {"Bitcoin", "Etherium", "Dogecoin"}},
    {"Bonds", {"Bonds3Years", "Bonds5Years", "Bonds10Years"}}
};

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

int UserAccount::client_Id = 0;     // static variable

UserAccount::UserAccount(const std::string& name, const std::string& surname, float& usd_Start_Val)
    : client_Name(name),
    client_Surname(surname),
    account_Activation_Status(true)
{
    client_Wallet_Money["Money"] = {usd_Start_Val};
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

std::string UserAccount::getClientName() const
{
    return client_Name;
}

std::string UserAccount::getClientSurname() const
{

    return client_Surname;
}

void UserAccount::getNumberOfClients() const
{
    std::cout << client_Id;
}

void UserAccount::showMyWallet() const
{
    std::cout << "\nAccount: " << this->getClientName() << " " << this->getClientSurname() << std::endl;    
    for (const auto& [category, values] : client_Goods)
    {
        std::cout << category << " - " << values << "\n";
    }
    std::cout << "\n";
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

void UserAccount::depositMoney()     // TODO
{
    menu_readAssetsNames();

    std::string assetType = "Money";
    std::cout << "Enter type of asset to deposit: ";
    std::cin >> assetType;

    float input_Deposit{ 0 };
    std::cout << "Enter amount to deposit: ";
    isEnterValNum(input_Deposit);

    try
    {
        client_Goods.at(assetType) += input_Deposit;            // Increase value if key exists

        float courseOfAsset = course_assets.at(assetType);
        client_History.insert({ assetType, {courseOfAsset, input_Deposit} });
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: The asset type \"" << assetType << "\" does not exist in client_Goods.\n";
    }
}

float UserAccount::calculateAccountWorth() const
{
    float total_Worth = 0;

    for (const auto& [category, keys] : course_assets)
    {
        for (const auto& [asset, amount] : client_Goods)
        {
            float multiplier = (category.find("Deposit") != std::string::npos ||
                category.find("Bonds") != std::string::npos) ? keys / 100 : keys;

            if (category == asset)
            {
                total_Worth += amount * multiplier;
            }
        }
    }
    total_Worth += client_Wallet_Money.at("Money");
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

void UserAccount::sellAsset()
{
    std::cout << "\nYou have " << client_Wallet_Money[WALLET_KEY] << " money.\n" << std::endl;

    showMyWallet();

    std::cout << "\nEnter type of asset to sell: " << std::endl;
    std::string asset_type;
    std::cin >> asset_type;

    std::cout << "\nEnter how much do you want to sell: " << std::endl;

    int asset_amount{ 0 };
    isEnterValNum(asset_amount);

    if (client_Goods[asset_type] < asset_amount)
    {
        std::cout << "\nYou enter too high value. You don't have that much amount of this asset.\n" << std::endl;
        return;
    }

    client_Goods[asset_type] -= asset_amount;
    client_Wallet_Money[WALLET_KEY] += asset_amount * ((course_assets[asset_type] * 90/100));

    std::cout << "\nAsset sold.After this operation you have: " << client_Goods[asset_type] << client_Goods[asset_type] <<std::endl;
    std::cout << "\nYou have " << client_Wallet_Money[WALLET_KEY] << " money.\n" << std::endl;
}

