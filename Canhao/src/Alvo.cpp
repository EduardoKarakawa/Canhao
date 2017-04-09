#include "Alvo.h"



Alvo::Alvo()
{
	m_postion = ofVec2f(ofGetWidth() - 150, ofGetHeight() - 50);
	m_width = 200.f;
	m_height = 50.f;
}

void Alvo::Draw()
{
	ofSetColor(150, 0, 0);
	ofDrawEllipse(m_postion, m_width, m_height);
}

bool Alvo::Acertou(ofVec2f position, float raio)
{
	if(raio > -1){
		if (position.x > m_postion.x - m_width / 2.f && position.x < m_postion.x + m_width / 2.f &&
			position.y > m_postion.y - m_height / 2.f && position.y < m_postion.y + m_height / 2.f)
			return true;
	}
	return false;
}


Alvo::~Alvo()
{
}
