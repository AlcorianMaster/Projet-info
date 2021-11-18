//Player.h

#ifndef __player_h__
#define __player_h__1
class FightMenu;
class Player{
private:
  int lifepoint;
  int attack;
  int defense;  
public:
  float speed;
  sf::Texture texture;
  sf::Sprite sprite;
  Player(int lifepoint1,int attack1,int defense1,float speed1,std::string path);
  void move(sf::Vector2f distance);
  void setPosition(sf::Vector2f newPos);
  void drawTo(sf::RenderWindow & window);
  int getY();
  int getX();
  void movement(bool blue,bool & isJumping, bool & plafond, const float groundheight);
};
#endif
