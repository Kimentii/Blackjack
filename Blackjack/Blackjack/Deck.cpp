//Deck.h
#include "Deck.h"
#include "TextFile.cpp"
Deck::Deck(int n) : m_NumberOfCards(n)
{
	m_Cards.reserve(m_NumberOfCards);
	Populate();
}
Deck::~Deck() {}
void Deck::Populate()
{
	Clear();
	if (m_NumberOfCards == 52)
	{
		for (int s = Card::CLUBS; s <= Card::SPADES; ++s)		//������� � ������ ����� ���� ������ � �����
		{
			for (int r = Card::ACE; r <= Card::KING; ++r)
			{
				Add(Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
			}
		}
	}
	else
	{
		for (int s = Card::CLUBS; s <= Card::SPADES; ++s)		//������� � ������ ����� �� 6 �� ������
		{
			for (int r = Card::SIX; r <= Card::KING; ++r)
			{
				Add(Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
			}
		}
		for (int s = Card::CLUBS; s <= Card::SPADES; ++s)		//���������� ����� ���� ������ � ������
		{
			Add(Card(Card::ACE, static_cast<Card::suit>(s)));
		}
	}
}
void Deck::Shuffle()										//������������ ������
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}
void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty())									//���� � ������ ���� �����, ��
	{
		aHand.Add(m_Cards.back());							//��������� � ���� �����
		m_Cards.pop_back();									//������� � �� ������
	}
	else
	{
		cout << "Out of cards. Unable to deal.";
	}
}
void Deck::AdditionalCards(GenericPlayer& aGP)
{
	TextFile<Hand> file;
	char c;
	file.open_trunc(STEP);
	cout << endl;
	while (!(aGP.IsBusted()) && aGP.IsHitting() && !Empty())
	{
		//������� ����� ������, ���� � ���� �� ������� ��� ���� �� ����� ����� ��� ����
		file << aGP;
		Deal(aGP);
		cout << aGP << endl;
		cout << "Do you want to take a step back?(y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			file >> aGP;
			file.refresh();
			cout << aGP << endl;
		}
		else
		{
			file.clear_file();
		}
		if (aGP.IsBusted())									//���� �������, ��
		{
			aGP.Bust();										//��������� ������� � ������
		}
	}
}
void Deck::AdditionalCardsHouse(GenericPlayer& aGP)
{
	cout << endl;
	while (!(aGP.IsBusted()) && aGP.IsHitting() && !Empty())
	{
		//������� ����� ������, ���� � ���� �� ������� ��� ���� �� ����� ����� ��� ����
		Deal(aGP);
		cout << aGP << endl;
		if (aGP.IsBusted())									//���� �������, ��
		{
			aGP.Bust();										//��������� ������� � ������
		}
	}
}
bool Deck::Empty()											//���������� true, ���� ������ �����
{
	return m_Cards.empty();
}