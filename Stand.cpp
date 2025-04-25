#include "Stand.h"
#include "graphics.h"
#include "config.h"


void Stand::draw()
{

	graphics::Brush br;

	float h = 1.0f * m_highlighted;


	br.texture = "";
	SETCOLOR(br.fill_color, h, h, h);
	br.outline_opacity = 1.0f * m_active;
	graphics::drawDisk(STAND_X, STAND_Y, STAND_WIDTH * 0.35f, br);
	graphics::resetPose();


	SETCOLOR(br.fill_color, 1, 1, 1);
	br.texture = ASSET_PATH + std::string("stand.png");
	br.outline_opacity = 0.0f;
	graphics::drawRect(STAND_X, STAND_Y, STAND_WIDTH, STAND_HEIGHT, br);

}

void Stand::update()
{
}

Stand* Stand::getInstance()
{
	if (!m_instance)
		m_instance = new Stand();
	return m_instance;
}

bool Stand::contains(float x, float y)
{
	return distance(x, y, STAND_X, STAND_Y) < HIT_WIDTH * 0.24f;
}

