//Player.h
#pragma once
#include "GenericPlayer.h"
class Player : public GenericPlayer
{
public:
	Player(const char* name = "", int p = 3000);
	virtual ~Player();
	virtual bool IsHitting() const;						//Показывает хочет ли игрок брать карты
	void Win();											//Показывает, что игрок победил
	void Lose();										//Плказывает, что игрок проиграл
	void Push();										//Объявляет ничью
	void ShowTable();									//Вывод таблицы
	const char* GetName();								//Возвращает имя
	bool operator == (const Player& aHum);				//Перегрузка ==
	bool operator != (const Player& aHum);				//Перегрузка !=
	bool operator > (const Player& aHum);				//Перегрузка >
	bool operator < (const Player& aHum);				//Перегрузка <
	friend ostream& operator << (ostream& os, const Player& aPlr);	//Перегрузка вывода
	friend istream& operator >> (istream& is, Player& aPlr);		//Перегрузка ввода
	friend fstream& operator >> (fstream& is, Player& aPlr);		//Перегрузка чтения из файла
	friend fstream& operator << (fstream& os, const Player& aPlr);	//Перегрузка записи в файл
private:
	int m_Points;										//Очки игрока
	int m_NumOfWin;										//Количество побед
	int m_NumOfLose;									//Количество ройгрышей
	int m_NumOfPush;									//Количествой партий в ничью
};