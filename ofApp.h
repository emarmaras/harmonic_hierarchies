#pragma once

#include "ofMain.h"

using namespace glm;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void drawHarmonicHierarchy(float theta, float phase, int harmonic, int branchDepth);

		int maxBranchDepth;
		int harmonicShift;
		float baseFrequency;
		float scaleMult;
		float scaleAmplitude;
		float rotAmplitude;
		float phaseShift;
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofEasyCam myCamera;
		ofMaterial myMaterial;
		ofLight myPointLight;
};
