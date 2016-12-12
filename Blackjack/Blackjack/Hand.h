//Hand.h
#ifndef _HAND_H_
#define _HAND_H_
#include "Card.h"
class Hand							//��������� ����
{
public:
	Hand();							//����������
	Hand(const Hand& aH);			//����������� �����������
	virtual ~Hand();				//����������
	void Add(Card& pCard);			//��������� ����� � ����
	void Clear();					//������� ���� �� ����
	int GetTotal() const;			//������� ����� ����� ���� � ����, ���������� ���� 1 ��� 11
	Hand& operator = (const Hand& aH);	//���������� =
	friend fstream& operator << (fstream& os, const Hand& aH);	//���������� ������ � ����
	friend fstream& operator >> (fstream& is, Hand& aH);		//���������� ������ �� �����
protected:
	vector<Card> m_Cards;			//������ ����
};
#endif