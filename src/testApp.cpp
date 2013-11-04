#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    camWidth            = ofGetWidth();
    camHeight           = ofGetHeight();
	videoBuffer         = 0;
	vidGrabber.setVerbose(true);
	vidGrabber.setDeviceID(0);
	vidGrabber.initGrabber(camWidth,camHeight);
    text.loadFont("action.ttf", 32);
    
	
	for (int i = 0; i < FRAME_DELAY; i++) {
        videoDelay[i].allocate(camWidth, camHeight, GL_RGB);
    }
    ofSetVerticalSync(true);
    delayReady = false;
    ofBackground(0, 0, 0);
}


//--------------------------------------------------------------
void testApp::update(){
	
	vidGrabber.update();
    
	if (vidGrabber.isFrameNew()){
        videoDelay[videoBuffer].loadData(vidGrabber.getPixels(), camWidth, camHeight, GL_RGB);
        videoBuffer++;
        if (videoBuffer == FRAME_DELAY) {
            delayReady = true;
            videoBuffer = 0;
        }

    }

}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0xffffff);
    if (delayReady) {
        videoDelay[videoBuffer].draw(0, 0, camWidth, camHeight);
    }
    else {
        for (int i = 0; i < videoBuffer; i++) {
            ofCircle(videoBuffer * 10, ofGetHeight()/2, 5);
        }
        //        text.drawString("Buffering... " + ofToString(int(ofMap(videoBuffer, 0, FRAME_DELAY, 0, 100))) + "%", (ofGetWidth()/2) - (text.stringWidth("Buffering... 000%")/2), ofGetHeight()/2);
    }
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	
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
