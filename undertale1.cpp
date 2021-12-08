#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "parole.h"
#include "sanstete.h"
#include "gb.h"
#include "sanscorps.h"
#include "menuItem.h"
#include "menustart.h"
#include "life.h"
using namespace std;
using namespace sf;


int main(){
  srand(static_cast<unsigned int>(time(NULL)));


  //teste de parole:
  parole test(20,"./Font/DTM-Sans.otf");
  
  //Boutton de combat:
  Button Fight("Sprite/Fight/fight.png");
  Button Items("Sprite/item/item.png");
  Button Act("Sprite/act/act.png");
  Button Mercy("Sprite/mercy/mercy.png");
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

  //Cadre de combat test:
  cadre cadre1;


  //constante nécessaire:
  int gameWidth = 800;
  int gameHeight = 700;
  Vector2f paddlesize(30,30);
  float deltaTime;
  RectangleShape rect({25,0});
  rect.setFillColor(Color::White);
  float rayon=0;

  //Gravity Constant:
  const int groundheight=490;
  const float gravityspeed=5;
  bool isJumping=false;
  
  //definition de la fenêtre:
  Image icon;
  if(!icon.loadFromFile("./Sprite/Sans/spr_sans_bface_5.png")){
    return EXIT_FAILURE;
  }
  RenderWindow window(VideoMode(gameWidth, gameHeight,32), "Undertale", Style::Titlebar |Style::Resize |Style::Close);
  window.setIcon(30,28,icon.getPixelsPtr());
  window.setVerticalSyncEnabled(true);

 
  //Definition des personnages:
  Player heart(92,99,99,2.5,"Sprite/heart/spr_heart_0.png");
  life lp_P;
  SansTete sanstete("Sprite/Sans/sans_head.png");
  SansCorps sanscorps("Sprite/Sans/sans_body.png");
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
  menustart Start;
  //menuItem:
  menuItem menu; 
  
  
  //Proprieties:
  Time AITime=seconds(0.1f);
  bool isPlaying=false;
  bool PlayButtonSelected=true;
  bool ExitButtonSelected=false;
  bool PlayButtonPressed=false;
  bool ExitButtonPressed=false;
  Text pauseMessage;
  bool ds_item=false;
  int presse=4;
  bool plafond=false;
  bool blue=true;
  int Button=0;
  //test de durée:
  Clock clock;
  Clock Timer;
  Clock combat;
  Clock appear;
  int yolo=0;
  while(window.isOpen()){
    Event event;
    if(isPlaying){
      if(!uTurn){
	if(combat.getElapsedTime().asSeconds()>10.f){
	  uTurn=true;
	  presse=4;
	  while (cadre1.rectcadre.left!=0){
	    cadre1.animationFinFight(Timer);
	  }
	}
	heart.movement(blue, isJumping, plafond,groundheight);
      }
      test.setPosition(50.f,200.f);
      test.setText("whalla bila",yolo, appear,0.09f);
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
	Start.etatmenu(PlayButtonSelected,ExitButtonSelected,PlayButtonPressed,ExitButtonPressed,event);
      }
      if(isPlaying){
	if(!uTurn){
	  heart.released(event,isJumping,groundheight);
	}
	if(uTurn){
	  if(!ds_item){
	    Button=FMenu.selectedButton(Button, heart.sprite,event,presse);
	  }
	  if(ds_item){
	    menu.selected(heart,event);
	  }
	}
      }
    }
    if(!isPlaying){
      Start.selected(window,PlayButtonPressed,ExitButtonPressed,isPlaying,PlayButtonSelected,ExitButtonSelected);
    }
    if(isPlaying){
      if(!uTurn){
	heart.gravity(event,groundheight,plafond,isJumping,blue);
      }
      if((uTurn)&&(!ds_item)){
	FMenu.EtatDuMenu(Button,heart);
	pauseMessage.setFont(lp_P.font);
	pauseMessage.setString("*You are going to have a \n very bad Time.");
	pauseMessage.setPosition({cadre1.spriteCadre.getPosition().x+20.f,cadre1.spriteCadre.getPosition().y+20.f});
	pauseMessage.setCharacterSize(40);
	if(presse==0){
	  combat.restart();
	  pauseMessage.setPosition({50.f,50.f});
	  pauseMessage.setString("");
	  uTurn=false;
	  cadre1.animationDebutFight(Timer,heart);
	  FMenu.buttons[0].etat.left=0;
	  FMenu.buttons[0].sprite.setTextureRect(FMenu.buttons[0].etat);
	}
	else if(presse==1){
	  pauseMessage.setPosition({50.f,50.f});
	  pauseMessage.setString("Vous etes a Act");
	}
	else if(presse==2){
	  pauseMessage.setPosition({50.f,50.f});
	  pauseMessage.setString("");
	  ds_item=true;
	  FMenu.buttons[2].etat.left=0;
	  FMenu.buttons[2].sprite.setTextureRect(FMenu.buttons[2].etat);
	  menu.drawTo(window, heart);
	}
	else if(presse==3){
	  pauseMessage.setPosition({50.f,50.f});
	  pauseMessage.setString("Vous etes a mercy");
	}
      }
      window.clear(Color(Color::Black));
      
      window.draw(pauseMessage);
      cadre1.drawTo(window);
      sanscorps.drawTo(window);
      sanstete.drawTo(window);
      FMenu.drawTo(window,heart);
      lp_P.drawTo(window);
      test.drawTo(window);
      if (presse==2){
	menu.drawTo(window,heart);
      }
      //cout<<heart.getX()<<endl;
    }
    window.display();
  }
  return EXIT_FAILURE;
  
}

