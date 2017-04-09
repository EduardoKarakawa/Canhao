#include "Tiro.h"

ofVec2f Tiro::GetPostion() { return m_position; }
float Tiro::GetRadius() { return m_radius; }

bool Tiro::OnScreen()
{
	if (m_position.x < ofGetWidth() && m_position.x > 0 &&
		m_position.y < ofGetHeight() && m_position.y > 0)
		return true;
	return false;
}


Tiro::Tiro(ofVec2f position, ofVec2f force, float mass, ofVec2f wind)
{
	m_gravity = ofVec2f(0, 100.f);
	m_wind = wind;
	m_force = ofVec2f(force.x, -force.y) + m_wind + m_gravity;
	m_mass = mass;
	m_position = position;
	m_momentum = (m_force / m_mass) * ofGetLastFrameTime();
	m_radius = 25.f;
}

void Tiro::Update() {
	m_force = m_force + m_wind + m_gravity;
	ofVec2f acceleration = (m_force / m_mass) * ofGetLastFrameTime();
	m_position += (m_momentum + acceleration / 2.0f)  * ofGetLastFrameTime();
	m_momentum += acceleration;
}

void Tiro::Draw() {
	ofSetColor(21, 21, 21);
	ofDrawCircle(m_position, m_radius);
}


Tiro::~Tiro()
{
}
