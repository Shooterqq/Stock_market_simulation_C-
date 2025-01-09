#include "UserAccountSavings.h"

void UserAccountSavings::getSaveClientName() const
{
    getClientName();
}

void UserAccountSavings::addDeposit(int startTurn, int duration, float amount, float interestRate)
{
    saveAcc_Deposit_List.push_back({ startTurn, duration, amount, interestRate });
}

void UserAccountSavings::updateDeposits(int currentTurn)
{
    for (auto it = saveAcc_Deposit_List.begin(); it != saveAcc_Deposit_List.end(); )
    {
        if (currentTurn - it->startTurn >= it->duration)
        {
            // 1 because we have to take into account the initial value
            // devide by 100 for make percentage investing rate 
            float maturedAmount = it->amount * (1 + it->interestRate / 100.0f);
            this->client_Wallet_Money["Money"] += maturedAmount;       // add interest to deposit
            std::cout << "Deposit matured! Returned " << maturedAmount << " to the account.\n";

            if (it->interestRate == DEPOSIT_INVEST_RATE_4)
            {
                this->client_Goods[DDEPOSIT_AT_4] -= it->amount;
            }
            else if (it->interestRate == DEPOSIT_INVEST_RATE_5)
            {
                this->client_Goods[DDEPOSIT_AT_5] -= it->amount;
            }
            else if (it->interestRate == DEPOSIT_INVEST_RATE_6)
            {
                this->client_Goods[DDEPOSIT_AT_6] -= it->amount;
            }
            else
            {
                std::cout << "\n ERROR in updateDeposits function \n";      // it should never happend
            }


            it = saveAcc_Deposit_List.erase(it);    // Delete deposit after it matured
        }
        else
        {
            ++it;    // Iterate to next deposit in list
        }
    }
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

void UserAccountSavings::generateReport() const     // TODO kiedys
{
    std::cout << "Not yet programmed :( \n";
}

void UserAccountSavings::buyDeposit(static int& actual_Turn_Nr)
{
    State_deposit deposit{ SM_DEP_IDLE };
    float user_Input_Deposit{ 0 };

    std::cout << "Your have " << this->client_Wallet_Money[WALLET_KEY] << " money on your account.\n";
    std::cout << "Enter how much you want to deposit: \n";

    isEnterValNum(user_Input_Deposit);

    if (client_Wallet_Money[WALLET_KEY] < user_Input_Deposit)
    {
        std::cout << "You enter too high amount of money." << std::endl;
        return;
    }

    int userInput;
    bool deposit_Run{ true };

    do {
        switch (deposit)
        {
        case SM_DEP_IDLE:
            std::cout << "Please choose the period and interest rate of your deposit:" << std::endl;
            std::cout << "1. Deposit for 6 months with 4% interest rate" << std::endl;
            std::cout << "2. Deposit for 9 months with 5% interest rate" << std::endl;
            std::cout << "3. Deposit for 12 months with 6% interest rate" << std::endl;

            isEnterValNum(userInput);
            deposit = static_cast<State_deposit>(userInput);
            break;

        case SM_DEP_DEPOSIT_AT_4:
            std::cout << "Chosed 6 months with 4% interest rate." << std::endl;
            client_Goods["DepositAt4"] += user_Input_Deposit;
            client_Wallet_Money[WALLET_KEY] -= user_Input_Deposit;
            addDeposit(actual_Turn_Nr, DEPOSIT_MONTHS_6, client_Goods["DepositAt4"], DEPOSIT_INVEST_RATE_4);
            deposit_Run = false;
            break;

        case SM_DEP_DEPOSIT_AT_5:
            std::cout << "Chosed 9 months with 5% interest rate." << std::endl;
            client_Goods["DepositAt5"] += user_Input_Deposit;
            client_Wallet_Money[WALLET_KEY] -= user_Input_Deposit;
            addDeposit(actual_Turn_Nr, DEPOSIT_MONTHS_9, client_Goods["DepositAt5"], DEPOSIT_INVEST_RATE_5);
            deposit_Run = false;
            break;

        case SM_DEP_DEPOSIT_AT_6:
            std::cout << "Chosed 12 months with 6% interest rate." << std::endl;
            client_Goods["DepositAt6"] += user_Input_Deposit;
            client_Wallet_Money[WALLET_KEY] -= user_Input_Deposit;
            addDeposit(actual_Turn_Nr, DEPOSIT_MONTHS_12, client_Goods["DepositAt6"], DEPOSIT_INVEST_RATE_6);
            deposit_Run = false;
            break;

        default:
            std::cout << "Invalid choice. Please choose a proper value. \n" << std::endl;
            deposit = SM_DEP_IDLE;
            break;
        }
    } while (deposit_Run);
}

void UserAccountSavings::buyGold(void)
{
    std::cout << "You have " << client_Wallet_Money[WALLET_KEY] << " money." << std::endl;
    std::cout << "Enter how much money you want to spend on buying gold: " << std::endl;

    int gold_amount{ 0 };
    isEnterValNum(gold_amount);

    if (client_Wallet_Money[WALLET_KEY] < gold_amount)
    {
        std::cout << "You enter too high value." << std::endl;
        return;
    }
    client_Goods[WALLET_GOLD] += gold_amount * (1 / course_assets[WALLET_GOLD]);
    client_Wallet_Money[WALLET_KEY] -= gold_amount;
    std::cout << "Gold purchased. Excellent choice. :) " << std::endl;
}

void UserAccountSavings::withdrawMoney()
{
    std::cout << "You have " << client_Wallet_Money[WALLET_KEY] << " money." << std::endl;
    std::cout << "Enter how much money you want to spend on buying gold: " << std::endl;

    int gold_amount{ 0 };
    isEnterValNum(gold_amount);

    if (client_Wallet_Money[WALLET_KEY] < gold_amount)
    {
        std::cout << "You enter too high value." << std::endl;
        return;
    }

    client_Wallet_Money[WALLET_KEY] -= gold_amount;
    std::cout << "Money withdrawed. Your actual account state is: " << client_Wallet_Money[WALLET_KEY] << std::endl;
}

void UserAccountSavings::showMyWallet() const
{
    std::cout << "\nAccount: " << this->getClientName() << " " << this->getClientSurname() << std::endl;
    for (const auto& [category, values] : client_Goods)
    {
        std::cout << category << " - " << values << "\n";
    }
    std::cout << "\n";
}

