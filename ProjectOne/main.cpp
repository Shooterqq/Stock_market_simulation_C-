#include "main.h"
#include "user.h"
#include "instrument.h"
#include "game_menu.h"


std::unordered_map<std::string, std::shared_ptr<UserAccount>> accountMap;
std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator account_Iterator = accountMap.begin();



int main()
{
	bool gameRunning = true;
	static int turn { 0 };
	sm_main sm_main_choose = MENU;

	while (gameRunning) 
	{
		switch (sm_main_choose)
		{
		case MENU:
		{
			std::cout << "\nTurn number: " << turn << "\n";
			displayMenu();

			int input_val { 0 };
			std::cin >> input_val;
			sm_main_choose = static_cast<sm_main>(input_val);
			break;
		}

		case CREATE_ACCOUNT:
		{
			std::string name, surname;
			float initial_Deposit { 0 };
			int account_type { 0 };

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
					std::cout << "Konto już istnieje dla: " << fullName << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid value: " << account_type << std::endl;
			}
			account_Iterator = accountMap.find(fullName);		// set iterator to actual created account
			sm_main_choose = MENU;
			break;
		}

		case CHANGE_ACCOUNT:
		{
			changeKnownAccount(account_Iterator);
			sm_main_choose = MENU;
			break;
		}

		case SHOW_ACCOUNTS:
		{
			for (const auto& account : accountMap)
			{
				account.second->showMyWallet();
			}
			sm_main_choose = MENU;
			break;
		}

		case MANAGE_ACCOUNT:
		{
			if (account_Iterator != accountMap.end()) {  // Sprawdzenie, czy znaleziono konto
				
				if (auto savingsAccount = std::dynamic_pointer_cast<UserAccountSavings>(account_Iterator->second))	// Dynamiczne rzutowanie na UserAccountSavings
				{
					int choosed_func = 0;

					std::unordered_map<int, std::function<void()>> actions_Savings_Account =
					{
						{1, [&]() { savingsAccount->showGlobalWallet(); }},
						{2, [&]() { savingsAccount->buyDeposit(savingsAccount->client_Wallet_Money, turn); }},
						{3, [&]() { savingsAccount->buyGold({ { "Money", 100 } }); }},
						{4, [&]() { savingsAccount->calculateAccountWorth(); }},
						{5, [&]() { savingsAccount->depositMoney("Money", 5.0f); }},
						{6, [&]() { savingsAccount->generateReport(); }},
						{7, [&]() { savingsAccount->getClientName(); }},
						{8, [&]() { savingsAccount->getClientSurname(); }},
						{9, [&]() { savingsAccount->getNumberOfClients(); }},
						{10, [&]() { savingsAccount->getSaveClientName(); }},
						{11, [&]() { savingsAccount->showGlobalWallet(); }},
						{12, [&]() { savingsAccount->withdrawMoney({ { "Money", 100 } }); }},
						{13, [&]() { accountMap.erase(account_Iterator); 
									 std::cout << "Konto zostało usunięte." << std::endl; }},
					};

					showSaveAccManageMenu();

					std::cin >> choosed_func;

					if (choosed_func == 14) {
						std::cout << "Exiting program." << std::endl;
						break;
					}

					auto action = actions_Savings_Account.find(choosed_func);

					if (action != actions_Savings_Account.end())
					{
						action->second();  // Wywołanie odpowiedniej funkcji
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
						{1, [&]() { investAccount->buyCrypto({ { "Money", 100 } }); }},
						{2, [&]() { investAccount->buyCurrencies({ { "Money", 100 } }); }},
						{3, [&]() { investAccount->buyHouses({ { "Money", 100 } }); }},
						{4, [&]() { investAccount->buyShares({ { "Money", 100 } }); }},
						{5, [&]() { investAccount->calculateAccountWorth(); }},
						{6, [&]() { investAccount->depositMoney("Money", 100); }},
						{7, [&]() { investAccount->generateReport(); }},
						{8, [&]() { investAccount->getClientName(); }},
						{9, [&]() { investAccount->getClientSurname(); }},
						{10, [&]() { investAccount->getNumberOfClients(); }},
						{11, [&]() { investAccount->showGlobalWallet(); }},
						{12, [&]() { investAccount->showHistory(); }},
						{13, [&]() { investAccount->showMyWallet(); }},
						{14, [&]() { accountMap.erase(account_Iterator);
									 std::cout << "Konto zostało usunięte." << std::endl; }},
					};

					showInvestAccManageMenu();

					std::cin >> choosed_func;

					if (choosed_func == 14) 
					{
						std::cout << "Exiting program." << std::endl;
						break;
					}

					auto action = actions_Invest_Account.find(choosed_func);
					if (action != actions_Invest_Account.end())
					{
						action->second();  // Wywołanie odpowiedniej funkcji
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
			sm_main_choose = MENU;
			break;
		}

		case SHOW_HISTORY:
		{
			for (const auto& account : accountMap)
			{
				account.second->showHistory();
			}
			sm_main_choose = MENU;
			break;
		}

		case NEXT_TOUR:
		{
			accountMap;
			std::cout << "\n ---===### A month has passed ###===--- \n";
			updateAssetPrices(course_assets);
			++turn;
			sm_main_choose = MENU;
			break;
		}

		case EXIT:
		{ 
			gameRunning = false;
			break;
		}

		default:
			std::cout << "\nInvalid value.\n";
			sm_main_choose = MENU;
			break;
		}
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



	// Wartość początkowa w USD
	float usdStartValue = 1000.0f;

	// Tworzenie obiektu UserAccount
	UserAccountSavings account("John", "Doe", usdStartValue);

	// Opcjonalne wyświetlenie danych
	account.getClientName();


	UserAccountSavings account2; // Tworzenie instancji klasy

	// Wywołanie funkcji z mapą utworzoną bezpośrednio w wywołaniu
	//account2.buyDeposit({ { "Money", 300.0 } });


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
