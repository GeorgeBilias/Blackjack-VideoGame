#include "Exit.h"
#include "graphics.h"
#include "config.h"


void Exit::draw()
{

	graphics::Brush br;

	float h = 1.0f * m_highlighted;

	
	br.texture = "";
	SETCOLOR(br.fill_color, h, h, h);
	br.outline_opacity = 1.0f * m_active;
	graphics::drawDisk(EXIT_X, EXIT_Y, EXIT_WIDTH * 0.35f, br);
	graphics::resetPose();
	

	SETCOLOR(br.fill_color, 1, 1, 1);
	br.texture = ASSET_PATH + std::string("exit.png");
	br.outline_opacity = 0.0f;
	graphics::drawRect(EXIT_X, EXIT_Y, EXIT_WIDTH, EXIT_HEIGHT, br);


}

void Exit::update()
{
}

Exit* Exit::getInstance()
{
	if (!m_instance)
		m_instance = new Exit();
	return m_instance;
}

bool Exit::contains(float x, float y)
{
	return distance(x, y, EXIT_X, EXIT_Y) < EXIT_WIDTH * 0.40f;
}

