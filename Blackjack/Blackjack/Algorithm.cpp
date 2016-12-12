//Algorithm.cpp
#include "Queue.h"
#include "Algorithm.h"
#include <random>
template <class it>
void Sort(it first, it last)
{												//��������� �������� �� first �� last(�� ������� last)
	it temp;
	for (it i = first; i != last; i++)			//���� �� ������ �� �����
	{
		temp = i;								//���������� ������� �������
		for (it j = i; j != last; j++)			//���� ������� �������
		{
			if (*temp > *j)
			{
				temp = j;
			}
		}
		if (i != temp)							//������ ���������� ������� � �������
		{
			auto c = *i;
			*i = *temp;
			*temp = c;
		}
	}
}
template <class it>
void Random_Shuffle(it first, it last)
{												//������������ �������� �� first �� last(�� ������� last)
	int i = 0, j = 1;
	it curr;
	for (it temp = first; temp != last; temp++, j++)
	{											//���� �� ������ �� �����
		i = rand() % j;							//����� ��������� ����� ��������
		curr = first;
		while (i-- > 0) curr++;					//���� ���� ��������� �������
		if (curr != temp)						//�������� ������� ������� � ������� � ��������� �������
		{
			auto c = *curr;
			*curr = *temp;
			*temp = c;
		}
	}
}