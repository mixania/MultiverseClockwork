#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  mySound.load("orange.mp3");
  mySound.play();
  mySound.setVolume(1.0);

  // animation end times:
  animation1Time = 22000;
  animation2Time = 34000;
  animation3Time = 45000;
  animation4aTime = 60000;
  animation4bTime = 65000;
  animation4cTime = 75000;
  animation5aTime = 90000;
  animation5bTime = 105000;
  animation5cTime = 120000;
  animation6Time = 135000;
  animation7Time = 150000;
  animation8Time = 170000;
  animation9Time = 190000;

  resetTime = 0;

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
  if (inverse) {
    // orange background
    ofBackground(255,165, 0);
  } else {
    ofBackground(0, 0, 0);
  }

  // Animation 1
  // Fading randomn circle
  if (ofGetElapsedTimeMillis() < animation1Time) {
    ofDrawBitmapStringHighlight("Multiverse Clockwork", 40,  ofGetHeight()/4*3);
    ofDrawBitmapStringHighlight("©2016 Michael Braverman", 40,  ofGetHeight()/4*3 + 25);
    ofDrawBitmapStringHighlight("Music:", 40,  ofGetHeight()/4*3 + 60);
    ofDrawBitmapStringHighlight("ClockWork Orange - Funeral Of Queen Mary", 40,  ofGetHeight()/4*3 + 75);
    ofDrawBitmapStringHighlight("Deadmau5 - Clockwork", 40,  ofGetHeight()/4*3 + 100);
    ofSetColor((int)ofRandom(50,200),(int)ofRandom(50,200),(int)ofRandom(50,200), fadeIn);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2 - 100, 70, 70);
    fadeIn2 = 0;
  }

  // Animation 2
  // Random Lines and Fading Circle
  else if (ofGetElapsedTimeMillis() < animation2Time) {
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
  // Inception circles
  else if (ofGetElapsedTimeMillis() + resetTime < animation3Time) {
    if (loopCount % 2 == 0) {
      var ++;
    }

    ofSetColor(255,165, 0);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2, circleSize, circleSize);

    // reality within reality circles
    for (int v = 0; v < 1 + (var/100); v ++) {
      // spreading circles
      for (int i = 0; i < 7; i ++) {
        for (int j = 0; j < 7; j ++) {
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
  // closing and opening circles
  else if ((ofGetElapsedTimeMillis() + resetTime) < animation4aTime) {
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
  // growing circles
  else if ((ofGetElapsedTimeMillis() + resetTime) < animation4bTime) {
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
  // "Un-suspended dimensions circles"
  else if ((ofGetElapsedTimeMillis() + resetTime) < animation4cTime ) {
    int clock1 = (loopCount % 300);
    int clock2 = ((loopCount - 50) % 300);

    if (clock1 < clock2) {
      var2 ++;
      inverse = true;
      ofSetColor(0,0, 0);
    } else {
      inverse = false;
      ofSetColor(255,165, 0);
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

        // draw
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 + var2*j, randomCircleSize, randomCircleSize);
        ofDrawEllipse(ofGetWidth()/2 + var2*i, ofGetHeight()/2 - var2*j, randomCircleSize, randomCircleSize);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 + var2*j, randomCircleSize, randomCircleSize);
        ofDrawEllipse(ofGetWidth()/2 - var2*i, ofGetHeight()/2 - var2*j, randomCircleSize, randomCircleSize);

      }
    }
  }

  // Animation 5a
  else if ((ofGetElapsedTimeMillis() + resetTime) < animation5aTime) {

    int clock1 = (loopCount % 300);
    int clock2 = ((loopCount - 150) % 300);

    if (clock1 < clock2) {
      inverse = true;
      ofSetColor(0,0, 0);
    } else {
      if (var > 30) {
        inverse = false;
        ofSetColor(255,165, 0);
      }
    }

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

        // draw
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);

      }
    }
  }

  // Animation 5b
  else if ((ofGetElapsedTimeMillis() + resetTime) < animation5bTime) {

    int clock1 = (loopCount % 300);
    int clock2 = ((loopCount - 150) % 300);

    if (clock1 < clock2) {
      inverse = true;
      ofSetColor(0,0, 0);
    } else {
      if (var > 30) {
        inverse = false;
        ofSetColor(255,165, 0);
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

        // draw
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);

      }
    }
  }

  // Animation 5c
  else if ((ofGetElapsedTimeMillis() + resetTime) < animation5cTime) {

    int clock1 = (loopCount % 300);
    int clock2 = ((loopCount - 150) % 300);

    if (clock1 < clock2) {
      inverse = true;
      ofSetColor(0,0, 0);
    } else {
      if (var > 30) {
        inverse = false;
        ofSetColor(255,165, 0);
      }
    }

    rotation += 0.5;
    ofRotate(rotation, 0, 0, 1);

    if (loopCount % 50 ) {
      if (minus < 60 ) {
        minus ++;

      }
    }

    for (int i = 0; i < 50; i ++) {
      for (int j = 0; j < 50; j ++) {

        // draw
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 + (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 + (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);
        ofDrawEllipse(ofGetWidth()/2 - (var2 + minus)*i, ofGetHeight()/2 - (var2 + minus)*j, circleSize*5 - minus, circleSize*5 - minus);

      }
    }
  }

  // Animation 6
    else if ((ofGetElapsedTimeMillis() + resetTime) < animation6Time) {

      int clock1 = (loopCount % 300);
      int clock2 = ((loopCount - 150) % 300);

      if (clock1 < clock2) {
        inverse = true;
        ofSetColor(0,0, 0);
      } else {
        if (var > 30) {
          inverse = false;
          ofSetColor(255,165, 0);
        }
      }

      rotation += 0.5;
      ofRotate(rotation, 0, 0, 1);

      if (loopCount % 50 ) {
        if (minus < 60 ) {
          minus ++;

        }
      }

      for (int i = 0; i < 50; i ++) {
        for (int j = 0; j < 50; j ++) {

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
  else if (ofGetElapsedTimeMillis() + resetTime < animation7Time) {

    int clock1 = (loopCount % 300);
    int clock2 = ((loopCount - 150) % 300);

    if (clock1 < clock2) {
      inverse = true;
    } else {
      if (var > 30) {
        inverse = false;
      }
    }

    int hourHand = ofMap(loopCount % 60, 0, 60, 0, 12);

    float angle = incrementalAngle;
    for(int i = 0; i < 12; i++){
      if (hourHand == i) {
        // hightlight clock color

        // check if inverse
        if (inverse) {
          ofSetColor(0,0, 0);
        } else {
          // default
          ofSetColor(255,165, 0);
        }
      } else {
        // the rest of the 11 digits,
        if (inverse) {
          ofSetColor(0,0, 0, 120);
        } else {
          // default
          ofSetColor(255,165, 0, 120);
        }
      }

      ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2 + 150,100 * sin(incrementalAngle) + ofGetWidth()/2 - 100, circleSize, circleSize);
      incrementalAngle += 6.2831853071795864769252867665590057683943387987502/ 12;
    }

    var3 = 0;
  }

  // Animation 8
  // Multiple Clocks spread
  else if ((ofGetElapsedTimeMillis() + resetTime) < animation8Time) {

  int clock1 = (loopCount % 300);
  int clock2 = ((loopCount - 150) % 300);

  if (clock1 < clock2) {
    inverse = true;
  } else {
    if (var > 30) {
      inverse = false;
    }
  }

  int hourHand = ofMap(loopCount % 60, 0, 60, 0, 12);
  int distanceBetweenClocks = 250;

  rotation += 0.5;
  ofRotate(rotation, 1, 0.5, 0);


  for(int m = 0; m < 10; m++){
    for(int n = 0; n < 10; n++){
      for(int i = 0; i < 12; i++){
        if (hourHand == i) {
          // hightlight clock color

          // check if inverse
          if (inverse) {
            ofSetColor(0,0, 0);
          } else {
            // default
            ofSetColor(255,165, 0);
          }
        } else {
          // the rest of the 11 digits,
          if (inverse) {
            ofSetColor(0,0, 0, 120);
          } else {
            // default
            ofSetColor(255,165, 0, 120);
          }
        }

        ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2 + distanceBetweenClocks*m,100 * sin(incrementalAngle) + ofGetWidth()/2 + distanceBetweenClocks*n, circleSize, circleSize);
        ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2 - distanceBetweenClocks*m,100 * sin(incrementalAngle) + ofGetWidth()/2 + distanceBetweenClocks*n, circleSize, circleSize);
        ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2 + distanceBetweenClocks*m,100 * sin(incrementalAngle) + ofGetWidth()/2 - distanceBetweenClocks*n, circleSize, circleSize);
        ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2 - distanceBetweenClocks*m,100 * sin(incrementalAngle) + ofGetWidth()/2 - distanceBetweenClocks*n, circleSize, circleSize);
        incrementalAngle += 6.2831853071795864769252867665590057/ 12;
        }
      }
    }
  }

  // Animation 10
  // Multiple Clocks spread
  else if ((ofGetElapsedTimeMillis() + resetTime )< animation9Time) {


    int clock1 = (loopCount % 300);
    int clock2 = ((loopCount - 150) % 300);

    if (clock1 < clock2) {
      inverse = true;
    } else {
      if (var > 30) {
        inverse = false;
      }
    }

    int hourHand = ofMap(loopCount % 60, 0, 60, 0, 12);
    int distanceBetweenClocks = 250;

    rotation += 0.5;
    ofRotate(rotation, 0, 1, 1);

    for(int m = 0; m < 10; m++){
      for(int n = 0; n < 10; n++){
        for(int i = 0; i < 12; i++){
          if (hourHand == i) {
            // hightlight clock color

            // check if inverse
            if (inverse) {
              ofSetColor(0,0, 0);
            } else {
              // default
              ofSetColor(255,165, 0);
            }
          } else {
            // the rest of the 11 digits,
            if (inverse) {
              ofSetColor(0,0, 0, 120);
            } else {
              // default
              ofSetColor(255,165, 0, 120);
            }
          }

          ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2 + distanceBetweenClocks*m,100 * sin(incrementalAngle) + ofGetWidth()/2 + distanceBetweenClocks*n, circleSize, circleSize);
          ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2 - distanceBetweenClocks*m,100 * sin(incrementalAngle) + ofGetWidth()/2 + distanceBetweenClocks*n, circleSize, circleSize);
          ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2 + distanceBetweenClocks*m,100 * sin(incrementalAngle) + ofGetWidth()/2 - distanceBetweenClocks*n, circleSize, circleSize);
          ofDrawEllipse(100 * cos(incrementalAngle) + ofGetHeight()/2 - distanceBetweenClocks*m,100 * sin(incrementalAngle) + ofGetWidth()/2 - distanceBetweenClocks*n, circleSize, circleSize);
          incrementalAngle += 6.2831853071795864769252867665590057683943387987502/ 12;
        }
      }
    }
  } else {

    // loop animations 4 throught 10
    resetTime = ofGetElapsedTimeMillis();
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
