#include "Canhao.h"

float Canhao::GetAngle() { return m_angle; }
ofVec2f Canhao::GetPostion() { return m_position; }
Canhao::~Canhao(){}


Canhao::Canhao()
{
	NewWind();
	m_force = 0;	
	m_position = ofVec2f(0, ofGetHeight());
	m_atirou = false;
}

void Canhao::addForce(float deltaTime)
{	
	std::cout << " force = " << m_force << std::endl;
	m_force += 1000.f * ofGetLastFrameTime();
}

void Canhao::Draw()
{
	if (m_atirou) {
		m_tiro->Draw();
	}

	ofSetColor(0, 100, 220);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofPushMatrix();
	ofTranslate(m_position);
	ofRotateZ(m_angle);
	ofRect(125, 0, 250, 100);
	ofPopMatrix();

	ofSetColor(0, 150, 0);
	ofDrawCircle(ofVec2f(ofGetWidth() / 2.0f, 100.f) + m_wind* 4.f, 7.f);
	ofSetLineWidth(3.f);
	ofVec2f tmpWind = m_wind.normalized() * 75.f;
	ofDrawLine(ofVec2f(ofGetWidth() / 2.0f, 100.f), ofVec2f(ofGetWidth() / 2.0f, 100.f) + m_wind * 4.f);
}

void Canhao::Rotation(ofVec2f angle) {
	m_direction = angle;
	m_angle = atan2f(m_position.y - angle.y, m_position.x - angle.x) * 180.f / PI + 180.f;
}

void Canhao::Update() {
	if (m_atirou) {
		m_tiro->Update();
		if (!m_tiro->OnScreen()) {
			ResetTiro();
		}
	}
}

void Canhao::Atirar()
{
	ofVec2f tmpPos = m_direction - m_position;
	tmpPos = tmpPos.getNormalized() * 220.f;
	std::cout << tmpPos << std::endl;
	m_tiro = new Tiro(m_position + tmpPos, (m_direction * m_force), 25.f, m_wind);
	std::cout << " force = " << m_force << std::endl;
	m_force = 0;
	m_atirou = true;
}

bool Canhao::GetAtirou() { return m_atirou; }

ofVec2f Canhao::GetTiroPosition()
{
	if (m_atirou)
		return m_tiro->GetPostion();
	return ofVec2f(0,0);
}

float Canhao::GetTiroRadius()
{
	if(m_atirou)
		return m_tiro->GetRadius();
	return -1;
}

void Canhao::ResetTiro()
{
	delete m_tiro;
	m_atirou = false;
	NewWind();
}

void Canhao::NewWind() {
	m_wind = ofVec2f(-20 + rand() % 20, -20 + rand() % 20);
}
