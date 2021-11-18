//sanscorps.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "sanscorps.h"
using namespace std;
using namespace sf;

SansCorps::SansCorps(string path){
  if (!texture.loadFromFile(path)){
    cout<<"Load failed successfuly"<<endl;
    system("pause");
  }
  sprite.setTexture(texture);
}
void SansCorps::setTextureRect(float top, float left, float width, float height){
  body.top=top;
  body.left=left;
  body.width=width;
  body.height=height;
  sprite.setTextureRect(body);
}
void SansCorps::move(Vector2f distance){
  sprite.move(distance);
}
void SansCorps::setPosition(Vector2f newPos){
  sprite.setPosition(newPos);
}
void SansCorps::drawTo(RenderWindow & window){
  window.draw(sprite);
}
int SansCorps::getY(){
  return sprite.getPosition().y;
}
int SansCorps::getX(){
  return sprite.getPosition().x;
}

