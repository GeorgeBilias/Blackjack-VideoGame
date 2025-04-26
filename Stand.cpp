#include "Stand.h"
#include "graphics.h"
#include "config.h"


Stand* Stand::getInstance()
{
	if (!m_instance)
		m_instance = new Stand();
	return m_instance;
}

void Stand::draw() {
	Button::draw();
}

bool Stand::contains(float x, float y) {
	return Button::contains(x, y);
}
