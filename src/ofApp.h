#pragma once


#include "ofMain.h"
#include "mesh.h"
#include "ofxGUI.h"

#define OBJFNAME "TDPAssassinLotus.obj"

class ofApp : public ofBaseApp{

	private:
		mesh m;

	public:
		void setup();
		void update();
		void draw();

		void loadFile(const char* fname);

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
		
		ofEasyCam cam;

		bool bHide = false;
		ofxFloatSlider normalLength;
		ofxToggle normalToggle;
		ofxPanel gui;
};
