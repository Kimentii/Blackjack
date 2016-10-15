#include <vector>
#include "GenericPlayer.h"
GenericPlayer::GenericPlayer(const string& name) : m_Name(name) {}
GenericPlayer::~GenericPlayer() {}
bool GenericPlayer::IsBusted() const
{
	return (GetTotal() > 21);
}
void GenericPlayer::Bust() const
{
	cout << m_Name << " busts.\n";
}
ostream& operator << (ostream& os, const GenericPlayer& aGP)
{
	os << aGP.m_Name << ":\t";
	vector<Card*>::const_iterator pCard;
	if (!aGP.m_Cards.empty())
	{
		for(pCard = aGP.m_Cards.begin(); pCard != aGP.m_Cards.end(); ++pCard)
		{
			os << *(*pCard) << "\t";
		}
		if (aGP.GetTotal() != 0)
		{
			os << "(" << aGP.GetTotal() << ")";
		}
	}
	else
	{
		os << "empty";
	}
	return os;
}