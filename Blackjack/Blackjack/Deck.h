//Deck.h
#include "Hand.h"
#include "GenericPlayer.h"
const char STEP[] = "D:/Предметы/3 сем/Курсовая/Blackjack/Blackjack/Blackjack/Step/Step.txt";
class Deck : public Hand
{
public:
	Deck(int n = 52);									//Конструктор
	virtual ~Deck();									//Деструктор
	void Populate();									//Создает колоду из 52 карт
	void Shuffle();										//Тусует карты
	void Deal(Hand& aHand);								//Раздает одну карту в руку
	void AdditionalCards(GenericPlayer& aGP);			//Дает доплнительные карты игроку
	void AdditionalCardsHouse(GenericPlayer& aGP);		//Дает доплнительные карты дилеру
	bool Empty();										//Показывает есть ли карта в колоде
private:
	int m_NumberOfCards;								//Количество карт
};