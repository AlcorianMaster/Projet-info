//fightmenu.h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "button.h"
#include "player.h"
using namespace std;
using namespace sf;

#ifndef __fightmenu_h__
#define __fightmenu_h__1

class FightMenu{
public:
  vector<Button> buttons;
  FightMenu(Button Fight,Button Act,Button Items, Button Mercy);
  void selectedButton(int Button, Sprite sprite, Event event,int & presse);
  void EtatDuMenu(const int Button, Player & heart);
  void drawTo(sf::RenderWindow & window, Player & heart);
};

#endif

