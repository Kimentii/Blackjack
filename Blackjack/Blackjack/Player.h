#include "GenericPlayer.h"
class Player : public GenericPlayer
{
public:
	Player(const string& name = "");
	virtual ~Player();
	virtual bool IsHitting() const;						//Показывает хочет ли игрок брать карты
	void Win() const;									//Показывает, что игрок победил
	void Lose() const;									//Плказывает, что игрок проиграл
	void Push() const;									//Объявляет ничью
};