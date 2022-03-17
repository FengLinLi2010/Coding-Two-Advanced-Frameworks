#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){	
	ofBackground(255,255,255);	
	ofSetFrameRate(60);
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	


	
	
	//------(d)--------------------------------------
	// 
	// 		2 kind of poylgon colour and numbers can be interact by mouse move 
	//
	// 		
	// 
	// 
	ofSetColor(120,255-mouseY,255-mouseY);
	ofSetPolyMode(OF_POLY_WINDING_ODD);
	ofBeginShape();
	for (int i = 0; i < mouseX; i++){
		ofVertex(ofRandom(0,1024), ofRandom(0,768),mouseX);
	}
	ofEndShape();
	
	ofSetColor(mouseX, mouseY, mouseY);
	ofSetPolyMode(OF_POLY_WINDING_ODD);
	ofBeginShape();
	for (int i = 0; i < mouseY; i++) {
		ofVertex(ofRandom(0, 1024), ofRandom(0, 768));
	}
	ofEndShape();

	//-------------------------------------text

	
	
	ofSetHexColor(0x000000);
	ofDrawBitmapString("chaos of the digital world", 800,720);
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//------------- -------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	mouseX = x;
	mouseY = y;
	
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
