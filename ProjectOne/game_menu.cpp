#include "game_menu.h"
#include "UserAccount.h"
#include "UserAccountSavings.h"

std::unordered_map<std::string, std::shared_ptr<UserAccount>> accountMap;
std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator account_Iterator = accountMap.begin();


void menu_updateAssetPrices(walletGoods& marketPrices)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-5.0, 5.0);

    for (auto& asset : marketPrices)
    {
        asset.second += dist(gen);
        asset.second = std::max(0.1f, asset.second); // Zapewniamy, ¿e cena nie jest ujemna
    }
    std::cout << "Course of assets are changed.\n";
}

void menu_saveToCSV(const walletGoods& market_Prices, const std::string& file_Name) 
{
    std::ofstream file;

    bool fileExists = std::ifstream(file_Name).good();   // Checking if a file already exists

    /* 
    Open the file in write mode(out) with the append option(app)
    std::ios::out - Opens the file in write mode, allowing data to be written to the file.
    std::ios::app - Sets the file cursor to the end to append new data without overwriting existing data.
    If the file does not exist, it will be created. If it does exist, the data will be appended to the end. 
    */
    file.open(file_Name, std::ios::out | std::ios::app);     // <-- std::ios::trunc - alternative for out

    if (!file.is_open()) 
    {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }

    file << std::fixed << std::setprecision(2);     // Setting float number and precision 

    if (!fileExists)            // If the file does not exist yet, save the headers
    {
        for (auto it = market_Prices.begin(); it != market_Prices.end(); ++it)
        {
            file << it->first;
            if (std::next(it) != market_Prices.end())
            {
                file << ";";    // next column
            }
        }
        file << "\n";           // next row
    }

    // Saving the rate value (each iteration in a new line)
    for (auto it = market_Prices.begin(); it != market_Prices.end(); ++it)
    {
        file << it->second;
        if (std::next(it) != market_Prices.end())
        {
            file << ";";        // next column
        }
    }
    file << "\n";               // next row

    file.close();
    std::cout << "Data saved to " << file_Name << "\n";
}

void menu_runPythonScript(const std::string& scriptName, const std::string& csvFile) 
{
    int culumn_Num{ 0 };
    menu_readAssetsNames();
    do
    {
        std::cout << "\nEnter value betwen 0 - 18: ";
        isEnterValNum(culumn_Num);
    }while (!(culumn_Num <= 18 && culumn_Num >= 0));

    std::string command = "python " + scriptName + " " + csvFile + " " + std::to_string(culumn_Num);
    int result = std::system(command.c_str());
    if (result == 0)
    {
        std::cout << "Python script executed successfully.\n";
    }
    else 
    {
        std::cerr << "Error: Python script execution failed.\n";
    }
}

void menu_displayMenu(void)
{
    std::cout << "1. Create account\n";
    std::cout << "2. Change account\n";
    std::cout << "3. Display wallet\n";
    std::cout << "4. Manage account\n";
    std::cout << "5. Show history\n";
    std::cout << "6. Next turn\n";
    std::cout << "7. Plot chart of asset rate\n";
    std::cout << "8. Exit\n\n";
    std::cout << "Enter option: ";
}

void menu_displayActualAccount(void)
{
    //std::cout << "Now plays: " << getClientName() << " " << getClientSurname() << "\n";
}

void menu_changeKnownAccount(std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator& account_Iterator)
{
    std::string name, surname;

    std::cout << "--Zmiana konta--\n";

    std::cout << "Podaj imiê: ";
    std::cin >> name;

    std::cout << "Podaj nazwisko: ";
    std::cin >> surname;

    std::string fullName = name + " " + surname;

    auto it = accountMap.find(fullName);

    if (it != accountMap.end()) 
    {
        account_Iterator = it;
        std::cout << "Zmieniono na konto: " << fullName << "\n";
    }
    else 
    {
        std::cout << "Nie znaleziono konta: " << fullName << "\n";
    }
}



