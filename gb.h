//gb.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
using namespace std;
using namespace sf;

class GB{
public:
  Sprite sprite;
  Texture texture;
  IntRect gasterblaster;
  GB();
  void position(Vector2f Pos);
  void drawTo(RenderWindow & window);
  void move(Vector2f distance);
  int getY();
  int getX();
  void animation();
};
