#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);

	myMaterial.setDiffuseColor(ofColor(128, 0, 255));
	myMaterial.setSpecularColor(ofColor(255, 255, 255));
	myMaterial.setAmbientColor(ofColor(128, 0, 255));
	myMaterial.setShininess(50.0);

	myPointLight.setDiffuseColor(ofColor(255, 255, 255));
	myPointLight.setSpecularColor(ofColor(255, 255, 255));
	myPointLight.setPosition(vec3(10, 10, 20));

	ofSetGlobalAmbientColor(ofColor(60, 60, 60));

	myCamera.setPosition(vec3(0, 0, 20));
	myCamera.setTarget(vec3(0, 0, 0));
	myCamera.setFov(60.0f);
	myCamera.setAutoDistance(false);

	baseFrequency = 0.5;
	maxBranchDepth = 24;
	scaleMult = 0.8;
	scaleAmplitude = 0.15;
	rotAmplitude = 40.0;
	phaseShift = 30.0;
	harmonicShift = 1;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	float t = ofGetElapsedTimef();
	float theta = 360.0 * baseFrequency * t;
	ofEnableDepthTest();
	ofEnableLighting();
	myCamera.begin();
	myMaterial.begin();
	int numInstances = 16;
	for (int i = 0; i < numInstances; i++) 
	{
		ofPushMatrix();
		ofRotateZDeg(360.0 * i / numInstances);
		float theta = 360.0 * baseFrequency * t;
		float phase = 360.0 * i / numInstances;
		drawHarmonicHierarchy(theta, phase, 1, 0);
		ofPopMatrix();
	}
	//drawHarmonicHierarchy(theta, 0, 1, 0);
	//ofDrawSphere(5.0);
	myMaterial.end();
	myPointLight.enable();

}
//--------------------------------------------------------------
void ofApp::drawHarmonicHierarchy(float theta, float phase, int harmonic, int branchDepth){

	ofPushMatrix();
	ofRotateDeg(rotAmplitude * sin(ofDegToRad(harmonic * theta + phase)));
	ofScale(scaleMult + scaleAmplitude * cos(ofDegToRad(harmonic * theta + phase)));
	ofTranslate(vec3(0, 1, 0));
	ofDrawSphere(1.0);
	ofTranslate(0, 1, 0);
	if (branchDepth < maxBranchDepth) 
	{
		drawHarmonicHierarchy(theta, phase + phaseShift, harmonic + harmonicShift, branchDepth + 1);
	}
	ofPopMatrix();
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
