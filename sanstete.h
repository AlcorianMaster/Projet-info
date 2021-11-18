//sanstete.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
using namespace std;
using namespace sf;


class SansTete{
public:
  IntRect head;
  Texture texture;
  Sprite sprite;
  SansTete(string path);
  void setTextureRect(float top, float left, float width, float height);
  void move(Vector2f distance);
  void setPosition(Vector2f newPos);
  void drawTo(RenderWindow & window);
  int getY();
  int getX();
};


