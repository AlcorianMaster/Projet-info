//button.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
using namespace std;
using namespace sf;

#ifndef __button_h__
#define __button_h__1
class FightButton;
class Button{
public:
  IntRect etat;
  Texture texture;
  Sprite sprite;
  Button(string path);
  void setTextureRect(float top, float left, float width, float height);
  void setPosition(Vector2f newPos);
  void drawTo(RenderWindow & window);
  bool Selected();
  bool notSelected();
  bool Pressed();
  bool notPressed();
  int getY();
  int getX();
};
#endif
