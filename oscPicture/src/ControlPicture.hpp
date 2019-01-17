//
//  ControlPicture.hpp
//  oscPicture
//
//  Created by 引田祐樹 on 2019/01/15.
//

#pragma once
#ifndef ControlPicture_hpp
#define ControlPicture_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Particle.hpp"

using namespace glm;
class ControlPicture {
    
public:
    ControlPicture(ofImage _img);
    ~ControlPicture();
    void update();
    void display();
    
    bool dead;
    
private:
    vector<Particle*> particle;
    ofImage img;
    vector<vector<vec3>> location;
    vector<vector<ofColor>>imgColor;
    int imgW,imgH;
    ofPixels pixels;
    float r;
    vec3 start;
    
};

#endif /* ControlPicture_hpp */
