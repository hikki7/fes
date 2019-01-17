#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    
    ofBackground(0,0,0);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    cam.setup(640, 480);
    smile.setup();
    findSmileFlg = false;
    ofSetCircleResolution(64);
    
    interval=0;
    count=0;
    
    //指定したIPアドレスとポート番号でサーバーに接続
    sender.setup(Host, Port);
    
}

void ofApp::update() {
    cam.update();
    
    if(cam.isFrameNew()){
        smile.update(cam);
    
        if(smile.getSmileAmount()) {
            findSmileFlg = true;
        } else{
            findSmileFlg = false;
        }
    }
    
    if(interval>0){
        interval++;
    }
    
    if(interval>180){
        interval=0;
    }
}

void ofApp::draw() {
    ofSetColor(255,255,255);
    
    cam.draw(0, 0);
    smile.draw();
    
    if(findSmileFlg){
        ofDrawCircle(ofGetWidth()*3/4, ofGetHeight()*4/5, 100);
        if(interval==0){
            pic.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            //pic.save(ofToString(count)+"pic.png");
            string path="/Users/amaimon/Documents/of_v0.10.1_osx_release/apps/fes/oscPicture/bin/data/"+ofToString(count)+"pic.png";
            pic.save(path);
            interval++;
            count++;
            ofSetColor(255,255,0);
            ofDrawCircle(ofGetWidth()*3/4, ofGetHeight()*4/5, 100);
            
            ofxOscMessage m;
            m.setAddress("/mouse/position");
            m.addIntArg(count);
            sender.sendMessage(m);
        }
    }
    
    ofDrawBitmapString(interval, 20, 600);
}

void ofApp::keyPressed(int key){
    
}