void menu_showSaveAccManageMenu(void)
{
    std::cout << "Type: Konto oszczêdnoœciowe." << std::endl;

    std::cout << "Choose option to manage your account:" << std::endl;
    std::cout << "1. showGlobalWallet" << std::endl;
    std::cout << "2. buyDeposit" << std::endl;
    std::cout << "3. buyGold" << std::endl;
    std::cout << "4. calculateAccountWorth" << std::endl;
    std::cout << "5. depositMoney" << std::endl;
    std::cout << "6. generateReport" << std::endl;
    std::cout << "7. getClientName" << std::endl;
    std::cout << "8. getClientSurname" << std::endl;
    std::cout << "9. getNumberOfClients" << std::endl;
    std::cout << "10. getSaveClientName" << std::endl;
    std::cout << "11. showGlobalWallet" << std::endl;
    std::cout << "12. withdrawMoney" << std::endl;
    std::cout << "13. Delete account" << std::endl;
    std::cout << "14. Exit" << std::endl;
}

void menu_showInvestAccManageMenu(void)
{
    std::cout << "Typ: Konto inwestycyjne." << std::endl;

    std::cout << "Choose option to manage your account:" << std::endl;
    std::cout << "1. buyCrypto" << std::endl;
    std::cout << "2. buyCurrencies" << std::endl;
    std::cout << "3. buyHouses" << std::endl;
    std::cout << "4. buyShares" << std::endl;
    std::cout << "5. calculateAccountWorth" << std::endl;
    std::cout << "6. depositMoney" << std::endl;
    std::cout << "7. generateReport" << std::endl;
    std::cout << "8. getClientName" << std::endl;
    std::cout << "9. getClientSurname" << std::endl;
    std::cout << "10. getNumberOfClients" << std::endl;
    std::cout << "11. showGlobalWallet" << std::endl;
    std::cout << "12. showHistory" << std::endl;
    std::cout << "13. showMyWallet" << std::endl;
    std::cout << "14. Delete account" << std::endl;
    std::cout << "15. Exit" << std::endl;
}

void menu_gameMenuRutine(void)
{
    1;
}


void menu_updateAllDeposits(std::unordered_map<std::string, std::shared_ptr<UserAccount>>& accountMap, int currentTurn)
{
    for (auto& [username, account] : accountMap) 
    {
        auto savingsAccount = std::dynamic_pointer_cast<UserAccountSavings>(account);

        if (savingsAccount)
        {
            std::cout << "Updating deposits for savings account: " << username << "\n";
            //  SprawdŸ, czy klucz "Money" istnieje
            //if (savingsAccount->client_Wallet_Money.find("Money") != savingsAccount->client_Wallet_Money.end())
            //{
                // Pobierz referencjê do wartoœci
                savingsAccount->updateDeposits(currentTurn);
            //}
            //else
            //{
            //    std::cerr << "Key 'Money' not found in client_Wallet_Money map for account " << username << "\n";
            //}
        }
        else 
        {
            std::cout << "Account " << username << " has no deposits to update.\n";
        }
    }
}


