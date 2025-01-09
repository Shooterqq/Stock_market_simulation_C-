#include "UserAccountInvest.h"

void UserAccountInvest::buyShares()
{
    State_shares shares = SM_ST_IDLE;
    float user_Input_Deposit;

    std::cout << "Your have " << client_Wallet_Money[WALLET_KEY] << " money on your account.\n";
    std::cout << "Enter how much you want to deposit: \n";

    isEnterValNum(user_Input_Deposit);

    if (client_Wallet_Money[WALLET_KEY] < user_Input_Deposit)
    {
        std::cout << "You enter too high amount of money." << std::endl;
        return;
    }

    int userInput {0};
    bool shares_Run{ true };

    do {
        switch (shares)
        {
        case SM_ST_IDLE:
            std::cout << "Please choose type of stocks to purchase:" << std::endl;
            std::cout << "1. Microsoft" << std::endl;
            std::cout << "2. Apple" << std::endl;
            std::cout << "3. Samsung" << std::endl;

            isEnterValNum(userInput);
            shares = static_cast<State_shares>(userInput);
            break;

        case SM_ST_MICROSOFT:
            std::cout << "Chosed St_Microsoft" << std::endl;
            client_Goods[ST_MICROSOFT] = { user_Input_Deposit * (1 / course_assets[ST_MICROSOFT]) };
            shares_Run = false;
            break;

        case SM_ST_APPLE:
            std::cout << "Chosed St_Apple" << std::endl;
            client_Goods[ST_APPLE] = { user_Input_Deposit * (1 / course_assets[ST_APPLE]) };
            shares_Run = false;
            break;

        case SM_ST_SAMSUNG:
            std::cout << "Chosed St_Samsung" << std::endl;
            client_Goods[ST_SAMSUNG] = { user_Input_Deposit * (1 / course_assets[ST_SAMSUNG]) };
            shares_Run = false;
            break;

        default:
            std::cout << "Invalid choice. Please choose a proper value." << std::endl;
            shares = SM_ST_IDLE; // Reset to IDLE if input is invalid
            break;
        }
    } while (shares_Run);
}

void UserAccountInvest::buyHouses()
{
    State_houses houses = SM_DEV_IDLE;
    float user_Input_Deposit { 0 };

    std::cout << "Your have " << this->client_Wallet_Money[WALLET_KEY] << " money on your account.\n";
    std::cout << "Enter how much you want to deposit: \n";

    isEnterValNum(user_Input_Deposit);

    if (client_Wallet_Money[WALLET_KEY] < user_Input_Deposit)
    {
        std::cout << "You enter too high amount of money." << std::endl;
        return;
    }

    int userInputCity;
    bool houses_Run{ true };

    do {
        switch (houses)
        {
        case SM_DEV_IDLE:
            std::cout << "Please choose city, where you want to buy house:" << std::endl;
            std::cout << "1. Warsaw" << std::endl;
            std::cout << "2. Berlin" << std::endl;
            std::cout << "3. Mexico City" << std::endl;

            isEnterValNum(userInputCity);
            houses = static_cast<State_houses>(userInputCity);
            break;

        case SM_DEV_HOUSE_WARSAW:
            std::cout << "Chosed Warsaw - grey, dark and cold piece of hell" << std::endl;
            //userMeters = chooseMeters();
            client_Goods[DEV_HS_WARSAW] += user_Input_Deposit / course_assets[DEV_HS_WARSAW];
            client_Wallet_Money[WALLET_KEY] -= user_Input_Deposit;
            houses_Run = false;
            break;

        case SM_DEV_HOUSE_BERLIN:
            std::cout << "Chosed House_Berlin" << std::endl;
            //userMeters = chooseMeters();
            client_Goods[DEV_HS_BERLIN] +=  user_Input_Deposit / course_assets[DEV_HS_BERLIN] ;
            client_Wallet_Money[WALLET_KEY] -= user_Input_Deposit;
            houses_Run = false;
            break;

        case SM_DEV_HOUSE_MEXICO_CITY:
            std::cout << "Chosed House_Mexico_City" << std::endl;
            //userMeters = chooseMeters();
            client_Goods[DEV_HS_MEXICO_CITY] += user_Input_Deposit / course_assets[DEV_HS_MEXICO_CITY];
            client_Wallet_Money[WALLET_KEY] -= user_Input_Deposit;
            houses_Run = false;
            break;

        default:
            std::cout << "Invalid choice. Please choose a proper value." << std::endl;
            houses = SM_DEV_IDLE; // Reset to IDLE if input is invalid
            break;
        }
    } while (houses_Run);
}

