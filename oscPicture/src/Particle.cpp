//
//  Particle.cpp
//  oscPicture
//
//  Created by 引田祐樹 on 2019/01/15.
//

#include "Particle.hpp"

Particle::Particle(ofColor _color,vec3 start){
    color=_color;
    location=start;
    firstVec=vec3(1,-1,0);
    firstVec*=10;
    r=1;
    lifeSpan=255;
    border=false;
    secondVec=vec3(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),ofRandom(ofGetHeight()));
    secondVec=normalize(secondVec);
    speed=10;
    secondVec*=speed;
}

Particle::~Particle(){
    
}

void Particle::update(){
    if(border){
        location+=secondVec;
        lifeSpan-=5;
    }else{
        location+=firstVec;
        //境界の判別式
        if(location.y<location.x){
            border=true;
        }
    }
}

void Particle::display(){
    ofSetColor(color,lifeSpan);
    ofDrawCircle(location,r);
}

bool Particle::dead(){
    return lifeSpan<0;
}
