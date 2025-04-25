#include "Dealer_deck.h"
#include "graphics.h"

void Dealer_deck::first_cards(Card d1, Card d2)
{
	dealer_deck.push_back(d1);
	dealer_deck.push_back(d2);
}

void Dealer_deck::showCards()
{
}

void Dealer_deck::getCard(Card d)
{
	dealer_deck.push_back(d);
}

int Dealer_deck::getNumberofCards()
{
	return dealer_deck.size();
}

int Dealer_deck::getValueofCards()
{
	int sum = 0;
	for (std::vector<Card>::iterator i = dealer_deck.begin(); i != dealer_deck.end(); i++)
	{
		sum += i->getValue();
	}
	return sum;
}

void Dealer_deck::draw()
{
	float s = 0.0f;

	for (std::vector<Card>::iterator i = dealer_deck.begin(); i != dealer_deck.end(); i++)
	{
		graphics::Brush br;
		br.texture = i->returnbr();
		br.outline_opacity = 0.0f;
		graphics::drawRect(CARD2_X + s, CARD2_Y, CARD1_WIDTH, CARD1_HEIGHT, br);
		s += 100.0f;
	}
}

void Dealer_deck::resetdeck()
{
	dealer_deck.clear();
}


Dealer_deck* Dealer_deck::getInstance()
{
	if (!m_instance)
		m_instance = new Dealer_deck();
	return m_instance;
}