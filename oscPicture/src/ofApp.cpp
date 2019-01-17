#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofHideCursor();
    ofSetFullscreen(true);
    
    receiver.setup(Port);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(controlp.size()>0){
        for(int i=0;i<controlp.size();i++){
            controlp[i]->update();
            if(controlp[i]->dead){
                controlp[i]=controlp.back();
                controlp.pop_back();
            }
        }
    }
    
    while (receiver.hasWaitingMessages()) {
        //get message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if(m.getAddress()=="/mouse/position"){
            count=m.getArgAsInt32(0);
            img.load(ofToString(count)+"pic.png");
            controlp.push_back(new ControlPicture(img));
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(controlp.size()>0){
        for(int i=0;i<controlp.size();i++){
            controlp[i]->display();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    controlp.push_back(new ControlPicture(img));
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
