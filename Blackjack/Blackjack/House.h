//Диллер
#include "GenericPlayer.h"
class House : public GenericPlayer
{
public:
	House(const string& name = "House");
	virtual ~House();
	virtual bool IsHitting() const;								//Показывает хочет ли игрок продолжать брать карты
	void FlipFirstCard();										//Переворачивает первую карту
};