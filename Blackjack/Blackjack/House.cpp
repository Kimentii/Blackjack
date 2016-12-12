//House.cpp
#include "House.h"
House::House(const char* name): GenericPlayer(name) {}
House::~House() {}
bool House::IsHitting() const
{
	return (GetTotal() <= 16);				//���� ����� ����� ���� ������ ��� ����� 16, �� true
}
void House::FlipFirstCard()					//�������������� ������ �����
{
	if (!(m_Cards.empty()))					//���� ����� ����
	{
		m_Cards[0].Flip();
	}
	else
	{
		cout << "No card to flip!\n";
	}
}