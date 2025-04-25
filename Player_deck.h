#pragma once
#include "Card.h"
#include "config.h"
#include "Base_deck.h"

class Player_deck : public Base_deck
{
	static Player_deck* m_instance;
public:
	void draw(); // // a function that draws player's deck
	static Player_deck* getInstance();
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
private:
	std::vector<Card> player_deck; // a vector for the player's deck (his cards)
};