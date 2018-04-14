#include "Menu.h"
#include <iostream>

Menu::Menu(float duzina , float sirina){
    if(!font.loadFromFile("arial.ttf")){
        exit(-1);
    }
    
   
    
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(duzina/2 , sirina/(MAX_NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Trava");
    setTeren(0);
    
    menu[1].setPosition(sf::Vector2f(duzina/2 , sirina/(MAX_NUMBER_OF_ITEMS+1)*2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(duzina/2 , sirina/(MAX_NUMBER_OF_ITEMS+1)*3));




    selectedItemIndex = 0 ;

}

void Menu::draw(sf::RenderWindow &window){
     
    sf::Texture texture ;
    if(!texture.loadFromFile("ludiloRavnice.png")){
        exit(-1);
    } 
    sf::Sprite background ;
    background.setTexture(texture);
    window.draw(background);
    for(int i = 0 ; i < MAX_NUMBER_OF_ITEMS ; i++){
        
        window.draw(menu[i]);
        
        
        
        window.setFramerateLimit(30);
    }
    
}

Menu::~Menu(){
    
}

void Menu::MoveUp(){
    if(selectedItemIndex -1 >=0){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    } 
}


void Menu::play(){
    if(! sb.loadFromFile("Intro.wav")){
        exit(-1);
    }
    intro.setBuffer(sb);
    intro.setLoop(true);
    intro.play();


}

void Menu::MoveDown(){
    if(selectedItemIndex +1 <MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    } 
}

void Menu::MoveRight(){
    if(selectedItemIndex ==0 || selectedItemIndex == 2){
    }

    else {
        if(getTeren()==2){

        }
        else {
            if(getTeren()==0){
                menu[1].setString("Brda");
                setTeren(1);
            }

            if (getTeren()==1){
                menu[1].setString("Led");
                setTeren(2);
            }
        }
    }
}
void Menu::MoveLeft(){
    if(selectedItemIndex ==0 || selectedItemIndex == 2){
    }

    else {
        if(getTeren()==0){

        }
        else {
            if(getTeren()==1){
                menu[1].setString("Trava");
                setTeren(0);
            }

            if (getTeren()==2){
                menu[1].setString("Brda");
                setTeren(1);
            }
        }
    }
}
