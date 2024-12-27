#include "main.h"
#include "user.h"
#include "instrument.h"

void add(int a, int b)
{
    std::cout << "Hello World! \n" << a << b << "\n";
    a *= b;
}

void displayMenu() 
{
    std::cout << "1. Stwórz konto\n";
    std::cout << "1. Zmień konto\n";
    std::cout << "2. Wyświetl stan kont\n";
    std::cout << "3. Zarządzaj kontem\n";
    std::cout << "4. Pokaż historię kont\n";
    std::cout << "5. Następne konto\n";
    std::cout << "6. Wyjdź\n";
    std::cout << "Wybierz opcję: ";
}

void displayActualAccount()
{
    //std::cout << "Now plays: " << getClientName() << " " << getClientSurname() << "\n";
}

void updateAssetPrices(walletGoods& marketPrices) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-5.0, 5.0);

    for (auto& asset : marketPrices) 
    {
        asset.second += dist(gen);
        asset.second = std::max(0.1f, asset.second); // Zapewniamy, że cena nie jest ujemna
    }
    std::cout << "Kursy aktywów zostały zaktualizowane.\n";
}

int main()
{
    std::unordered_map<std::string, std::shared_ptr<UserAccount>> accountMap;
    auto account_Iterator = accountMap.begin();

    bool gameRunning = true;
    int turn = 0;

    std::vector<UserAccount*> accounts;

    sm_main sm_main_choose = MENU;
    int userInput;
    std::cin >> userInput;
    sm_main_choose = static_cast<sm_main>(userInput);

    while (gameRunning) {
        std::cout << "\nTura: " << turn << "\n";
        displayMenu();


        int input_val;
        std::cin >> input_val;
        sm_main_choose = static_cast<sm_main>(input_val);


        switch (sm_main_choose)
        {
        case CREATE_ACCOUNT:
        {
            std::string name, surname;
            float initialDeposit;
            int account_type;

            std::cout << "Wybierz jaki rodzaj konta chcesz otworzyć \n";
            std::cout << "1. konto oszczednosciowe \n";
            std::cout << "2. konto inwestycyjne \n";
            std::cin >> account_type;

            std::cout << "Podaj imię: ";
            std::cin >> name;

            std::cout << "Podaj nazwisko: ";
            std::cin >> surname;

            std::cout << "Podaj początkowy depozyt: ";
            std::cin >> initialDeposit;

            std::string fullName = name + " " + surname;

            // Sprawdzenie i dodanie konta
            if (accountMap.count(fullName) == 0)
            {
                accountMap[fullName] = std::make_shared<UserAccountInvest>(name, surname, initialDeposit);
                std::cout << "Dodano nowe konto dla: " << fullName << std::endl;


            }
            else
            {
                std::cout << "Konto już istnieje dla: " << fullName << std::endl;
            }

            break; 
            
        }
        case MENU:
        { 
            std::string name, surname;

            std::cout << "--Zmiana konta-- ";

            std::cout << "Podaj imię: ";
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
            break;

        }
        case SHOW_ACCOUNTS:
        { // Wyświetl stan kont
            for (const auto& account : accountMap) 
            {
                account.second->showGlobalWallet();
            }
            break;

        }
        case MANAGE_ACCOUNT:
        { // Zarządzaj kontem

            //account_Iterator->second->showHistory();

            if (account_Iterator != accountMap.end()) {  // Sprawdzenie, czy znaleziono konto
                // Dynamiczne rzutowanie na UserAccountSavings
                if (auto savingsAccount = std::dynamic_pointer_cast<UserAccountSavings>(account_Iterator->second)) 
                {
                    std::cout << "Typ: Konto oszczędnościowe." << std::endl;
                    // Tu możesz wywołać funkcje specyficzne dla UserAccountSavings
                    savingsAccount->showGlobalWallet();
                }
                // Dynamiczne rzutowanie na UserAccountInvest
                else if (auto investAccount = std::dynamic_pointer_cast<UserAccountInvest>(account_Iterator->second)) 
                {
                    std::cout << "Typ: Konto inwestycyjne." << std::endl;
                    // Tu możesz wywołać funkcje specyficzne dla UserAccountInvest
                    investAccount->showGlobalWallet();
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


            break;

        }
        case 4: 
        { // Pokaż historię kont
            for (const auto& account : accounts) {
                account->showHistory();
            }
            break;

        }
        case 5: 
        { // Następna tura
            accountMap;
            updateAssetPrices(course_assets);
            ++turn;
            break;

        }
        case 6: 
        { // Wyjdź
            gameRunning = false;
            break;

        }
        default:
            std::cout << "Niepoprawny wybór.\n";
            break;

        }
    }

    // Sprzątanie pamięci
    for (auto account : accounts) {
        delete account;
    }









    //auto it = accountMap.find(searchKey);
    //if (it != accountMap.end()) {
    //    UserAccount* account = it->second;
    //    std::cout << "Znaleziono konto użytkownika: "
    //        << searchName << " " << searchSurname << std::endl;
    //    account->generateReport(); // Możesz wywołać dowolne metody
    //}
    //else {
    //    std::cout << "Nie znaleziono użytkownika " << searchKey << std::endl;
    //}



    std::cout << "Hello World!\n";
    add(1, 2);

    // Wartość początkowa w USD
    float usdStartValue = 1000.0f;

    // Tworzenie obiektu UserAccount
    UserAccountSavings account("John", "Doe", usdStartValue);

    // Opcjonalne wyświetlenie danych
    account.getClientName();
     

    UserAccountSavings account2; // Tworzenie instancji klasy

    // Wywołanie funkcji z mapą utworzoną bezpośrednio w wywołaniu
    account2.buyDeposit({ { "Money", 300.0 } });


    UserAccountInvest account3;
     
    account3.buyHouses({ { "Money", 19000.0 } });

    account3.showMyWallet();

    return 0;

}





// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
