//fightmenu.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "fightmenu.h"
#include "button.h"
#include "player.h"
using namespace std;
using namespace sf;


FightMenu::FightMenu(Button Fight,Button Act,Button Items, Button Mercy){
  buttons.insert(buttons.end(),Fight);
  buttons.insert(buttons.end(),Act);
  buttons.insert(buttons.end(),Items);
  buttons.insert(buttons.end(),Mercy);
}
int FightMenu::selectedButton(int Button, Sprite sprite, Event event,int & presse){
  if (event.type==sf::Event::KeyPressed){
    switch(event.key.code){
    case sf::Keyboard::Right:
      Button=(Button+1)%4;
      break;
    case sf::Keyboard::Left:
      if(Button==0){
	Button=3;
      }
      else{
	Button-=1;
      }
      break;
    case sf::Keyboard::Return:
      presse=4;
      if (Button==0){
	presse=0;
      }
      if(Button==1){
	presse=1;
      }
      if(Button==2){
	presse=2;
      }
      if(Button==3){
	presse=3;
      }
      break;
    }
  }
  return Button;
}

void FightMenu::EtatDuMenu(const int Button, Player & heart){
  if(Button==0){
    buttons[0].etat.left=115.f;
    buttons[1].etat.left=0.f;
    buttons[2].etat.left=0.f;
    buttons[3].etat.left=0.f;
    heart.sprite.setPosition({110.f,612.f});
    buttons[0].sprite.setTextureRect(buttons[0].etat);
    buttons[1].sprite.setTextureRect(buttons[1].etat);
    buttons[2].sprite.setTextureRect(buttons[2].etat);
    buttons[3].sprite.setTextureRect(buttons[3].etat);
  }
  if(Button==1){
    buttons[0].etat.left=0.f;
    buttons[1].etat.left=115.f;
    buttons[2].etat.left=0.f;
    buttons[3].etat.left=0.f;
    heart.sprite.setPosition({260.f,612.f});
    buttons[0].sprite.setTextureRect(buttons[0].etat);
    buttons[1].sprite.setTextureRect(buttons[1].etat);
    buttons[2].sprite.setTextureRect(buttons[2].etat);
    buttons[3].sprite.setTextureRect(buttons[3].etat);
  }
  if(Button==2){
    buttons[0].etat.left=0.f;
    buttons[1].etat.left=0.f;
    buttons[2].etat.left=115.f;
    buttons[3].etat.left=0.f;
    heart.sprite.setPosition({410.f,612.f});
    buttons[0].sprite.setTextureRect(buttons[0].etat);
    buttons[1].sprite.setTextureRect(buttons[1].etat);
    buttons[2].sprite.setTextureRect(buttons[2].etat);
    buttons[3].sprite.setTextureRect(buttons[3].etat);
  }
  if(Button==3){
    buttons[0].etat.left=0.f;
    buttons[1].etat.left=0.f;
    buttons[2].etat.left=0.f;
    buttons[3].etat.left=115.f;
    heart.sprite.setPosition({560.f,612.f});
    buttons[0].sprite.setTextureRect(buttons[0].etat);
    buttons[1].sprite.setTextureRect(buttons[1].etat);
    buttons[2].sprite.setTextureRect(buttons[2].etat);
    buttons[3].sprite.setTextureRect(buttons[3].etat);
  }
}
void FightMenu::drawTo(sf::RenderWindow & window, Player & heart){
  for(int i=0;i<4;i++){
    buttons[i].drawTo(window);
  }
  heart.drawTo(window);
}

