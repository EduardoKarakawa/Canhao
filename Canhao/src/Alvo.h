#pragma once
#include "ofGraphics.h"
#include "ofAppRunner.h"
#include "ofVec2f.h"

class Alvo
{
private:
	ofVec2f m_postion;
	float m_width, m_height;

public:
	Alvo();
	void Draw();
	bool Acertou(ofVec2f position, float raio);
	~Alvo();
};

