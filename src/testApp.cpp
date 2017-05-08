#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	cout << "Press up to make the bird go up. Press Enter when you are ready to start the game." << endl;
	cout << "Do you want your bird to be square (1) or circle (2)?" << endl;
	cin >> num;
	
	switch(num){
	case 1:
		bird = new Square(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 50.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
		break;

	case 2:
		bird = new Circle(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 25.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
		break;
	}
	topBarriers = new Barriers[3];
	bottomBarriers = new Barriers[3];
	int xPos=ofGetWidth()/2;

	for(int i = 0; i < 3; i++)
	{
		topBarriers[i] = Barriers(10, ofRandom(50,300), ofVec2f(xPos, 0));
		ofPushMatrix();
		ofRotateY(180);
		bottomBarriers[i] = Barriers(10, -topBarriers[i].getHeight(), ofVec2f(xPos, ofGetHeight()));
		ofPopMatrix();
		xPos+=200;
	}
	flag = false;
	score = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	if(flag == true)
	{
		bird->move();
	}

	if(bird->getPos().x + 50 > ofGetWidth())
	{
		bird->setPos(ofVec2f(0, bird->getPos().y));

		int xPos=(ofGetWidth()/2) - 300;
		for(int i = 0; i < 5; i++)
		{
			topBarriers[i] = Barriers(10, ofRandom(50,300), ofVec2f(xPos, 0));
			ofPushMatrix();
			ofRotateY(180);
			bottomBarriers[i] = Barriers(10, -topBarriers[i].getHeight(), ofVec2f(xPos, ofGetHeight()));
			ofPopMatrix();
			xPos+=200;
		}
	}

	if(bird->getPos().y + 50 > ofGetHeight())
	{
		flag = false;
		switch(num){
			case 1:
			bird = new Square(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 50.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
			break;

			case 2:
			bird = new Circle(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 25.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
			break;
		}
	}

	else if(bird->getPos().y - 50 < 0)
	{
		flag = false;
		switch(num){
			case 1:
			bird = new Square(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 50.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
			break;

			case 2:
			bird = new Circle(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 25.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
			break;
		}
	}

	for(int a = 0; a < 3; a++)
	{
		if(bird->getPos().x + 50 > topBarriers[a].getPos().x && bird->getPos().y > topBarriers[a].getHeight() && bird->getPos().y + 50 < (ofGetHeight()-topBarriers[a].getHeight()))
		{
			score++;
		}

		else if(((bird->getPos().x + 50 > topBarriers[a].getPos().x ) && ((bird->getPos().y) < topBarriers[a].getHeight())) &&
			bird->getPos().x < topBarriers[a].getPos().x+10)
		{
			flag = false;
			cout << "You lose! Score is: " << score << endl;
			switch(num){
				case 1:
				bird = new Square(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 50.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
				break;

				case 2:
				bird = new Circle(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 25.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
				break;
			}
			score = 0;
		}

		else if((bird->getPos().x + 50  > bottomBarriers[a].getPos().x) && (bird->getPos().y + 50 > (ofGetHeight()-topBarriers[a].getHeight())) &&
				bird->getPos().x < bottomBarriers[a].getPos().x+10)
		{
			flag = false;
			cout << "You lose! Score is: " << score << endl;
			switch(num){
				case 1:
				bird = new Square(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 50.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
				break;

				case 2:
				bird = new Circle(ofVec2f(50, ofGetHeight()/2), ofVec2f(.25,0), 25.0, ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
				break;
			}
			score = 0;
		}

	}
}

//--------------------------------------------------------------
void testApp::draw(){
	bird->display();
	for(int i = 0; i < 3;i++){
		topBarriers[i].display();
		bottomBarriers[i].display();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == OF_KEY_UP){
		bird->setPos(ofVec2f(bird->getPos().x, bird->getPos().y-150));
	}

	if(key == OF_KEY_RETURN){
		flag = true;
	}

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
