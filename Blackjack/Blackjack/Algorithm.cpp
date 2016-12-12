//Algorithm.cpp
#include "Queue.h"
#include "Algorithm.h"
#include <random>
template <class it>
void Sort(it first, it last)
{												//Сортирует элементы от first до last(не включая last)
	it temp;
	for (it i = first; i != last; i++)			//Цикд от начала до конца
	{
		temp = i;								//Запоминает текущий элемент
		for (it j = i; j != last; j++)			//Ищет меньший элемент
		{
			if (*temp > *j)
			{
				temp = j;
			}
		}
		if (i != temp)							//Меняет наименьший элемент и текущий
		{
			auto c = *i;
			*i = *temp;
			*temp = c;
		}
	}
}
template <class it>
void Random_Shuffle(it first, it last)
{												//Перемешивает элементы от first до last(не включая last)
	int i = 0, j = 1;
	it curr;
	for (it temp = first; temp != last; temp++, j++)
	{											//Цикл от начала до конца
		i = rand() % j;							//Берет рандомный номер элемента
		curr = first;
		while (i-- > 0) curr++;					//Ищет этот рандомный элемент
		if (curr != temp)						//Заменяет текущий элемент и элемнет с рандомным номером
		{
			auto c = *curr;
			*curr = *temp;
			*temp = c;
		}
	}
}