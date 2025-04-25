#include "Deck.h"
#include "Card.h"
#include <iostream> // std
#include <vector> // vector
#include <algorithm> // random shuffle
#include <random>

Deck::Deck()
{
}

Deck::~Deck()
{
}

void Deck::fill_deck()
{

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			deck.push_back(new Card(i, j));
		}
	}
}

void Deck::randomise_cards()
{
	std::shuffle(deck.begin(), deck.end(), std::random_device());
}

Card Deck::giveCard()
{
	for (int i = 0; i <= deck.size() - 1; i++)
	{
		if (!deck[i]->getGiven())
		{
			deck[i]->cardGiven();
			return (*deck[i]);
		}
	}
}

void Deck::resetdeck()
{
	deck.clear();
}

Deck* Deck::getInstance()
{
	if (!m_instance)
		m_instance = new Deck();
	return m_instance;
}