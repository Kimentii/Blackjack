//GenericPlayer.h
#ifndef _GENERICPLAYER_H_
#define _GENERICPLAYER_H_
#include "Hand.h"
#pragma warning(disable:4996)
const int SIZE = 80;
class GenericPlayer : public Hand											//Абстактный класс
{
public:
	friend ostream& operator << (ostream& os, const GenericPlayer& aGP);	//Перегрузка оператора вывода на экран
	GenericPlayer(const char* name = "");									//Конструктор
	virtual ~GenericPlayer();												//Деструктор
	virtual bool IsHitting() const = 0;										//Показывает хочет ли игрок продолжать брать карты
	bool IsBusted() const;													//Показывает есть ли у игрока перебор
	void Bust() const;														//Объявляет что игрока перебор
protected:
	char m_Name[SIZE];														//Имя
};
#endif