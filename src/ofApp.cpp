#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToConsole();
    ofSetFrameRate(60);
    
    subscriber.connect("tcp://localhost:5555");
}

//--------------------------------------------------------------
void ofApp::update(){
    bool atleast_one = false;
     while (subscriber.hasWaitingMessage()) {
        atleast_one = true;
        ofBuffer buffer;
        subscriber.getNextMessage(buffer);

        if (buffer.size() > 0) {
            // ofLog() << "has waiting message!";
            
            try {
                tex = serializer.deserialize(buffer);
                // ofLog() << "deserialized!";
            } catch (std::exception& e) {
                ofLogError() << e.what();
            }
        }
     }
    
    if(!atleast_one){
//        ofLog() << "no waiting message....orz";
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (tex.isAllocated()) {
        // ofLog() << "drawed!!";
        tex.draw(0, 0);
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