float chooseMeters(void)
{
    float userInputMeters;

    std::cout << "Chow much meters?:" << std::endl;
    isEnterValNum(userInputMeters);

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

void UserAccountInvest::showMyWallet() const
{
    std::cout << "\nAccount: " << this->getClientName() << " " << this->getClientSurname() << "\n";
    for (const auto& [category, values] : client_Goods)
    {
        std::cout << category << " - " << values << "\n";
    }
    std::cout << "\n";
}

void UserAccountInvest::buyCurrencies()
{
    State_currenties currencies = SM_CUR_IDLE;
    float in_Val_Of_Currienties {0};

    std::cout << "Your have " << client_Wallet_Money[WALLET_KEY] << " money on your account.\n";
    std::cout << "Enter how much you want to deposit: \n";

    isEnterValNum(in_Val_Of_Currienties);

    if (client_Wallet_Money[WALLET_KEY] < in_Val_Of_Currienties)
    {
        std::cout << "You enter too high amount of money." << std::endl;
        return;
    }
    int cur_Chose_Option {0};
    bool currenties_Run {true};

	do {
		switch (currencies)
		{
		case SM_CUR_IDLE:
			std::cout << "Please choose currienties to buy:" << std::endl;
			std::cout << "1. Dollar" << std::endl;
			std::cout << "2. Euro" << std::endl;
			std::cout << "3. British Pound" << std::endl;

			isEnterValNum(cur_Chose_Option);
            currencies = static_cast<State_currenties>(cur_Chose_Option);
			break;

		case SM_CUR_DOLLAR:
			std::cout << "Chosed Dollar" << std::endl;
			client_Goods[CUR_DOLLAR] += in_Val_Of_Currienties / course_assets[CUR_DOLLAR];
            client_Wallet_Money[WALLET_KEY] -= in_Val_Of_Currienties;
            currenties_Run = false;
			break;

		case SM_CUR_EURO:
			std::cout << "Chosed Euro" << std::endl;
			client_Goods[CUR_EURO] += in_Val_Of_Currienties / course_assets[CUR_EURO];
            client_Wallet_Money[WALLET_KEY] -= in_Val_Of_Currienties;
            currenties_Run = false;
			break;

		case SM_CUR_BRITISH_POUND:
			std::cout << "Chosed British Pound" << std::endl;
			client_Goods[CUR_BRITISH_POUND] += in_Val_Of_Currienties / course_assets[CUR_BRITISH_POUND];
            client_Wallet_Money[WALLET_KEY] -= in_Val_Of_Currienties;
            currenties_Run = false;
			break;

		default:
			std::cout << "Invalid choice. Please choose a proper value." << std::endl;
            currencies = SM_CUR_IDLE;
			break;
		}
	} while (currenties_Run);
}

void UserAccountInvest::buyCrypto()
{
    State_crypto crypto = SM_CR_IDLE;
    float in_Val_Of_Crypto { 0 };

    std::cout << "Your have " << client_Wallet_Money[WALLET_KEY] << " money on your account.\n";
    std::cout << "Enter how much you want to deposit: \n";

    isEnterValNum(in_Val_Of_Crypto);

    if (client_Wallet_Money[WALLET_KEY] < in_Val_Of_Crypto)
    {
        std::cout << "You enter too high amount of money." << std::endl;
        return;
    }

    int userInputCurypto {0};
    bool crypto_Run {true};

    do {
        switch (crypto)
        {
        case SM_CR_IDLE:
            std::cout << "Please choose crypto to buy:" << std::endl;
            std::cout << "1. Bitcoin" << std::endl;
            std::cout << "2. Etherium" << std::endl;
            std::cout << "3. Dogecoin" << std::endl;

            isEnterValNum(userInputCurypto);
            crypto = static_cast<State_crypto>(userInputCurypto);
            break;

        case SM_CR_BITCOIN:
            std::cout << "Chosed Bitcoin" << std::endl;
            client_Goods[CRY_BITCOIN] += in_Val_Of_Crypto / course_assets[CRY_BITCOIN];
            client_Wallet_Money[WALLET_KEY] -= in_Val_Of_Crypto;
            crypto_Run = false;
            break;

        case SM_CR_ETHERIUM:
            std::cout << "Chosed Etherium" << std::endl;
            client_Goods[CRY_ETHERIUM] += in_Val_Of_Crypto / course_assets[CRY_ETHERIUM];
            client_Wallet_Money[WALLET_KEY] -= in_Val_Of_Crypto;
            crypto_Run = false;
            break;

        case SM_CR_DOGECOIN:
            std::cout << "Chosed Dogecoin" << std::endl;
            client_Goods[CRY_DOGECOIN] += in_Val_Of_Crypto / course_assets[CRY_DOGECOIN];
            client_Wallet_Money[WALLET_KEY] -= in_Val_Of_Crypto;
            crypto_Run = false;
            break;

        default:
            std::cout << "Invalid choice. Please choose a proper value." << std::endl;
            crypto = SM_CR_IDLE;
            break;
        }
    } while(crypto_Run);
}