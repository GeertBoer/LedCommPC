#include "ofApp.h"
#include "SerialArduino.h"
#define NUM_LEDS 76

//--------------------------------------------------------------
void ofApp::setup(){
	serial = new SerialArduino("COM18", 9600);
}

void ofApp::LEDPulse() {
	// animation which sends a stroke to either side starting from the center
	serial->Clear();

	int l;
	int r;

	l = (NUM_LEDS) / 2 + 1;
	r = (NUM_LEDS) / 2 - 1;

	while (l < NUM_LEDS && r >= 0) {
		l++;
		serial->SetColor(l, 100, 255, 100);
		serial->SetColor(l - 8, 0, 0, 0);

		r--;
		serial->SetColor(r, 100, 255, 100);
		serial->SetColor(r + 8, 0, 0, 0);

		serial->Flush();
		serial->Delay(25);
	}

	for (int i = 7; i >= 0; i--)
	{
		serial->SetColor(i, 0, 0, 0);
		serial->SetColor(NUM_LEDS - i, 0, 0, 0);
		serial->Flush();
		serial->Delay(25);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	LEDPulse();

	
	//int max = 255;
/*
	for (uint8_t i = 0; i < max; i++)
	{
		for (uint8_t d = 0; d < 75; d++)
		{
			serial->SetColor(d, 0, 0, i);
		}
		serial->Flush();
		serial->Delay(1000);
	}
	/*
	for (uint8_t i = 0; i < max; i++)
	{
		for (uint8_t d = 0; d < 75; d++)
		{
			serial->SetColorV2(d, 0, i, max);
		}
		serial->FlushV2();
	}
	for (uint8_t i = 0; i < max; i++)
	{
		for (uint8_t d = 0; d < 75; d++)
		{
			serial->SetColorV2(d, i, max, max);
		}
		serial->FlushV2();
	}


	for (uint8_t i = max; i >= 0; i--)
	{
		for (uint8_t d = 0; d < 75; d++)
		{
			serial->SetColorV2(d, max, max, i);
		}
		serial->FlushV2();
	}
	for (uint8_t i = max; i >= 0; i--)
	{
		for (uint8_t d = 0; d < 75; d++)
		{
			serial->SetColorV2(d, max, i, 0);
		}
		serial->FlushV2();
	}
	for (uint8_t i = max; i >= 0; i--)
	{
		for (uint8_t d = 0; d < 75; d++)
		{
			serial->SetColorV2(d, i, 0, 0);
		}
		serial->FlushV2();
	}*/
}

//--------------------------------------------------------------
void ofApp::draw(){

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
