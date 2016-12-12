//Deck.h
#include "Hand.h"
#include "GenericPlayer.h"
const char STEP[] = "D:/��������/3 ���/��������/Blackjack/Blackjack/Blackjack/Step/Step.txt";
class Deck : public Hand
{
public:
	Deck(int n = 52);									//�����������
	virtual ~Deck();									//����������
	void Populate();									//������� ������ �� 52 ����
	void Shuffle();										//������ �����
	void Deal(Hand& aHand);								//������� ���� ����� � ����
	void AdditionalCards(GenericPlayer& aGP);			//���� ������������� ����� ������
	void AdditionalCardsHouse(GenericPlayer& aGP);		//���� ������������� ����� ������
	bool Empty();										//���������� ���� �� ����� � ������
private:
	int m_NumberOfCards;								//���������� ����
};