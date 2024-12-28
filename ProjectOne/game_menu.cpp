#include "game_menu.h"
#include "user.h"
#include <unordered_map>

extern std::unordered_map<std::string, std::shared_ptr<UserAccount>> accountMap;
extern std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator account_Iterator = accountMap.begin();

void displayMenu(void)
{
    std::cout << "1. Stwórz konto\n";
    std::cout << "1. Zmieñ konto\n";
    std::cout << "2. Wyœwietl stan kont\n";
    std::cout << "3. Zarz¹dzaj kontem\n";
    std::cout << "4. Poka¿ historiê kont\n";
    std::cout << "5. Nastêpne konto\n";
    std::cout << "6. WyjdŸ\n";
    std::cout << "Wybierz opcjê: ";
}

void displayActualAccount(void)
{
    //std::cout << "Now plays: " << getClientName() << " " << getClientSurname() << "\n";
    int a;
}
void changeKnownAccount(void)
{
    std::string name, surname;

    std::cout << "--Zmiana konta-- ";

    std::cout << "Podaj imiê: ";
    std::cin >> name;

    std::cout << "Podaj nazwisko: ";
    std::cin >> surname;

    std::string fullName = name + " " + surname;

    // Sprawdzenie i dodanie konta
    if (accountMap.count(fullName) == 0)
    {
        account_Iterator = accountMap.find(fullName);
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

















