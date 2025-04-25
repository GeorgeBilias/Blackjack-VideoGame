#pragma
#include <iostream>
#include <vector>
#include "Card.h"

class Deck
{
	static Deck* m_instance;
public:
	Deck(); // deck constructor
	~Deck(); // deck destructor
	void fill_deck(); // function that fills the deck in order
	void randomise_cards(); // function to randomise the deck cards
	Card giveCard(); // function to get a card from the deck
	static Deck* getInstance();
	void resetdeck(); // a function that clears deck
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
private:
	std::vector<Card*> deck; // creating a vector of Cards as a deck
};