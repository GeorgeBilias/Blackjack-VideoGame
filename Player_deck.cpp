#include "Player_deck.h"
#include "graphics.h"

void Player_deck::first_cards(Card c1, Card c2)
{
	player_deck.push_back(c1);
	player_deck.push_back(c2);
}

void Player_deck::showCards()
{
}

void Player_deck::getCard(Card c)
{
	player_deck.push_back(c);
}

int Player_deck::getNumberofCards()
{
	return player_deck.size();
}

int Player_deck::getValueofCards()
{
	int sum = 0;
	for (std::vector<Card>::iterator i = player_deck.begin(); i != player_deck.end(); i++)
	{
		sum += i->getValue();
	}
	return sum;
}

void Player_deck::draw()
{
	float s = 0.0f;

	for (std::vector<Card>::iterator i = player_deck.begin(); i != player_deck.end(); i++)
	{
		graphics::Brush br;
		br.texture= i->returnbr();
		br.outline_opacity = 0.0f;
		graphics::drawRect(CARD1_X + s, CARD1_Y, CARD1_WIDTH, CARD1_HEIGHT, br);
		s += 100.0f;
	}
}

void Player_deck::resetdeck()
{
	player_deck.clear();
}

Player_deck* Player_deck::getInstance()
{
	if (!m_instance)
		m_instance = new Player_deck();
	return m_instance;
}