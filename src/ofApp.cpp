#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    bool ok = false;

    if(!sm_reader) {
        //sm_reader = std::make_shared<lsm::SharedMemoryReadStream>("imagePipe", 262143, false);
        auto res = lsm::SharedMemoryReadStream::tryCreate("imagePipe", 262143, false);
        if (res.first) {
            sm_reader = res.second;
            ok = true;
        }
    }
    else {
        ok = true;
    }

    if (ok) {
        ofBuffer buffer = sm_reader->readBytes();
        tex = serializer.deserialize(buffer);
        buffer.clear();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (tex.isAllocated()) {
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
