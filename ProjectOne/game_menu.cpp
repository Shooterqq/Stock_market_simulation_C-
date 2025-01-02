#include "game_menu.h"
#include "user.h"

extern std::unordered_map<std::string, std::shared_ptr<UserAccount>> accountMap;
extern std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator account_Iterator;


void updateAssetPrices(walletGoods& marketPrices)
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

void displayMenu(void)
{
    std::cout << "1. Create account\n";
    std::cout << "2. Change account\n";
    std::cout << "3. Display wallet\n";
    std::cout << "4. Manage account\n";
    std::cout << "5. Show history\n";
    std::cout << "6. Next turn\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter option: ";
}

void displayActualAccount(void)
{
    //std::cout << "Now plays: " << getClientName() << " " << getClientSurname() << "\n";
}

extern std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator account_Iterator;

void changeKnownAccount(std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator& account_Iterator)
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



void showSaveAccManageMenu(void)
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

void showInvestAccManageMenu(void)
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
















