#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
class Card
{
public:
	enum rank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SVEN, EIGHT, NINE,TEN,JACK, QUEEN, KING};
	enum suit{CLUBS,DIAMONDS,HEARTS,SPADES};
	friend ostream& operator<< (ostream& os, const Card& aCard);
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	int GetValue() const;
	void Flip();
private:
	suit m_Suit;
	bool m_IsFaceUp;
};