
#include "ofApp.h"
#include <math.h>
//--------------------------------------------------------------
void ofApp::setup(){

	//input the music
	mySound.load("Summer_Cozy_Rock.mp3");
	mySound.play();
	volume = mySound.getVolume();
	//set the basic information of music
	fft = new float[128];
	for (int i = 0; i < 128; i++) {
		fft[i] = 0;
	}

	bands = 64;

	//set up mesh width and heigth
	meshwidth = 180;
	meshheight = 120;
	// set the quality of circle
	ofSetCircleResolution(60);
	
	//set initial value of perlin noise mesh
	perlinRange = 5.0;
	perlinHeight = 10.0;

	//basic setting
	ofBackground(255, 255, 255);
	mainCam.setPosition(0, 20, 100);

	//creat mesh vertex
	for (int y = 0; y < meshheight; y++) {
		for (int x = 0; x < meshwidth; x++) {
			mainMesh.addVertex(ofPoint(x - meshwidth / 2, y - meshheight / 2, 0));    
			mainMesh.addColor(ofFloatColor(0, 0, 0));  
		}
	}

	//join vertex to frangles
	for (int y = 0; y < meshheight - 1; y++) {
		for (int x = 0; x < meshwidth - 1; x++) {
			mainMesh.addIndex(x + y * meshwidth);                
			mainMesh.addIndex((x + 1) + y * meshwidth);            
			mainMesh.addIndex(x + (y + 1) * meshwidth);            
			
			mainMesh.addIndex((x + 1) + y * meshwidth);           
			mainMesh.addIndex((x + 1) + (y + 1) * meshwidth);        
			mainMesh.addIndex(x + (y + 1) * meshwidth);            
		}
	}
}
//--------------------------------------------------------------
void ofApp::update(){
	//get sound variable
	ofSoundUpdate();
	mySound.setVolume(volume);
	soundSpectrum = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++) {
		fft[i] *= decay;
		if (fft[i] < soundSpectrum[i]) {
			fft[i] = soundSpectrum[i];
		}

	}
	//set up z value
	int i = 0;

	for (int y = 0; y < meshheight; y++) {
		for (int x = 0; x < meshwidth ; x++) {
			ofVec3f newPosition = mainMesh.getVertex(i);
			//creat position.z;use sound vriable to control position.z
			for (int q = 0; q < bands; q++) {
				
				newPosition.z = ofNoise(ofMap(x, 0, meshwidth, 0, perlinRange), ofMap(y, 0, meshheight, 0, perlinRange)) * perlinHeight;
				newPosition.z *= soundSpectrum[q]*10000;
				
				q++;
			}
			mainMesh.setVertex(i, newPosition); // update 
			i++;

		}
	}

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	mainCam.begin();
	
	for (int i = 0; i < bands; i++) {


		ofRotateX(270);//change the circle orientation
		ofSetLineWidth(fft[i] * 10);
		//ofSetColor(sin(fft[i]*50)*190,cos(soundSpectrum[i]*20)*90,210); 
		// color also can be changed, but I think it looks not very good...
		ofSetColor(0),
		ofNoFill();
		ofDrawCircle(0, -60, 100, 25+ soundSpectrum[i]*20);//use sound control circle size

		ofSetColor(255);
		ofFill();
		ofDrawCircle(0, -60, 100, 24);
		
	}
	for (int i = 0; i < bands; i++) {
		mainMesh.drawVertices();
		
	}
	

	mainCam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	/*
	mouseX = x;
	mouseY = y;
	perlinHeight += x * 0.01;
	perlinRange += y * 0.01;
	*/
	//I try to use mouse control mesh,but mouse need to control camera...
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
