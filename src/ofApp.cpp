#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  mySound.load("orange.mp3");
  mySound.play();
  mySound.setVolume(0.8);

  ofBackground(0, 0, 0);

  circleSize = 25;

  // animation 2
  fadeIn = 125;

  // animation 3
  var = 100;

  // animation 4b
  arrayLengths = 4;
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
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, circleSize, circleSize);

    // reality within reality circles
    for (int v = 0; v < 1 + (var/100); v ++) {
      // spreading circles
      for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
          ofSetColor(255,165, 0);

          ofDrawEllipse(ofGetWidth()/2 + var*i, ofGetHeight()/2 + var*j, circleSize, circleSize);
          ofDrawEllipse(ofGetWidth()/2 + var*i, ofGetHeight()/2 - var*j, circleSize, circleSize);
          ofDrawEllipse(ofGetWidth()/2 - var*i, ofGetHeight()/2 + var*j, circleSize, circleSize);
          ofDrawEllipse(ofGetWidth()/2 - var*i, ofGetHeight()/2 - var*j, circleSize, circleSize);


          // draw
          ofDrawEllipse(ofGetWidth()/2 + (var - 100*v)*i, ofGetHeight()/2 + (var - 100*v)*j, circleSize, circleSize);
          ofDrawEllipse(ofGetWidth()/2 + (var - 100*v)*i, ofGetHeight()/2 - (var - 100*v)*j, circleSize, circleSize);
          ofDrawEllipse(ofGetWidth()/2 - (var - 100*v)*i, ofGetHeight()/2 + (var - 100*v)*j, circleSize, circleSize);
          ofDrawEllipse(ofGetWidth()/2 - (var - 100*v)*i, ofGetHeight()/2 - (var - 100*v)*j, circleSize, circleSize);

        }
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
      if (var > 30) {
        var2 --;
      }
    }

    rotation += 0.5;
    ofRotate(rotation, 1, 0.5, 0.1);

    for (int i = 0; i < 4; i ++) {
      for (int j = 0; j < 4; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 + var2*j, circleSize, circleSize);
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 - var2*j, circleSize, circleSize);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 + var2*j, circleSize, circleSize);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 - var2*j, circleSize, circleSize);

      }
    }
  }

  // Animation 4b
  else if (ofGetElapsedTimeMillis() < 75000) {
    int clock1 = (loopCount % 100);
    int clock2 = ((loopCount - 50) % 100);

    if (clock1 < clock2) {
      var2 ++;
    } else {
      if (var > 30) {
        var2 --;
      }
    }

    if (clock1 == 0) {
      arrayLengths ++;
    }

    rotation += 0.5;
    ofRotate(rotation, 1, 0.5, 0.1);

    for (int i = 0; i < arrayLengths; i ++) {
      for (int j = 0; j < arrayLengths; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 + var2*j, circleSize, circleSize);
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 - var2*j, circleSize, circleSize);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 + var2*j, circleSize, circleSize);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 - var2*j, circleSize, circleSize);

      }
    }
  }

  // Animation 4c
  else if (ofGetElapsedTimeMillis() < 90000) {
    int clock1 = (loopCount % 300);
    int clock2 = ((loopCount - 50) % 300);

    if (clock1 < clock2) {
      var2 ++;
    } else {
      if (var > 30) {
        var2 --;
      }
    }

    if (clock1 == 0 || clock1 == 100  || clock1 == 200) {
      arrayLengths ++;
    }

    int randomCircleSize = ofRandom(circleSize - 2, circleSize + 2);
    rotation += 0.5;
    ofRotate(rotation, 1, 0.5, 0.1);

    for (int i = 0; i < arrayLengths; i ++) {
      for (int j = 0; j < arrayLengths; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 + var2*j, randomCircleSize, randomCircleSize);
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 - var2*j, randomCircleSize, randomCircleSize);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 + var2*j, randomCircleSize, randomCircleSize);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 - var2*j, randomCircleSize, randomCircleSize);

      }
    }
  }

  // Animation 5a
  else if (ofGetElapsedTimeMillis() < 110000) {

    var2 = 100;

    rotation += 0.5;
    ofRotate(rotation, 1, 0, 0);

    if (loopCount % 50 ) {
      if (minus < 60 ) {
        minus ++;

      }
    }

    for (int i = 0; i < 50; i ++) {
      for (int j = 0; j < 50; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);

      }
    }
  }

  // Animation 5b
  else if (ofGetElapsedTimeMillis() < 130000) {

    rotation += 0.5;
    ofRotate(rotation, 0, 1, 0);

    if (loopCount % 50 ) {
      if (minus < 60 ) {
        minus ++;

      }
    }

    for (int i = 0; i < 50; i ++) {
      for (int j = 0; j < 50; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);

      }
    }
  }

  // Animation 5c
  else if (ofGetElapsedTimeMillis() < 150000) {

    rotation += 0.5;
    ofRotate(rotation, 0, 0, 1);

    if (loopCount % 50 ) {
      if (minus < 60 ) {
        minus ++;

      }
    }

    for (int i = 0; i < 50; i ++) {
      for (int j = 0; j < 50; j ++) {
        ofSetColor(255,165, 0);

        // draw
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);

      }
    }
  }

  // Animation 6
    else if (ofGetElapsedTimeMillis() < 180000) {

      rotation += 0.5;
      ofRotate(rotation, 0, 0, 1);

      if (loopCount % 50 ) {
        if (minus < 60 ) {
          minus ++;

        }
      }

      for (int i = 0; i < 50; i ++) {
        for (int j = 0; j < 50; j ++) {
          ofSetColor(255,165, 0);

          // draw
          ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
          ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
          ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
          ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);

        }
      }

      rotation += 0.5;
      ofRotate(rotation, 0, 1, 0);

      if (loopCount % 50 ) {
        if (minus < 60 ) {
          minus ++;
        }
      }

      for (int i = 0; i < 50; i ++) {
        for (int j = 0; j < 50; j ++) {
          ofSetColor(255,165, 0);

          // draw
          ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
          ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
          ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
          ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        }
      }

      rotation += 0.5;
      ofRotate(rotation, 1, 0, 0);

      if (loopCount % 50 ) {
        if (minus < 60 ) {
          minus ++;

        }
      }

      for (int i = 0; i < 50; i ++) {
        for (int j = 0; j < 50; j ++) {
          ofSetColor(255,165, 0);

          // draw
          ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
          ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
          ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
          ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);

        }
      }
  }

  // Animation 7
  // Clock
  else if (ofGetElapsedTimeMillis() < 190000) {
    ofSetColor(255,165, 0);
    float angle = incrementalAngle;
    for(int i = 0; i < 12; i++){
      ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2,100 * sin(incrementalAngle) + ofGetWidth()/2, circleSize, circleSize);

      incrementalAngle += 6.2831853071795 / 12;
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
