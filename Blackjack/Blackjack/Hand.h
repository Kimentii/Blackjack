#ifndef _HAND_H_
#define _HAND_H_
#include "Card.h"
class Hand							//��������� ����
{
public:
	Hand();							
	virtual ~Hand();				
	void Add(Card* pCard);			//��������� ����� � ����.
	void Clear();					//������� ���� �� ����.
	int GetTotal() const;			//������� ����� ����� ���� � ����, ���������� ���� 1 ��� 11.
protected:
	vector <Card*> m_Cards;
};
#endif