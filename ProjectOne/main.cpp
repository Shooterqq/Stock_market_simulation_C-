#include "main.h"
#include "user.h"
#include "instrument.h"

void add(int a, int b)
{
    std::cout << "Hello World! \n" << a << b << "\n";
    a *= b;
}

int main()
{
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
