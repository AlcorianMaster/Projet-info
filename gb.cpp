//gb.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "gb.h"
using namespace std;
using namespace sf;

GB::GB(){
  if(!texture.loadFromFile("../premier test/Sprite/Sans_attack/attack sans.png")){
    cout<<"Load Failed!"<<endl;
    system("pause");
  }
  
  sprite.setTexture(texture);
  gasterblaster.top=0;
  gasterblaster.left=0;
  gasterblaster.width=45;
  gasterblaster.height=60;
  sprite.setTextureRect(gasterblaster);
  sprite.setScale(2.f,2.f);
}
void GB::position(Vector2f Pos){
  sprite.setPosition(Pos);
}
void GB::drawTo(RenderWindow & window){
  window.draw(sprite);
}
void GB::move(Vector2f distance){
    sprite.move(distance);
}
int GB::getY(){
  return sprite.getPosition().y;
}
int GB::getX(){
  return sprite.getPosition().x;
}
void GB::animation(){
  
}

