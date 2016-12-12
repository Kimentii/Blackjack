//Hand.h
#ifndef _HAND_H_
#define _HAND_H_
#include "Card.h"
class Hand							//Коллекция карт
{
public:
	Hand();							//Констуктор
	Hand(const Hand& aH);			//Конструктор копирования
	virtual ~Hand();				//Деструктор
	void Add(Card& pCard);			//Добовляет карту в руку
	void Clear();					//Очищает руку от карт
	int GetTotal() const;			//Очищает сумму очков карт в руке, присваивая тузу 1 или 11
	Hand& operator = (const Hand& aH);	//Перегрузка =
	friend fstream& operator << (fstream& os, const Hand& aH);	//Перегрузка записи в файл
	friend fstream& operator >> (fstream& is, Hand& aH);		//Перегрузка чтения из файла
protected:
	vector<Card> m_Cards;			//Вектор карт
};
#endif