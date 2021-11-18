//sanstete.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "sanstete.h"
using namespace std;
using namespace sf;


SansTete::SansTete(string path){
  if (!texture.loadFromFile(path)){
    cout<<"Load failed successfuly"<<endl;
    system("pause");
  }
  sprite.setTexture(texture);
}
void SansTete::setTextureRect(float top, float left, float width, float height){
  head.top=top;
  head.left=left;
  head.width=width;
  head.height=height;
  sprite.setTextureRect(head);
}
void SansTete::move(Vector2f distance){
  sprite.move(distance);
}
void SansTete::setPosition(Vector2f newPos){
  sprite.setPosition(newPos);
}
void SansTete::drawTo(RenderWindow & window){
  window.draw(sprite);
}
int SansTete::getY(){
  return sprite.getPosition().y;
}
int SansTete::getX(){
  return sprite.getPosition().x;
}
