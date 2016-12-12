//Game.cpp
#include "Game.h"
#include "Queue.h"
Game::Game(cQueue<Player>& names)
{
	cQueue<Player>::Iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName)
	{
		m_Players.push_back(&(*pName));						//��������� ������� � ����
	}
	srand(static_cast<unsigned int>(time(0)));				//����� ���� �������
}
Game::~Game() {}
void Game::Play()
{
	NewDeck();
	vector<Player*>::iterator pPlayer;
	for (int i = 0; i < 2; i++)								//������� ���� ������� �� 2 �����
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.Deal(*(*pPlayer));
		}
		m_Deck.Deal(m_House);								//������� ������ �����
	}
	m_House.FlipFirstCard();								//������ ������ ����� ������
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{														//������� �������
		cout << dynamic_cast<GenericPlayer&>(*(*pPlayer)) << endl;
	}
	cout << m_House << endl;								//������� ������
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.AdditionalCards(*(*pPlayer));				//���� ��� �������
	}
	m_House.FlipFirstCard();								//���������� ������ ����� ������
	cout << endl << m_House;
	if(!m_Deck.Empty()) m_Deck.AdditionalCardsHouse(m_House);//������� ������ �������������� �����
	if (m_House.IsBusted())									//���� � ������ �������
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{													//���, � ���� �� ������� ���������
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
		{													//��������� ����� ������ � �������
			if (!(*pPlayer)->IsBusted())						//���� � ������ ��� ��������
			{
				if ((*pPlayer)->GetTotal() > m_House.GetTotal())
				{											//� � ������ ������ ��� � ������
					(*pPlayer)->Win();							//�� �� �������
				}
				else if ((*pPlayer)->GetTotal() < m_House.GetTotal())
				{											//���� ������ � ������
					(*pPlayer)->Lose();						//�� ����� ��������
				}
				else
				{
					(*pPlayer)->Push();						//����� �����
				}
			}
		}
	}
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{														//������� ���� ���� �������
		(*pPlayer)->Clear();
	}
	m_House.Clear();										//������� ���� ������
}
void Game::NewDeck()										//������� ����� ������
{
	m_Deck.Populate();
	m_Deck.Shuffle();
}