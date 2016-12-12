//Queue.cpp
#pragma once
#include "Queue.h"
template <class T>
cQueue<T>::cQueue()													//Конструктор по умолчанию
{
	//cout << "cQueue constructor: " << typeid(T).name() << endl;		//Выводит тип хранения данных в очереди
	head = nullptr;
	tail = nullptr;
}
template <class T>
cQueue<T>::cQueue(int size, T d)									//Конструктор с двумя параметрами
{
	//cout << "cQueue constructor: " << typeid(T).name() << endl;		//Выводит тип хранения данных в очереди
	for (int i = 0; i < size; i++)									//Создает нужное количество элемнетов
	{																//и инициализирует их
		PushBack(d);
	}
}
template <class T>
cQueue<T>::cQueue(int size)											//Констуктор с парметром размера очереди
{
	//cout << "cQueue constructor: " << typeid(T).name() << endl;		//Выводит тип хранения данных в очереди
	if (size > 0)
	{
		head = new cQueueUnit<T>;									//Инициализация начала очереди
		tail = head;
		for (int i = 0; i < (size - 1); i++)						//Добавление элементов в хвост
		{
			tail->next = new cQueueUnit<T>(nullptr, tail);
			tail = tail->next;
		}
	}
}
template <class T>
cQueue<T>::cQueue(const cQueue<T>& cQ)									//Конструктор копирования
{
	if (cQ.head)
	{
		cQueueUnit<T>* temp = cQ.head->next;
		head = new cQueueUnit<T>(cQ.head->data);
		tail = head;
		while(temp)														//Добавление элементов в хвост
		{
			tail->next = new cQueueUnit<T>(temp->data, nullptr, tail);	//Добавление элемента
			tail = tail->next;
			temp = temp->next;
		}
	}
	else
	{
		head = tail = nullptr;
	}
}
template <class T>
cQueue<T>::~cQueue()												//Деструктор
{
	int i = 0;
	while (head)
	{
		cout << "delete element with number: " << ++i << endl;		//Выводит количесвто удаленных элементов
		cQueueUnit<T>* temp = head;
		head = head->next;
		delete temp;
	}
}
template <class T>
void cQueue<T>::show()												//Вывод очереди
{
	cQueueUnit* temp = head;
	while (temp)													//Пока не конец очереди
	{
		cout << temp->data << endl;									//Вывод данных из нее
		temp = temp->next;
	}
}
template <class T>
void cQueue<T>::clear()												//Очищение очереди
{
	while (head)
	{
		PopBack();													//Удаляет элементы из конца очереди пока
	}																//очередь не кончится
}
template <class T>
bool cQueue<T>::empty()												//Проверка наличия элементов
{
	if (head)
	{
		return false;
	}
	else
	{
		return true;
	}
}
template <class T>
int cQueue<T>::size()												//Возвращает размер очереди
{
	cQueueUnit<T>* temp = head;
	int i = 0;
	while (temp)													//Проходит до конца очереди и считает все элементы
	{
		i++;
		temp = temp->next;
	}
	return i;
}
template <class T>
void cQueue<T>::PushBack(const T& u)								//Добавление элемента в конец очереди
{
	if (tail)														//Если очередь уже содержит элементы
	{
		tail->next = new cQueueUnit<T>(u, nullptr, tail);			//То добовляем еще один
		tail = tail->next;
	}
	else
	{
		head = new cQueueUnit<T>(u);								//Иначе инициализируем очередь
		tail = head;
	}
}
template <class T>
void cQueue<T>::PushFront(const T& u)								//Добавление элемента в начало очереди
{
	if (head)														//Если очередь есть
	{
		head->prev = new cQueueUnit<T>(u, head, nullptr);			//Добовляем элемент в начало
		head = head->prev;
	}
	else
	{
		head = new cQueueUnit<T>(u);								//Иначе создаем первый элемент очереди
		tail = head;
	}
}
template <class T>
T cQueue<T>::PopFront()												//Удаление элемента из начала очереди
{
	if (head)														//Если очередь содержит элементы
	{
		T buf = head->data;											//Переписываем данные из элемента
		cQueueUnit<T>* temp = head;
		head = head->next;											//Переносим начало очереди
		if (head) head->prev = nullptr;
		else tail = nullptr;
		delete temp;												//Удаляем элемент
		return buf;
	}
	else
	{
		throw QueueExp();
	}
}
template <class T>
T cQueue<T>::PopBack()												//Удаление элемента из конца очереди
{
	if (tail)														//Если очередь содержит элементы
	{
		T buf = tail->data;											//Сохраненые данных из элемента
		cQueueUnit<T>* temp = tail;
		tail = tail->prev;											//Перенос конца очереди
		if (tail) tail->next = nullptr;
		else head = nullptr;
		delete temp;												//Удаление элемента
		return buf;
	}
	else
	{
		throw QueueExp();
	}
}
template <class T>
cQueue<T>& cQueue<T>::operator = (cQueue<T>& cQ)					//Перегрузка оператора =
{
	clear();
	cQueue<T>::Iterator iter = cQ.begin();
	while (iter != cQ.end())										//Цикл по всей очереди
	{
		PushBack(*iter);											//Добавление элементов в новуню очердеь
		iter++;
	}
	return *this;
}