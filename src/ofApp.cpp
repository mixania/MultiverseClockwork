#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  mySound.load("orange.mp3");
  mySound.play();
  mySound.setVolume(0.2);

  ofBackground(0, 0, 0);

  circleSize = 30;
  fadeIn = 125;
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


  // Animation 1
  // Fading randomn circle
  if (ofGetElapsedTimeMillis() < 22000) {
    ofDrawBitmapStringHighlight("Clockwork", ofGetWidth()/2,  ofGetHeight()/2);
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
      ofSetColor(70,70, 70);
      int x1 = ofRandom(0,ofGetWidth());
      int y1 = ofRandom(0,ofGetHeight());
      int x2 = ofRandom(0,ofGetWidth());
      int y2 = ofRandom(0,ofGetHeight());
      ofDrawLine(x1,y1,x2,y2);
    }

    // fade in circle;
    ofSetColor(255,165, 0, fadeIn2);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, 300 - fadeIn2, 300 - fadeIn2);
    var = 0;
  }

  // Animation 3
  else if (ofGetElapsedTimeMillis() < 50000) {
    if (loopCount % 2 == 0) {
      var ++;
    }

    ofSetColor(255,165, 0);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, 45, 45);

    // spreading circles
    for (int i = 0; i < 4; i ++) {
      for (int j = 0; j < 4; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth()/2 + var*i, ofGetHeight()/2 + var*j, 45, 45);
        ofDrawEllipse(ofGetWidth()/2 + var*i, ofGetHeight()/2 - var*j, 45, 45);
        ofDrawEllipse(ofGetWidth()/2 - var*i, ofGetHeight()/2 + var*j, 45, 45);
        ofDrawEllipse(ofGetWidth()/2 - var*i, ofGetHeight()/2 - var*j, 45, 45);

      }
    }

  }

  // Animation 4a
  else if (ofGetElapsedTimeMillis() < 60000) {
    int clock1 = (loopCount % 100);
    int clock2 = ((loopCount - 50) % 100);

    if (clock1 < clock2) {
      var2 ++;
    } else {
      var2 --;
    }

    rotation += 0.5;
    ofRotate(rotation, 1, 0.5, 0.1);

    for (int i = 0; i < 4; i ++) {
      for (int j = 0; j < 4; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 + var2*j, 45, 45);
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 - var2*j, 45, 45);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 + var2*j, 45, 45);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 - var2*j, 45, 45);

      }
    }
  }

  // Animation 4b
  else if (ofGetElapsedTimeMillis() < 70000) {
    int clock1 = (loopCount % 100);
    int clock2 = ((loopCount - 50) % 100);

    if (clock1 < clock2) {
      var2 ++;
    } else {
      var2 --;
    }

    rotation += 0.5;
    ofRotate(rotation, 1, 0.5, 0.1);

    for (int i = 0; i < 4; i ++) {
      for (int j = 0; j < 4; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 + var2*j, 45, 45);
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 - var2*j, 45, 45);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 + var2*j, 45, 45);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 - var2*j, 45, 45);

      }
    }

    for (int i = 0; i < 4; i ++) {
      for (int j = 0; j < 4; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(var2*i, var2*j, 45, 45);
        ofDrawEllipse(var2*i, var2*j, 45, 45);
        ofDrawEllipse(var2*i, var2*j, 45, 45);
        ofDrawEllipse(var2*i, var2*j, 45, 45);

      }
    }

    for (int i = 0; i < 4; i ++) {
      for (int j = 0; j < 4; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth() + var2*i, ofGetHeight() + var2*j, 45, 45);
        ofDrawEllipse(ofGetWidth() + var2*i, ofGetHeight() - var2*j, 45, 45);
        ofDrawEllipse(ofGetWidth() - var2*i, ofGetHeight() + var2*j, 45, 45);
        ofDrawEllipse(ofGetWidth() - var2*i, ofGetHeight() - var2*j, 45, 45);

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
