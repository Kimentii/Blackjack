//House.h
#include "GenericPlayer.h"
class House : public GenericPlayer
{
public:
	House(const char* name = "House");							//�����������
	virtual ~House();											//����������
	virtual bool IsHitting() const;								//���������� ����� �� ����� ���������� ����� �����
	void FlipFirstCard();										//�������������� ������ �����
private:
	int m_Points;												//���� ������
};