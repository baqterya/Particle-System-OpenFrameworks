#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	t0 = ofGetElapsedTimef();
	backgroundImage.load("sky2.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
	float dt = ofGetElapsedTimef() - t0;

	for (auto i = 0; i < systems.size(); i++) {
		systems[i].update(dt);
		if (systems[i].allDead() && systems[i].canChild && systems[i].canCopy()) {
			for (auto j = 0; j < systems[i].newLocations.size(); j++) {
				systems.push_back(ParticleSystem(
					systems[i].newLocations[j], 
					systems[i].generation + 1,
					ofVec3f(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255))
				));
			}
			systems[i].canChild = false;
		}
	}
	t0 = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableAlphaBlending();
	ofSetColor(240, 240, 240, 100);
	backgroundImage.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	for (auto& sys : systems) {
		sys.draw();

		if (sys.canSpawn()) {
			sys.addParticle();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	systems.push_back(ParticleSystem(
		ofVec3f(x, y, 0), 
		0,
		ofVec3f( ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255) )
	));
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
