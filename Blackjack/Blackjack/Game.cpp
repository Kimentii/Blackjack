//Game.cpp
#include "Game.h"
#include "Queue.h"
Game::Game(cQueue<Player>& names)
{
	cQueue<Player>::Iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName)
	{
		m_Players.push_back(&(*pName));						//Добовляет игроков в игру
	}
	srand(static_cast<unsigned int>(time(0)));				//Садит семя рандома
}
Game::~Game() {}
void Game::Play()
{
	NewDeck();
	vector<Player*>::iterator pPlayer;
	for (int i = 0; i < 2; i++)								//Раздает всем игрокам по 2 карты
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.Deal(*(*pPlayer));
		}
		m_Deck.Deal(m_House);								//Раздает дилеру карты
	}
	m_House.FlipFirstCard();								//Прячит первую карту дилера
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{														//Выводит игроков
		cout << dynamic_cast<GenericPlayer&>(*(*pPlayer)) << endl;
	}
	cout << m_House << endl;								//Выводит дилера
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.AdditionalCards(*(*pPlayer));				//Дает ход игрокам
	}
	m_House.FlipFirstCard();								//Показывает первую карту дилера
	cout << endl << m_House;
	if(!m_Deck.Empty()) m_Deck.AdditionalCardsHouse(m_House);//Раздает дилеру дополнительные карты
	if (m_House.IsBusted())									//Если у дилера перебор
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{													//Все, у кого не перебор побеждают
			if (!((*pPlayer)->IsBusted()))
			{
				(*pPlayer)->Win();
			}
			else
			{
				(*pPlayer)->Push();
			}
		}
	}
	else
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{													//Сравнение очков дилера и игроков
			if (!(*pPlayer)->IsBusted())						//Если у игрока нет перебора
			{
				if ((*pPlayer)->GetTotal() > m_House.GetTotal())
				{											//И у игрока больше чем у дилера
					(*pPlayer)->Win();							//То он выиграл
				}
				else if ((*pPlayer)->GetTotal() < m_House.GetTotal())
				{											//Если больше у дилера
					(*pPlayer)->Lose();						//То игрок проиграл
				}
				else
				{
					(*pPlayer)->Push();						//Иначе ничья
				}
			}
		}
	}
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{														//Очищает руки всех игроков
		(*pPlayer)->Clear();
	}
	m_House.Clear();										//Очищает руки дилера
}
void Game::NewDeck()										//Создает новую колоду
{
	m_Deck.Populate();
	m_Deck.Shuffle();
}