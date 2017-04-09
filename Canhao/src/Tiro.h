#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"

class Tiro
{
	private:
		ofVec2f m_gravity, m_wind;
		ofVec2f m_position;
		ofVec2f m_momentum;
		ofVec2f m_force;
		float m_mass, m_radius;

	public:
		Tiro(ofVec2f position, ofVec2f force, float mass, ofVec2f wind);
		void Update();
		void Draw();
		ofVec2f GetPostion();
		float GetRadius();
		bool OnScreen();
		~Tiro();
};

