#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    box = new CBox(500.0, 500.0, 500.0);
    
    // build some flocks for the boids to belong to
    // now assign the boids to the flocks
    
    Flocks[0] = new CFlock(10);
    Flocks[1] = new CFlock(4);
    Flocks[2] = new CFlock(13);
    Flocks[3] = new CFlock(2);
    Flocks[4] = new CFlock(1);
    
    mouseDownX=mouseDownY=0;
    inMouseDrag = false;

    ofBackground(191, 226, 246);
    backgroundImage.load("photo.png");
    ofSetWindowShape(backgroundImage.getWidth(), backgroundImage.getHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < MAX_FLOCKS; i++) {
        Flocks[i]->Update();
    }
    
    if(inMouseDrag)
    {
        ofVec3f screenVec(mouseX-mouseDownX,mouseY-mouseDownY,0.0);
        screenVec.limit(ofGetHeight()/2);
        float angle = (10.0 / 60.0) * screenVec.length() / (ofGetHeight()/2);
        screenVec.normalize();
        screenVec.set(screenVec.y,screenVec.x,0.0);
        wrld_rot = wrld_rot * ofQuaternion(ofDegToRad(angle), screenVec);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    backgroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
    
    ofPushStyle();
    float ang=0.0;
    ofVec3f axis;
    wrld_rot.getRotate(ang, axis);
    
    ofPushMatrix();
    
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2,0);
    ofRotate(ofRadToDeg(ang), -axis.x, axis.y, -axis.z);
    
    // box->Draw();
    
    for (int i = 0; i < MAX_FLOCKS; i++) {
        Flocks[i]->Draw();
    }
    
    ofPopMatrix();
    ofPopStyle();
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
