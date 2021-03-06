//Card.h
#ifndef _CARD_H_
#define _CARD_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;
class Card																	//��������� ������� �����
{
public:
	enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	//������������ ���� ����
	enum suit {CLUBS,DIAMONDS,HEARTS,SPADES};								//����� ����
	friend ostream& operator << (ostream& os, const Card& aCard);			//���������� ��������� <<
	friend fstream& operator << (fstream& os, const Card& aCard);			//���������� ������ � ����
	friend fstream& operator >> (fstream& is, Card& aCard);					//���������� ������ �� �����
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);					//����������� � �����������
																			//�� ���������
	int GetValue() const;													//��������� �������� �����
	void Flip();															//�������������� �����
private:
	rank m_Rank;															//���� �����
	suit m_Suit;															//����� �����
	bool m_IsFaceUp;														//��������� �����
};
#endif