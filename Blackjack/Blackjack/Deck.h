#include "Hand.h"
#include "GenericPlayer.h"
class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck();
	void Populate();									//Создает колоду из 52 карт
	void Shuffle();										//Тусует карты
	void Deal(Hand& aHand);								//Раздает одну карту в руку
	void AdditionalCards(GenericPlayer& aGP);			//Дает доплнительные карты инроку
};