//Game.h
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include "Queue.h"
class Game
{
public:
	Game::Game(cQueue<Player>& names);				//�����������
	~Game();										//����������
	void Play();									//�������� ���� � Blackjack
private:
	Deck m_Deck;									//���� ������
	House m_House;									//���� ������
	vector<Player*> m_Players;						//������ �������
	void NewDeck();									//������� ����� ������
};