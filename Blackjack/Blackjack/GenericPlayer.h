//GenericPlayer.h
#ifndef _GENERICPLAYER_H_
#define _GENERICPLAYER_H_
#include "Hand.h"
#pragma warning(disable:4996)
const int SIZE = 80;
class GenericPlayer : public Hand											//���������� �����
{
public:
	friend ostream& operator << (ostream& os, const GenericPlayer& aGP);	//���������� ��������� ������ �� �����
	GenericPlayer(const char* name = "");									//�����������
	virtual ~GenericPlayer();												//����������
	virtual bool IsHitting() const = 0;										//���������� ����� �� ����� ���������� ����� �����
	bool IsBusted() const;													//���������� ���� �� � ������ �������
	void Bust() const;														//��������� ��� ������ �������
protected:
	char m_Name[SIZE];														//���
};
#endif