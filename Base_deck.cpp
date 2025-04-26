#include "Base_deck.h"

void Base_deck::first_cards(Card c1, Card c2)
{
    deck.push_back(c1);
    deck.push_back(c2);
}

void Base_deck::getCard(Card c)
{
    deck.push_back(c);
}

int Base_deck::getNumberofCards()
{
    return deck.size();
}

int Base_deck::getValueofCards()
{
    int sum = 0;
    for (auto& card : deck)
        sum += card.getValue();
    return sum;
}

void Base_deck::resetdeck()
{
    deck.clear();
}

void Dealer_deck::draw()
{
	float s = 0.0f;

	for (std::vector<Card>::iterator i = deck.begin(); i != deck.end(); i++)
	{
		graphics::Brush br;
		br.texture = i->returnbr();
		br.outline_opacity = 0.0f;
		graphics::drawRect(CARD2_X + s, CARD2_Y, CARD1_WIDTH, CARD1_HEIGHT, br);
		s += 100.0f;
	}
}

Dealer_deck* Dealer_deck::getInstance()
{
	if (!m_instance)
		m_instance = new Dealer_deck();
	return m_instance;
}

void Player_deck::draw()
{
	float s = 0.0f;

	for (std::vector<Card>::iterator i = deck.begin(); i != deck.end(); i++)
	{
		graphics::Brush br;
		br.texture = i->returnbr();
		br.outline_opacity = 0.0f;
		graphics::drawRect(CARD1_X + s, CARD1_Y, CARD1_WIDTH, CARD1_HEIGHT, br);
		s += 100.0f;
	}
}

Player_deck* Player_deck::getInstance()
{
	if (!m_instance)
		m_instance = new Player_deck();
	return m_instance;
}