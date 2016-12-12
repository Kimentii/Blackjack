//Game.h
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include "Queue.h"
class Game
{
public:
	Game::Game(cQueue<Player>& names);				//Конструктор
	~Game();										//Деструктор
	void Play();									//Проводит игру в Blackjack
private:
	Deck m_Deck;									//Одна колода
	House m_House;									//Один диллер
	vector<Player*> m_Players;						//Вектор игроков
	void NewDeck();									//Создает новую колоду
};