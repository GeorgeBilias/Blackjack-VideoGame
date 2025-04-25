#pragma once
#include <graphics.h>

class Card
{
public:
	Card(int style, int num); // card constructor
	Card(const Card&); // using for getters
	~Card(); // card destructor
	int getNum()const; // getting the number of the card
	int getStyle() const; // getting the style of the card
	int getValue() const; // getting the value of the card
	bool getGiven() const; // getting if the card is already given or not
	void cardGiven(); // setting the card as given
	std::string returnbr(); // drawing the card function
private:
	int num;
	int style;
	int value;
	bool given;
	int setValue();
	graphics::Brush br;
};