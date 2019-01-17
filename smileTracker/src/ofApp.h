#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "SmileDetector.hpp"
#include "ofxOsc.h"

#define Host "localhost"
#define Port 8000

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    
    // カメラ
    ofVideoGrabber cam;
    
    // 笑顔検知クラス
    SmileDetector smile;
    
    // 笑ってるかどうか
    bool findSmileFlg;
    
    ofImage pic;
    int interval;
    int count;
    
    //oscの送信者
    ofxOscSender sender;
};


