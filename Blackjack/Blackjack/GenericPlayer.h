#ifndef _GENERICPLAYER_H_
#define _GENERICPLAYER_H_
#include "Hand.h"
class GenericPlayer : public Hand
{
	friend ostream& operator << (ostream& os, const GenericPlayer& aGP);
public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();
	virtual bool IsHitting() const = 0;										//���������� ����� �� ����� ���������� ����� �����
	bool IsBusted() const;													//���������� ���� �� � ������ �������
	void Bust() const;														//��������� ��� ������ �������
protected:
	string m_Name;
};
#endif