#include "ofApp.h"
#include "ofxGui.h"
#include "math.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup() {
	xcoord = 150;
	ycoord = 150;
	xgoal = 150;
	ygoal = 150;
	speed = 6;
	vector<Projectile> bullets;
	spider.load("JumpingSpiderBuff.jpg");
	gui.setup();
	gui.add(bullspeed.set("bullet speed", 0, 0, 400));
	wall = new GameObject(0, 0, 32, 32, "Wall.png");
}

//--------------------------------------------------------------
void ofApp::update() {
	float d = pow(xgoal - xcoord, 2) + pow(ygoal - ycoord, 2);
	d = sqrt(d);
	if (d <= speed)
	{
		xcoord = xgoal;
		ycoord = ygoal;
	}
	else {
		xcoord += (-(xcoord - xgoal) / d)*speed;
		ycoord += (-(ycoord - ygoal) / d)*speed;
	}
	for (int x(0); x != bullets.size(); x++)
	{
		cout << bullets[x].move();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	spider.draw(xcoord, ycoord);
	gui.draw();
	for (int x(0); x != bullets.size(); x++)
	{
		bullets[x].draw()->draw(bullets[x].getX(), bullets[x].getY());
	}

	wall->draw()->draw(wall->getX(), wall->getY());

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	inputwait = key;
	std::cout<<key;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	cout << button;
	if (button == 0 && inputwait != 13)
	{
		wall->setPosition(x, y);
	}
	if (inputwait == 13 && button == 0)
	{
		
		Point2D<float> tempbase((float)xcoord, (float)ycoord);
		Point2D<float> tempend((float)x,(float)y);

		//jusque la ca va

		bullets.push_back(Projectile(tempbase, tempend, bullspeed/60, 500));
		inputwait = 0;
	}
	else if (button == 2){
		xgoal = x - 16;
		ygoal = y - 16;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
