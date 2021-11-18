//player.ccp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include "player.h"
using namespace std;
using namespace sf;

Player::Player (int lifepoint1, int attack1, int defense1, float speed1, std::string texture_path) :
  lifepoint(lifepoint1), attack(attack1), defense(defense1), speed(speed1)
{
  if (!texture.loadFromFile(texture_path))
    throw std::runtime_error("Loading of the texture failed !");
  this->sprite.setTexture(texture);
}

void Player::move(sf::Vector2f distance){
  sprite.move(distance);
}
void Player::setPosition(sf::Vector2f newPos){
  sprite.setPosition(newPos);
}

void Player::drawTo(sf::RenderWindow & window){
  window.draw(sprite);
}
int Player::getY(){
  return sprite.getPosition().y;
}
int Player::getX(){
  return sprite.getPosition().x;
}
void Player::movement(bool blue,bool & isJumping, bool & plafond,const float groundheight){
  if(blue){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->getY() >= 400.f && plafond==false ){
      this->move({0, -speed});
      isJumping=true;
    }
    if(this->getY()==400.f){
      plafond=true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->getY()<=groundheight){
      this->move({0,speed});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getX() < 700.f){
      this->move({speed,0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& this->getX() > 30.f){
      this->move({-speed,0});
    }
  }
  if(!blue){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->getY() >= 400.f){
      this->move({0, -speed});
      isJumping=true;
	}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->getY()<=groundheight){
      this->move({0,speed});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->getX() < 700.f){
      this->move({speed,0});
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& this->getX() > 30.f){
      this->move({-speed,0});
    }
  }
}

