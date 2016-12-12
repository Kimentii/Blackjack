//Hand.h
#include "Hand.h"
Hand::Hand()
{
	m_Cards.reserve(7);											//���������� ������� ������� �� 7 ����					
}
Hand::Hand(const Hand& aH)
{
	if (!aH.m_Cards.empty())
	{
		vector<Card>::const_iterator it = aH.m_Cards.begin();
		for (; it != aH.m_Cards.end(); it++)
		{
			m_Cards.push_back(*it);
		}
	}
}
Hand::~Hand()
{
	Clear();
}
void Hand::Add(Card& pCard)										//���������� �����
{
	m_Cards.push_back(pCard);
}
void Hand::Clear()												//�������� ���� �� ����
{
	if(!m_Cards.empty()) m_Cards.clear();
}
int Hand::GetTotal() const
{
	if (m_Cards.empty())										//���� ���� ���, �� ���������� 0.
	{
		return 0;
	}
	if(m_Cards[0].GetValue() == 0)								//���� ������ ����� ������� �����, �� ����������� 0.
	{
		return 0;
	}
	int total = 0;												//������� ����� ���� ���� (��� ���� 1)
	vector<Card>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += iter->GetValue();
	}
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)	//���������� ���� �� � ���� ���
	{
		if (iter->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}
	if (containsAce && total <= 11)								//���� ��� ���� � ����� ����������, �� ��� ���� 11.
	{
		total += 10;											//��������� 10 ������ ��� ��� ��� ��� 1 ��� �������� �����.
	}
	return total;												//���������� �����.
}
Hand& Hand::operator = (const Hand& aH)							//���������� ��������� =
{
	if (!aH.m_Cards.empty())
	{
		if(!m_Cards.empty()) m_Cards.clear();
		vector<Card>::const_iterator it = aH.m_Cards.begin();
		for (; it != aH.m_Cards.end(); it++)
		{
			m_Cards.push_back(*it);
		}
	}
	return *this;
}
fstream& operator << (fstream& os, const Hand& aH)				//������ � ����
{
	vector<Card>::const_iterator iter = aH.m_Cards.begin();
	for (; iter != aH.m_Cards.end(); ++iter)					//�������� �� ��� ������
	{
		os << (*iter) << ' ';									//���������� �����
	}
	return os;
}
fstream& operator >> (fstream& is, Hand& aH)					//������ �� �����
{
	aH.Clear();													//������� ����
	Card buf;
	while (1)													//����� ����� ���� ��� �� ��������
	{
		is >> buf;
		if (is.eof())
		{
			break;
		}
		aH.m_Cards.push_back(buf);
	}
	return is;
}