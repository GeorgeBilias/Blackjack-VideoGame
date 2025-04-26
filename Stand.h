// Stand.h
#pragma once
#include "Button.h"
#include "config.h"

class Stand : public Button {
private:
	static Stand* m_instance;

public:
	void draw() override;
	bool contains(float x, float y) override;
	static Stand* getInstance();
	static void releaseInstance() {
		if (m_instance) delete m_instance; m_instance = nullptr;
	}
	std::string getTextureName() const override { return "stand.png"; }
	float getX() const override { return STAND_X; }
	float getY() const override { return STAND_Y; }
	float getWidth() const override { return STAND_WIDTH; }
	float getHeight() const override { return STAND_HEIGHT; }
	bool useDiskShape() const override { return true; }

};

