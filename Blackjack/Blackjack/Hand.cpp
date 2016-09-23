#include "Hand.h"
Hand::Hand()
{
	m_Cards.reserve(7);
}
Hand::~Hand()
{
	Clear();
}
void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}
void Hand::Clear()
{
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete *iter;
		*iter = nullptr;
	}
	m_Cards.clear();
}
int Hand::GetTotal() const
{
	if (m_Cards.empty())										//Если карт нет, то возвращает 0.
	{
		return 0;
	}
	if(m_Cards[0]->GetValue()==0)								//Если первая карта рубашой вверх, то возваращаем 0.
	{
		return 0;
	}
	int total = 0;												//Находит сумму всех карт (туз дает 1)
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total == (*iter)->GetValue();
	}
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)	//Определяем есть ли в руке туз
	{
		if ((*iter) -> GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}
	if (containsAce&&total <= 11)								//Если туз есть и сумма маленьакая, то туз дает 11.
	{
		total += 10;											//Добовляем 10 потому что туз уже дал 1 при подсчете суммы.
	}
	return total;												//Возвращаем сумму.
}