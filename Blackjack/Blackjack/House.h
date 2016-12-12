//House.h
#include "GenericPlayer.h"
class House : public GenericPlayer
{
public:
	House(const char* name = "House");							//Конструктор
	virtual ~House();											//Деструктор
	virtual bool IsHitting() const;								//Показывает хочет ли игрок продолжать брать карты
	void FlipFirstCard();										//Переворачивает первую карту
private:
	int m_Points;												//Очки игрока
};