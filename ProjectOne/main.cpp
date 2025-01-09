/********************************************************************************
  * @file           : main.cpp
  * @brief          : Main program file
  ******************************************************************************
  * @author         : Piotr Wiski
  * @date           : 2025-01-04
  * @version        : 1.0
  * @description    : Bank account with stock market simulation
  ******************************************************************************
  * @license
  *
  * This software is provided "as is", without warranty of any kind, express
  * or implied, including but not limited to the warranties of merchantability,
  * fitness for a particular purpose, and noninfringement. In no event shall
  * the authors or copyright holders be liable for any claim, damages, or
  * other liability, whether in an action of contract, tort, or otherwise,
  * arising from, out of or in connection with the software or the use or
  * other dealings in the software.
  *
  *******************************************************************************/

#include "main.h"
#include "UserAccount.h"
#include "instrument.h"
#include "game_menu.h"
#include "UserAccountInvest.h"

int main()
{
	const std::string filename = "market_data.csv";

	extern std::unordered_map<std::string, std::shared_ptr<UserAccount>> accountMap;
	extern std::unordered_map<std::string, std::shared_ptr<UserAccount>>::iterator account_Iterator;

	bool gameRunning = true;
	static int turn { 0 };
	sm_mn_main sm_main_choose = SM_MN_MENU;

	while (gameRunning) 
	{
		switch (sm_main_choose)
		{
		case SM_MN_MENU:
		{
			std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++";
			std::cout << "\n---=== Turn number: " << turn << " ===---\n\n";
			menu_displayMenu();

			int input_val{ 0 };
			isEnterValNum(input_val);
			sm_main_choose = static_cast<sm_mn_main>(input_val);
			break;
		}

		case SM_MN_CREATE_ACCOUNT:
		{
			menu_createAccount();
			sm_main_choose = SM_MN_MENU;
			break;
		}

		case SM_MN_CHANGE_ACCOUNT:
		{
			menu_changeKnownAccount(account_Iterator);
			sm_main_choose = SM_MN_MENU;
			break;
		}

		case SM_MN_SHOW_ACCOUNTS:
		{
			for (const auto& account : accountMap)
			{
				account.second->showMyWallet();
			}
			sm_main_choose = SM_MN_MENU;
			break;
		}

		case SM_MN_MANAGE_ACCOUNT:
		{
			menu_manageAccount(turn);

			sm_main_choose = SM_MN_MENU;
			break;
		}

		case SM_MN_SHOW_RANKING:		// show ranking
		{
			//std::cout << account_Iterator->second->calculateAccountWorth();
			showRanking();

			sm_main_choose = SM_MN_MENU;
			break;
		}

		case SM_MN_NEXT_TOUR:
		{
			std::cout << "\n ---===### A month has passed ###===--- \n";
			const std::string filename = "market_data.csv";

			menu_updateAllDeposits(accountMap, turn);
			menu_saveToCSV(course_assets, filename);
			menu_updateAssetPrices(course_assets);

			++turn;
			sm_main_choose = SM_MN_MENU;
			break;
		}
		case SM_MN_PLOT_CHART:
		{
			// Python script name
			std::string pythonScript = "plotChart.py";

			// CSV file name
			std::string csvFile = "market_data.csv";

			menu_runPythonScript(pythonScript, csvFile);
			sm_main_choose = SM_MN_MENU;
			break;
		}

		case SM_MN_EXIT:
		{
			gameRunning = false;
			break;
		}

		default:
			std::cout << "\nInvalid value.\n";
			sm_main_choose = SM_MN_MENU;
			break;
		}
	}
	return 0;
}


