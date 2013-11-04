#pragma once
#define FRAME_DELAY 200
#include "ofMain.h"

class testApp : public ofBaseApp{
	
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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
		
		ofVideoGrabber 		vidGrabber;
        ofTexture			videoDelay[FRAME_DELAY];
        ofTrueTypeFont      text;
        int 				camWidth;
		int 				camHeight;
        int                 videoBuffer;
        bool                delayReady;
};
