#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	srand(time(NULL));
	m_canhao = Canhao();
}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (m_alvo.Acertou(m_canhao.GetTiroPosition(), m_canhao.GetTiroRadius())) {
		std::cout << "Acertou" << std::endl;
		m_canhao.ResetTiro();
	}
	m_canhao.Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	m_canhao.Draw();
	m_alvo.Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_UP) {
		setup();
	}
	if (key == ' ' && !m_canhao.GetAtirou()) {
		m_canhao.addForce(ofGetLastFrameTime());
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == ' ' && !m_canhao.GetAtirou()) {
		std::cout << "Atirou" << std::endl;
		m_canhao.Atirar();
	}

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	m_canhao.Rotation(ofVec2f(x, y));
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
