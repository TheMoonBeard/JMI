#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Projectile.h"
#include "GameObject.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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

	private:
		ofImage spider;
		ofxPanel gui;
		ofParameter <float> bullspeed;
		float speed;

		std::vector<Projectile> bullets;

		int inputwait;
		int inptype;
		float xgoal;
		float ygoal;
		float xcoord;
		float ycoord;
		GameObject* wall;
};