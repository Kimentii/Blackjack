//Card.h
#ifndef _CARD_H_
#define _CARD_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;
class Card																	//Отдельная игровая карта
{
public:
	enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	//Перечесление всех карт
	enum suit {CLUBS,DIAMONDS,HEARTS,SPADES};								//Масти карт
	friend ostream& operator << (ostream& os, const Card& aCard);			//Перегрузка оператора <<
	friend fstream& operator << (fstream& os, const Card& aCard);			//Перегрузка записи в файл
	friend fstream& operator >> (fstream& is, Card& aCard);					//Перегрузка чтения из файла
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);					//Конструктор с параметрами
																			//по умолчанию
	int GetValue() const;													//Вовращает значение карты
	void Flip();															//Переворачивает карту
private:
	rank m_Rank;															//Ранг карты
	suit m_Suit;															//Масть карты
	bool m_IsFaceUp;														//Состояние карты
};
#endif