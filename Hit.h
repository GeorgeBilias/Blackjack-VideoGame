// Hit.h
#pragma once
#include "Button.h"
#include "config.h"

class Hit : public Button {
private:
	static Hit* m_instance;

public:
	void draw() override;
	bool contains(float x, float y) override;
	static Hit* getInstance();
	static void releaseInstance() {
		if (m_instance) delete m_instance; m_instance = nullptr;
	}
	std::string getTextureName() const override { return "hit.png"; }
	float getX() const override { return HIT_X; }
	float getY() const override { return HIT_Y; }
	float getWidth() const override { return HIT_WIDTH; }
	float getHeight() const override { return HIT_HEIGHT; }
	bool useDiskShape() const override { return true; }

};

