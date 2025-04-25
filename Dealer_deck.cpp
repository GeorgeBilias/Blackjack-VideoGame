#include "Dealer_deck.h"
#include "graphics.h"
#include "Card.h"

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