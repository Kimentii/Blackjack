//GenericPlayer.cpp
#include <vector>
#include "GenericPlayer.h"
GenericPlayer::GenericPlayer(const char* name)
{
	strcpy(m_Name, name);
}
GenericPlayer::~GenericPlayer() {}
bool GenericPlayer::IsBusted() const							//Показывает есть ли перебор
{
	return (GetTotal() > 21);
}
void GenericPlayer::Bust() const								//Выводит надпись о том, что у игрока перебор
{
	cout << m_Name << " busts.\n";
}
ostream& operator << (ostream& os, const GenericPlayer& aGP)
{
	os << aGP.m_Name << ":\t";									//Выводит имя игрока
	vector<Card>::const_iterator pCard;
	if (!aGP.m_Cards.empty())									//Выводит карты, если они есть
	{
		for(pCard = aGP.m_Cards.begin(); pCard != aGP.m_Cards.end(); ++pCard)
		{
			os << *pCard << "\t";
		}
		if (aGP.GetTotal() != 0)
		{
			os << "(" << aGP.GetTotal() << ")";
		}
	}
	else
	{
		os << "empty";											//Иначе вывыодит что очередь пуста
	}
	return os;
}