//Hand.h
#include "Hand.h"
Hand::Hand()
{
	m_Cards.reserve(7);											//Увеличение емкости вектора до 7 карт					
}
Hand::Hand(const Hand& aH)
{
	if (!aH.m_Cards.empty())
	{
		vector<Card>::const_iterator it = aH.m_Cards.begin();
		for (; it != aH.m_Cards.end(); it++)
		{
			m_Cards.push_back(*it);
		}
	}
}
Hand::~Hand()
{
	Clear();
}
void Hand::Add(Card& pCard)										//Добавление карты
{
	m_Cards.push_back(pCard);
}
void Hand::Clear()												//Очищение руки от карт
{
	if(!m_Cards.empty()) m_Cards.clear();
}
int Hand::GetTotal() const
{
	if (m_Cards.empty())										//Если карт нет, то возвращает 0.
	{
		return 0;
	}
	if(m_Cards[0].GetValue() == 0)								//Если первая карта рубашой вверх, то возваращаем 0.
	{
		return 0;
	}
	int total = 0;												//Находит сумму всех карт (туз дает 1)
	vector<Card>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += iter->GetValue();
	}
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)	//Определяем есть ли в руке туз
	{
		if (iter->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}
	if (containsAce && total <= 11)								//Если туз есть и сумма маленьакая, то туз дает 11.
	{
		total += 10;											//Добовляем 10 потому что туз уже дал 1 при подсчете суммы.
	}
	return total;												//Возвращаем сумму.
}
Hand& Hand::operator = (const Hand& aH)							//Перегрукза оператора =
{
	if (!aH.m_Cards.empty())
	{
		if(!m_Cards.empty()) m_Cards.clear();
		vector<Card>::const_iterator it = aH.m_Cards.begin();
		for (; it != aH.m_Cards.end(); it++)
		{
			m_Cards.push_back(*it);
		}
	}
	return *this;
}
fstream& operator << (fstream& os, const Hand& aH)				//Запись в файл
{
	vector<Card>::const_iterator iter = aH.m_Cards.begin();
	for (; iter != aH.m_Cards.end(); ++iter)					//Проходит по все картам
	{
		os << (*iter) << ' ';									//Записывает карту
	}
	return os;
}
fstream& operator >> (fstream& is, Hand& aH)					//Чтение из файла
{
	aH.Clear();													//Очищает руку
	Card buf;
	while (1)													//Чтает карты пока они не кончатся
	{
		is >> buf;
		if (is.eof())
		{
			break;
		}
		aH.m_Cards.push_back(buf);
	}
	return is;
}