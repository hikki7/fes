//
//  Particle.hpp
//  oscPicture
//
//  Created by 引田祐樹 on 2019/01/15.
//

#pragma once
#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

using namespace glm;

class Particle {
    
    
public:
    Particle(ofColor _color,vec3 start);
    ~Particle();
    void update();
    void display();
    bool dead();
    
    bool border;
    
private:
    float lifeSpan;
    float r;
    vec3 location;
    vec3 firstVec;
    vec3 secondVec;
    ofColor color;
    float speed;
};

#endif /* Particle_hpp */
