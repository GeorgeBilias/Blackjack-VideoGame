#pragma once
// Paths
#define ASSET_PATH "assets\\"
 
//Window and Canvas Sizing
#define WINDOW_WIDTH 1200 // window width
#define WINDOW_HEIGHT 600 // window height
#define CANVAS_WIDTH 1000 // canvas width
#define CANVAS_HEIGHT 500 // canvas height

//Cards picture Sizing
#define CARD_X 200  // the x location of the card png
#define CARD_Y 60 // the y location of the card png
#define CARD_WIDTH 260 // the width of the card png 
#define CARD_HEIGHT 160 // the height of the card png

//Cards 1 spawning TBD

#define CARD1_X 100 
#define CARD1_Y 370
#define CARD1_WIDTH 70
#define CARD1_HEIGHT 100

//Dealer Card1
#define CARD2_X 370 
#define CARD2_Y 100

//Hit picture Sizing
#define HIT_X 850  // the x location of the card png
#define HIT_Y 400 // the y location of the card png
#define HIT_WIDTH 100 // the width of the card png 
#define HIT_HEIGHT 100 // the height of the card png

//Stand picture Sizing
#define STAND_X 940  // the x location of the card png
#define STAND_Y 400 // the y location of the card png
#define STAND_WIDTH 100 // the width of the card png 
#define STAND_HEIGHT 100 // the height of the card png

//Exit picture Sizing
#define EXIT_X 40  // the x location of the card png
#define EXIT_Y 40 // the y location of the card png
#define EXIT_WIDTH 60 // the width of the card png 
#define EXIT_HEIGHT 60 // the height of the card png

//Replay picture Sizing
#define REPLAY_X  960 // the x location of the card png
#define REPLAY_Y 40 // the y location of the card png
#define REPLAY_WIDTH 50 // the width of the card png 
#define REPLAY_HEIGHT 50 // the height of the card png

#define SETCOLOR(c, r ,g ,b) {c[0] = r; c[1] = g; c[2] = b;}
#define RAND0TO1() (rand()/(float)RAND_MAX)

inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}