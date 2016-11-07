#include "random.h"
#include <string>
#include <iostream>
using namespace std;

class Player
{
private:	
	int mTotal;
	float mMoney;
	float mWager;
	std::string mName;
	static int wins;
	static int nrGames;
	static int nrPush;	
	int mRetract;
public:
	Player();
	void begin();
	int deal(int);
	int game(int);
	float getMoney();
	void setMoney(float);
	int getWager();
	void setWager(float);
	int getTotal();
	void setTotal(int);	
	void viewStats();
	void rest();
	static int gamesWin(int);
	static int numberGames(int);
	static int numberPush(int);
	int gamesWin();
	int numberGames();
	int numberPush();
	int getRetract();
	void setRetract(int);
};