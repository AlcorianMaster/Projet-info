//button.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "button.h"
using namespace std;
using namespace sf;

IntRect etat;
Texture texture;
Sprite sprite;

Button::Button(string path){ 
  if (!texture.loadFromFile(path))
    throw std::runtime_error("Loading of the texture failed !");
  sprite.setTexture(texture);
}
void Button::setTextureRect(float top, float left, float width, float height){
  etat.top=top;
  etat.left=left;
  etat.width=width;
  etat.height=height;
  sprite.setTextureRect(etat);
}
void Button::setPosition(Vector2f newPos){
  sprite.setPosition(newPos);
}
void Button::drawTo(RenderWindow & window){
  window.draw(sprite);
}
bool Button::Selected(){
  return true;
}
bool Button::notSelected(){
  return false;
}
bool Pressed(){
  return true;
}
bool notPressed(){
  return false;
}
int getY(){
  return sprite.getPosition().y;
}
int getX(){
  return sprite.getPosition().x;
}
