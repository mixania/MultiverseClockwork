#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  mySound.load("orange.mp3");
  mySound.play();

  ofBackground(0, 0, 0);

  circleSize = 30;

  var = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
  loopCount ++;

  // Animation 1

  if ((ofGetElapsedTimeMillis() % 5000) < 2500) {
    fadeIn += 3;
  } else {
    fadeIn -= 3;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0, 0, 0);

  ofDrawBitmapStringHighlight("Clockwork", ofGetWidth()/2,  ofGetHeight()/2);

  // Animation 1
  // Fading randomn circle
  if (ofGetElapsedTimeMillis() < 15000) {
    ofSetColor((int)ofRandom(50,200),(int)ofRandom(50,200),(int)ofRandom(50,200), fadeIn);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2 - 100, 70, 70);
    fadeIn2 = 0;
  }

  // Animation 2
  else if (ofGetElapsedTimeMillis() < 32000) {
    if (loopCount % 2 == 0 && fadeIn2 < 255) {
      fadeIn2++;
    }

    // random lines
    for (int i = 0; i < 200; i++) {
      ofSetColor(fadeIn2/2,fadeIn2/2, fadeIn2/2);
      int x1 = ofRandom(0,ofGetWidth());
      int y1 = ofRandom(0,ofGetHeight());
      int x2 = ofRandom(0,ofGetWidth());
      int y2 = ofRandom(0,ofGetHeight());
      ofDrawLine(x1,y1,x2,y2);
    }

    // fade in circle;
    ofSetColor(255,165, 0, fadeIn2);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2 - 100, 300 - fadeIn2, 300 - fadeIn2);

  }

  // Animation 3
  else if (ofGetElapsedTimeMillis() < 50000) {
    int clock1 = (loopCount % 100);
    int clock2 = ((loopCount - 50) % 100);

    if (clock1 < clock2) {
      var ++;
    } else {
      var --;
    }

    ofRotate(4, 1, 0.5, 0);

    for (int i = 0; i < 8; i ++) {
      for (int j = 0; j < 8; j ++) {
        ofSetColor(255,165, 0, fadeIn2);

        // draw
        ofDrawEllipse(ofGetWidth()/4 + var*i, ofGetHeight()/4 + var*j - 100, 300 - fadeIn2, 300 - fadeIn2);

      }
    }
  }

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
