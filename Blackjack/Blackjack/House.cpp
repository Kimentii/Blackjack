//House.cpp
#include "House.h"
House::House(const char* name): GenericPlayer(name) {}
House::~House() {}
bool House::IsHitting() const
{
	return (GetTotal() <= 16);				//Если сумма очков карт меньше или равно 16, то true
}
void House::FlipFirstCard()					//Переворачивает первую карту
{
	if (!(m_Cards.empty()))					//Если карта есть
	{
		m_Cards[0].Flip();
	}
	else
	{
		cout << "No card to flip!\n";
	}
}