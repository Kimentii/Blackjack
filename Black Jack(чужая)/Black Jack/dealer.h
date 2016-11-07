#include "random.h"

class Dealer
{
private:
	int mTotal;
	int mInsurance;
public:
	Dealer();
	int deal(int);
	int game(int);
	int getTotal();
	void setTotal(int);
	void setInsurance(int);
	int getInsurance();
};