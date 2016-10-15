#include "Deck.h"
#include "House.h"
#include "Player.h"
class Game
{
public:
	Game(const vector<string>& names);
	~Game();
	void Play();									//Проводит игру в Blackjack
private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};