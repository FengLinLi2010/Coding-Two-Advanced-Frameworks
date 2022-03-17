#include "testApp.h"
#include "boid.h"

testApp::~testApp()
{
	for (int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
	for (int i = 0; i < hunters.size(); i++)
	{
		delete hunters[i];
	}
}

//--------------------------------------------------------------
void testApp::setup() {


	int screenW = ofGetScreenWidth();
	int screenH = ofGetScreenHeight();

	ofBackground(255, 255, 255);

	// set up the boids
	for (int i = 0; i < 50; i++)
		boids.push_back(new Boid());
	for (int i = 0; i < 50; i++)
		hunters.push_back(new Hunter());
}





//--------------------------------------------------------------
void testApp::update() {

	ofVec3f min(0, 0);
	ofVec3f max(ofGetWidth(), ofGetHeight());
	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->update(boids, min, max);
	}
	for (int i = 0; i < hunters.size(); i++)
	{
		hunters[i]->newupdate(hunters, boids, min, max);
	}
}

//--------------------------------------------------------------
void testApp::draw() {

	for (int i = 0; i < boids.size(); i++)
	{
		boids[i]->draw();
	}
	for (int i = 0; i < hunters.size(); i++)
	{
		hunters[i]->newdraw();
	}
}


//--------------------------------------------------------------
void testApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}
