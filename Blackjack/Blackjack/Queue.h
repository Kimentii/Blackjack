//Queue.h
#pragma once
#include "Exception.h"
#include <iostream>
using namespace std;
template <class T>
class cQueueUnit														//Элемент очереди
{
public:
	T data;																//Данные
	cQueueUnit(cQueueUnit* nt = nullptr, cQueueUnit* pr = nullptr) : next(nt), prev(pr) { }	//Конструктор по умолчанию с 2 параметрами
	cQueueUnit(const T& u, cQueueUnit* nt = nullptr, cQueueUnit* pr = nullptr) : next(nt), prev(pr), data(u) {}	//Конструктор с параметрами
	cQueueUnit<T>* next;												//Указатель на следующий элемент
	cQueueUnit<T>* prev;												//Указатель на предыдущий элемент
};
template <class T>
class cQueue
{
	cQueueUnit<T> *head, *tail;											//Начало и конечц очереди
public:
	class Iterator;
	friend class Iterator;
	class Iterator														//Класс итератор
	{
		cQueueUnit<T>* ptr;
	public:
		//Указатель на элемент очереди
		Iterator(cQueueUnit<T>* tmp = nullptr) : ptr(tmp) { }			//Конструктор с одним параметром
		Iterator operator ++ (int)										//Перемещение на сделующий элемент
		{
			if (ptr)													//Если указатель не пуст
			{
				ptr = ptr->next;										//Перемещаем указатель
				return Iterator(ptr);
			}
			else
			{
				return Iterator(ptr);									//Иначе возвращаем нулевой итератор
			}
		}
		Iterator operator -- (int)										//Перемещение на предыдущий элемент
		{
			if (ptr)
			{
				ptr = ptr->prev;
				return Iterator(ptr);
			}
			else
			{
				return Iterator(ptr);
			}
		}
		Iterator operator ++ () { return (*this)++; };					//Перемещение на следующий элемент
		Iterator operator -- () { return (*this)--; };					//Перемещение на пердыдущий элемент
		T& operator * ()												//Перегрузка оператора *
		{
			if (ptr) return ptr->data;									//Возвращение ссылки на данные
			else throw wrong_element();
		}
		T& operator -> ()												//Перегрузка оператора ->
		{
			if (ptr) return ptr->data;									//Возвращение ссылки на данные
			else throw wrong_element();
		}
		bool operator == (const Iterator& i)							//Перегрузка оператора ==
		{
			if (ptr == i.ptr)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator != (const Iterator& i)							//Перегрузка оператора !=
		{
			if (ptr == i.ptr)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	};
	cQueue();															//Конструктор по умолчанию
	cQueue(int size);													//Конструктор с параметром размера очереди
	cQueue(int size, const T d);										//Конструктор с двумя параметрами
	cQueue(const cQueue& cQ);
	~cQueue();															//Деструктор
	Iterator begin() { return Iterator(head); }							//Возвращает итератор на начало очереди
	Iterator end() { return Iterator(nullptr); }						//Возвращает итератор на конец очереди
	Iterator rbegin() { return Iterator(tail); }
	Iterator rend() { return Iterator(nullptr); }
	Iterator find(const T& inf)											//Поиск элемента очереди
	{
		Iterator it = begin();
		while (it.ptr)
		{
			if (*it == inf)
			{
				return it;
			}
			it++;
		}
		return Iterator(nullptr);
	}
	void show();														//Функция вывода очереди
	void clear();														//Функция очистки очереди
	void del_element(Iterator& it)										//Удаление элемента из очереди
	{
		if (it == Iterator(nullptr)) throw wrong_element();				//Елси элемента нет, то ошибка
		if (it == begin())												//Если начало очереди
		{
			it++;
			PopFront();
		}
		else if (it == rbegin())										//Если конец очереди
		{
			it++;
			PopBack();
		}
		else															//Случай середины очереди
		{
			cQueueUnit<T>* temp = it.ptr;								//Зпоминаем элемент
			temp->prev->next = temp->next;								//Переводим указатели
			temp->next->prev = temp->prev;
			it++;
			delete temp;												//Удаляем сам элемент

		}
	}
	void PushBack(const T& u);											//Добавление элемнета в конец очереди
	void PushFront(const T& u);											//Добавление элемента в начало очереди
	bool empty();														//Проверка пусткая ли очередь
	int size();															//Возвращение размера очереди
	T PopFront();														//Удаление элемента из начала очереди
	T PopBack();														//Удаление элемента из конца очереди
	T& operator [] (int i)												//Перегрузка оператора []
	{
		if (i < size() && i >= 0)
		{
			cQueue::Iterator it = begin();								//Создание итератора на начало
			while (--i > 0)												//Поиск нужного элемента
			{
				it++;
			}
			return *it;
		}
		else
		{
			throw wrong_element();
		}
	}
	cQueue& operator = (cQueue& cQ);
	friend ostream& operator << (ostream& os, cQueue& q)				//Перегрузка вывода
	{
		cQueueUnit<T>* temp = q.head;
		while (temp)
		{
			os << temp->data << endl;									//Почленный вывод элементов
			temp = temp->next;
		}
		if (q.empty())													//Если очередь пуста
		{
			os << "Queue is empty" << endl;								//Выводим это
		}
		return os;
	}
	friend istream& operator >> (istream& is, cQueue& q)				//Перегрузка ввода
	{
		cQueue::Iterator it = q.begin();
		for (; it != q.end();)
		{
			try
			{
				is >> *it;
				if (is.fail() || is.eof())								//Если в потоке ввода ошибка
				{
					throw InputExp();									//то вызов исключения
				}
				it++;
			}
			catch (InputExp& exp)										//Обработка исключения
			{
				bool e = is.eof();
				is.clear();
				if (!e) while (is.get() != '\n');						//Удаление лишних символов
				while (is.get() != '\n');
				cout << "Error:" << exp.error() << endl;
				cout << exp.what() << endl;
			}
		}
		return is;
	}
	friend fstream& operator << (fstream& os, const cQueue& q)			//Перегрузка записи в файл
	{
		cQueueUnit<T>* temp = q.head;
		while (temp)
		{
			os << temp->data << ' ';									//Почленная запись элементов
			temp = temp->next;
		}
		return os;
	}
	friend fstream& operator >> (fstream& is, cQueue& q)				//Перегрузка чтения из файла
	{
		T buf;															//Буферный элемент
		while (1)
		{
			is >> buf;													//Чтение элемента
			if (is.eof() || is.fail())									//Если конец или ошибка
			{
				break;													//Выходим из цикла
			}
			q.PushBack(buf);											//Добавление элемента в очередь
		}
		return is;
	}
};