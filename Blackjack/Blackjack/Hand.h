#include "Card.h"
class Hand							//Коллекция карт
{
public:
	Hand();							
	virtual ~Hand();				
	void Add(Card* pCard);			//Добовляет карту в руку.
	void Clear();					//Очищает руку от карт.
	int GetTotal() const;			//Очищает сумму очков карт в руке, присваивая тузу 1 или 11.
protected:
	vector <Card*> m_Cards;
};