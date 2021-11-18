#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "player.h"
#include "button.h"
#include "sanstete.h"
#include "gb.h"
#include "sanscorps.h"
#include "fightmenu.h"
using namespace std;
using namespace sf;





int main(){
  srand(static_cast<unsigned int>(time(NULL)));

  //Boutton de combat:
  Button Fight("../premier test/Sprite/Fight/fight.png");
  Button Items("../premier test/Sprite/item/item.png");
  Button Act("../premier test/Sprite/act/act.png");
  Button Mercy("../premier test/Sprite//mercy/mercy.png");
  Fight.setTextureRect(0,0,115,43);
  Items.setTextureRect(0,0,115,43);
  Act.setTextureRect(0,0,113,43);
  Mercy.setTextureRect(0,0,115,43);
  Fight.setPosition({100.f,600.f});
  Act.setPosition({250.f,600.f});
  Items.setPosition({400,600.f});
  Mercy.setPosition({550.f,600.f});
  FightMenu FMenu(Fight,Act,Items,Mercy);
  bool uTurn=true;


  
  //constante nécessaire:
  int gameWidth = 800;
  int gameHeight = 700;
  Vector2f paddlesize(30,30);
  float deltaTime;
  RectangleShape rect({25,0});
  rect.setFillColor(Color::White);
  float rayon=0;

  //Gravity Constant:
  const int groundheight=500;
  const float gravityspeed=5;
  bool isJumping=false;
  
  //definition de la fenêtre:
  RenderWindow window(VideoMode(gameWidth, gameHeight,32), "Undertale", Style::Titlebar |Style::Close);
  window.setVerticalSyncEnabled(true);

  //test du rouge:
  RectangleShape square2;
  square2.setSize(paddlesize - Vector2f(3,3));
  square2.setOutlineThickness(1);
  square2.setOutlineColor(Color::Red);
  square2.setFillColor(Color::Red);
  square2.setOrigin(paddlesize/2.f);
  square2.setPosition(420.f,110.f);

  //Definition des personnages:
  Player heart(92,99,99,2.5,"../premier test/Sprite/heart/spr_heart_0.png");
  heart.sprite.setScale(2.f,2.f);
  SansTete sanstete("../premier test/Sprite/Sans/sans_head.png");
  SansCorps sanscorps("../premier test/Sprite/Sans/sans_body.png");
  sanstete.sprite.setScale(3.f,3.f);
  sanscorps.sprite.setScale(3.f,3.f);
  sanstete.setTextureRect(34,0,35,30);
  sanstete.setPosition({325.f,100.f});
  sanscorps.setTextureRect(0,0,56,50);
  sanscorps.setPosition({sanstete.getX()-38.f,sanstete.getY()+75.f});

  GB gaster;
  gaster.position({10.f,60.f});
  rect.setPosition({gaster.getX()+26.f,gaster.getY()+85.f});

  //Message de base
  Text pauseMessage;
  Text play;
  Font font;
  Text exit;
  if(!font.loadFromFile("../MonsterFriendFore.otf")){
    return EXIT_FAILURE;
  }
  pauseMessage.setFont(font);
  pauseMessage.setCharacterSize(60);
  pauseMessage.setPosition(140.f,80.f);
  pauseMessage.setFillColor(Color::White);
  pauseMessage.setString("UNdERTaLE");
  
  play.setFont(font);
  play.setCharacterSize(40);
  play.setPosition(40.f,350.f);
  play.setFillColor(Color::Yellow);
  play.setString("  Play");

  exit.setFont(font);
  exit.setCharacterSize(40);
  exit.setPosition(40.f,470.f);
  exit.setFillColor(Color::White);
  exit.setString("  Exit");

  //Proprieties:
  Time AITime=seconds(0.1f);
  bool isPlaying=false;
  bool PlayButtonSelected=true;
  bool ExitButtonSelected=false;
  bool PlayButtonPressed=false;
  bool ExitButtonPressed=false;


  int presse=4;
  bool plafond=false;
  bool blue=false;
  int Button=0;
  //test de durée:
  Clock clock;
  Clock Timer;
  while(window.isOpen()){
    Event event;
    if(isPlaying){
      if(!uTurn){
	heart.movement(blue, isJumping, plafond,groundheight);
      }
      if(clock.getElapsedTime().asSeconds()>0.5f){
	if(sanscorps.body.left==224){
	  sanscorps.body.left=0;
	}
	else{
	  sanscorps.body.left+=56;
	}
	sanscorps.sprite.setTextureRect(sanscorps.body);
	clock.restart();
      }
    }
    while(window.pollEvent(event)){
      // Window closed or escape key pressed: exit
      if ((event.type == sf::Event::Closed) ||  ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))){
	window.close();
        break;
      }
      if(!isPlaying){
	if (event.type==sf::Event::KeyPressed){
	  switch(event.key.code){
	  case sf::Keyboard::Up:{
	    if(!PlayButtonSelected){
	      PlayButtonSelected=true;
	      ExitButtonSelected=false;
	    }
	    else{
	      PlayButtonSelected=false;
	      ExitButtonSelected=true;
	    }
	    break;
	  }
	  case sf::Keyboard::Down:{
	    if (!ExitButtonSelected){
	      PlayButtonSelected=false;
	      ExitButtonSelected=true;
	    }
	    else{
	      PlayButtonSelected=true;
	      ExitButtonSelected=false;
	    }
	    break;
	  }
	  case sf::Keyboard::Return:{
	    PlayButtonPressed=false;
	    ExitButtonPressed=false;
	    if(PlayButtonSelected){
	      PlayButtonPressed=true;
	    }
	    else{
	      ExitButtonPressed=true;
	    }
	    break;
	  }
	  default:{
	    break;
	  }  
	  }
	}
      }
      if(isPlaying){
	if(!uTurn){
	  switch(event.type){
	  case sf::Event::KeyReleased:
	    isJumping=false;
	  }
	}
	if(uTurn){
	  Button=FMenu.selectedButton(Button, heart.sprite,event,presse);
	}
      }
    }
    if(!isPlaying){
      if(PlayButtonSelected){
	play.setFillColor(Color::Yellow);
	exit.setFillColor(Color::White);
	heart.setPosition({20.f,355.f});
	window.clear(Color(Color::Black));
	window.draw(square2);
	window.draw(pauseMessage);
	heart.drawTo(window);
	window.draw(play);
	window.draw(exit);	
      }
      else{
	exit.setFillColor(Color::Yellow);
	play.setFillColor(Color::White);
	heart.setPosition({20.f,475.f});
	window.clear(Color(Color::Black));
	window.draw(square2);
	window.draw(pauseMessage);
	heart.drawTo(window);
	window.draw(play);
	window.draw(exit);
      }
      if(PlayButtonPressed){
	isPlaying=true;
	if (!uTurn){
	  heart.setPosition({450.f,50.f});
	  heart.sprite.setScale(1.f,1.f);
	}
	else{
	  heart.setPosition({110.f,612.f});
	  heart.sprite.setScale(1.f,1.f);
	}
      }
      else if(ExitButtonPressed){
	window.close();
	break;
      }
    }
    else{
      if(!uTurn){
	if((heart.getY()< groundheight) && (isJumping==false) && (blue) ||(plafond)){
	  heart.move({0, gravityspeed});
	  if(heart.getY()==groundheight){
	    plafond=false;
	  }
	}
      }
      if(uTurn){
	FMenu.EtatDuMenu(Button,heart);//ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
	pauseMessage.setPosition({50.f,50.f});
	pauseMessage.setCharacterSize(20);
	if(presse==0){
	  pauseMessage.setString("Vous etes a fight");
	  uTurn=false;
	  heart.setPosition({50.f,50.f});
	  FMenu.buttons[0].etat.left=0;
	  FMenu.buttons[0].sprite.setTextureRect(FMenu.buttons[0].etat);
	}
	else if(presse==1){
	  pauseMessage.setString("Vous etes a Act");
	}
	else if(presse==2){
	  pauseMessage.setString("Vous etes a item");
	}
	else if(presse==3){
	  pauseMessage.setString("Vous etes a mercy");
	}
      }
      window.clear(Color(Color::Black));
      //cout<<"uTurn ="<<uTurn<<endl;
      window.draw(pauseMessage);
      sanscorps.drawTo(window);
      sanstete.drawTo(window);
      FMenu.drawTo(window,heart);
      //cout<<heart.getX()<<endl;
    }
    window.display();
  }
  return EXIT_FAILURE;
  
}

