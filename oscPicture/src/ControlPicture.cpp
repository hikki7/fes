//
//  ControlPicture.cpp
//  oscPicture
//
//  Created by 引田祐樹 on 2019/01/15.
//

#include "ControlPicture.hpp"

ControlPicture::ControlPicture(ofImage _img){
    
    dead=false;
    
    //画像の処理系
    img=_img;
    imgW=img.getWidth();
    imgH=img.getHeight();
    pixels=img.getPixels();
    r=1.0;
    start=vec3(0,ofGetHeight(),0);
    
    cout<<imgH<<endl;
    
    //imgの位置と色の取得
    imgColor.resize(imgH);
    location.resize(imgH);
    for(int y=0;y<imgH;y++){
        imgColor[y].resize(imgW);
        location[y].resize(imgW);
        for(int x=0;x<imgW;x++){
            imgColor[y][x]=pixels.getColor(x,y);
            location[y][x]=vec3(x,y,0);
            location[y][x]+=start;
            particle.push_back(new Particle(imgColor[y][x],location[y][x]));
        }
    }
}

ControlPicture::~ControlPicture(){
    
}


void ControlPicture::update(){
    
    if(particle.size()<1){
        dead=true;
    }else{
        for(int i=0;i<particle.size();i++){
            Particle* ps=particle[i];
            ps->update();
            if(ps->dead()){
                particle[i]=particle.back();
                particle.pop_back();
            }
        }
    }
}

void ControlPicture::display(){
    for(int i=0;i<particle.size();i++){
        particle[i]->display();
    }
}