std::string menu_createAccount(void)
{
    std::string name, surname;
    float initial_Deposit{ 0 };
    int account_type{ 0 };

    std::cout << "Please choose account type to create: \n";
    std::cout << "1. Savings account \n";
    std::cout << "2. Investition account \n";
    std::cin >> account_type;

    std::cout << "\nEnter your name: ";
    std::cin >> name;

    std::cout << "\nEnter your surname: ";
    std::cin >> surname;

    std::cout << "\nEnter initial deposit: ";
    std::cin >> initial_Deposit;

    std::string fullName = name + " " + surname;

    if (account_type == 1)
    {
        if (accountMap.count(fullName) == 0)
        {
            accountMap[fullName] = std::make_shared<UserAccountSavings>(name, surname, initial_Deposit);
            std::cout << "Added new account for: " << fullName << std::endl;
        }
        else
        {
            std::cout << "\n------------------------------------ ";
            std::cout << "\nERROR - This account already exist: " << fullName << std::endl;
        }
    }
    else if (account_type == 2)
    {
        if (accountMap.count(fullName) == 0)
        {
            accountMap[fullName] = std::make_shared<UserAccountInvest>(name, surname, initial_Deposit);
            std::cout << "Dodano nowe konto dla: " << fullName << std::endl;
        }
        else
        {
            std::cout << "Konto ju¿ istnieje dla: " << fullName << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid value: " << account_type << std::endl;
    }
    account_Iterator = accountMap.find(fullName);		// set iterator to actual created account

    return fullName;
}

void menu_manageAccount(static int turn)
{
    if (account_Iterator != accountMap.end()) {  // Sprawdzenie, czy znaleziono konto

        if (auto savingsAccount = std::dynamic_pointer_cast<UserAccountSavings>(account_Iterator->second))	// Dynamiczne rzutowanie na UserAccountSavings
        {
            int choosed_func = 0;

            std::unordered_map<int, std::function<void()>> actions_Savings_Account =
            { 
                {0, [&]() { savingsAccount->sellAsset(); }},
                {1, [&]() { savingsAccount->showGlobalWallet(); }},
                {2, [&]() { savingsAccount->buyDeposit(turn); }},
                {3, [&]() { savingsAccount->buyGold(); }},
                {4, [&]() { savingsAccount->calculateAccountWorth(); }},
                {5, [&]() { savingsAccount->depositMoney("Money", 5.0f); }},
                {6, [&]() { savingsAccount->generateReport(); }},
                {7, [&]() { savingsAccount->getClientName(); }},
                {8, [&]() { savingsAccount->getClientSurname(); }},
                {9, [&]() { savingsAccount->getNumberOfClients(); }},
                {10, [&]() { savingsAccount->getSaveClientName(); }},
                {11, [&]() { savingsAccount->showGlobalWallet(); }},
                {12, [&]() { savingsAccount->withdrawMoney(); }},
                {13, [&]() { savingsAccount->~UserAccountSavings();
                             accountMap.erase(account_Iterator);
                             std::cout << "Konto zosta³o usuniête." << std::endl; }},
            };

            menu_showSaveAccManageMenu();

            std::cin >> choosed_func;

            if (choosed_func == 14) {
                std::cout << "Exiting program." << std::endl;
                return;
            }

            auto action = actions_Savings_Account.find(choosed_func);

            if (action != actions_Savings_Account.end())
            {
                action->second();  // Wywo³anie odpowiedniej funkcji
            }
            else
            {
                std::cout << "Invalid option. Please try again." << std::endl;
            }
        }

        else if (auto investAccount = std::dynamic_pointer_cast<UserAccountInvest>(account_Iterator->second))	// Dynamiczne rzutowanie na UserAccountInvest
        {
            int choosed_func = 0;

            std::unordered_map<int, std::function<void()>> actions_Invest_Account =
            {
                {1, [&]() { investAccount->buyCrypto(); }},
                {2, [&]() { investAccount->buyCurrencies(); }},
                {3, [&]() { investAccount->buyHouses(); }},
                {4, [&]() { investAccount->buyShares(); }},
                {5, [&]() { investAccount->calculateAccountWorth(); }},
                {6, [&]() { investAccount->depositMoney("Money", 100); }},
                {7, [&]() { investAccount->generateReport(); }},
                {8, [&]() { investAccount->getClientName(); }},
                {9, [&]() { investAccount->getClientSurname(); }},
                {10, [&]() { investAccount->getNumberOfClients(); }},
                {11, [&]() { investAccount->showGlobalWallet(); }},
                {12, [&]() { investAccount->showHistory(); }},
                {13, [&]() { investAccount->showMyWallet(); }},
                {14, [&]() { investAccount->~UserAccountInvest(); 
                             accountMap.erase(account_Iterator);
                             std::cout << "Konto zosta³o usuniête." << std::endl; }},
            };

            menu_showInvestAccManageMenu();

            std::cin >> choosed_func;

            if (choosed_func == 14)
            {
                std::cout << "Exiting program." << std::endl;
                return;
            }

            auto action = actions_Invest_Account.find(choosed_func);
            if (action != actions_Invest_Account.end())
            {
                action->second();  // Wywo³anie odpowiedniej funkcji
            }
            else
            {
                std::cout << "Invalid option. Please try again." << std::endl;
            }

        }
        else
        {
            std::cout << "Nieznany typ konta." << std::endl;
        }
    }
    else
    {
        std::cout << "Konto o podanym imieniu i nazwisku nie istnieje!" << std::endl;
    }
}

void menu_readAssetsNames(void)
{
    int i{ 0 };
    for (const auto name: course_assets)
    {
        std::cout << i << ". " << name.first << std::endl;
        ++i;
    }
}

