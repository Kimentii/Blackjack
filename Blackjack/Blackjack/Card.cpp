//Gard.cpp
#include "Card.h"
Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}
int Card::GetValue() const
{
	int value = 0;								 //���� ����� ���������� ����� ����, �� ������� ����� 0.
	if (m_IsFaceUp)
	{
		value = m_Rank;							 //�������� - ��� �����, ��������� �� �����
		if (value > 10)							 //�������� ����� 10 ��� �������� ����
		{
			value = 10;
		}
	}
	return value;
}
void Card::Flip()								 //������������� �����
{
	m_IsFaceUp = !(m_IsFaceUp);
}
ostream& operator << (ostream& os, const Card& aCard)
{
	const string RANKS[] = { "0","A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	const string SUITS[] = { "c","d","h","s" };
	if (aCard.m_IsFaceUp)						//���� ����� ����� �����,
	{
		os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];	//�� ����� � ����� � �����
	}
	else
	{
		os << "XX";								//����� ������� ������� �����
	}
	return os;
}
fstream& operator << (fstream& os, const Card& aCard)
{												//���������� ������ � ����
	os << static_cast<int>(aCard.m_Rank) << ' ' << static_cast<int>(aCard.m_Suit);
	return os;
}
fstream& operator >> (fstream& is, Card& aCard)
{												//���������� ������ �� �����
	is >> reinterpret_cast<int&>(aCard.m_Rank) >> reinterpret_cast<int&>(aCard.m_Suit);
	return is;
}