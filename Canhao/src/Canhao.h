#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"
#include "Tiro.h"


class Canhao
{
	private:
		float m_force;
		ofVec2f m_direction;
		ofVec2f m_position;
		float m_angle;
		Tiro* m_tiro;
		bool m_atirou;
		ofVec2f m_wind;

	public:
		void addForce(float deltaTime);
		void Draw();
		void Rotation(ofVec2f angle);
		float GetAngle();
		void Atirar();
		void Update();
		ofVec2f GetPostion();
		bool GetAtirou();
		ofVec2f GetTiroPosition();
		float GetTiroRadius();
		void ResetTiro();
		void NewWind();

		Canhao();
		~Canhao();
};

