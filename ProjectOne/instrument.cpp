#include "instrument.h"

class Instrument
{
public:
	virtual void updateStockPriece(void) = 0;
	virtual ~Instrument() = default;
private:
	std::map<std::string, int> amount_Of_Shares;
protected:

};