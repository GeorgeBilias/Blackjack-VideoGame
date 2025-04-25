// GEORGIOS BILIAS 3200278
// PANAGIOTIS BOURAZANAS 3200268

#include "graphics.h"
#include "config.h"
#include "Game.h"

void update(float ms)
{

	// Calling the update function from the game
	Game* blackjack = Game::getInstance();
	blackjack->update();
}


void draw()
{
	//Basically calling the draw function from the Game
	Game* blackjack = Game::getInstance();
	blackjack->draw();

}

int main()
{
	
	//Creates a Window 
	graphics::createWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"Blackjack Game");
	//Creates a Game and gets it if it exists
	Game * blackjack = Game::getInstance();

	//Creates a Canvas where we can actually work upon
	graphics::setCanvasSize(CANVAS_WIDTH,CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);
	graphics::startMessageLoop();

	return 0;
}

