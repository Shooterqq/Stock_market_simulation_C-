#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <list>
#include <queue>
#include <cstdint>
#include <unordered_map>
#include <array>
#include <fstream>


using walletGoods = std::map<std::string, float>;
extern walletGoods course_assets;

class Instrument
{
public:
	virtual void updateStockPriece(void);
	virtual ~Instrument() = default;

private:
	std::map<std::string, int> amount_Of_Shares;

protected:

};











