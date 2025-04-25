#include "Player_deck.h"
#include "graphics.h"
#include "Card.h"

void Player_deck::draw()
{
	float s = 0.0f;

	for (std::vector<Card>::iterator i = deck.begin(); i != deck.end(); i++)
	{
		graphics::Brush br;
		br.texture= i->returnbr();
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