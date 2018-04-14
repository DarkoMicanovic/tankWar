#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#define MAX_NUMBER_OF_ITEMS 3
#define BrojPozadina 3
class Menu 
{
    public:
        Menu(float duzina , float sirina) ;
        ~Menu();
        void play() ;
        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        void MoveRight();
        void MoveLeft();
        int getTeren(){
            return izabraniTeren ;
        }
        void setTeren(int k){
            izabraniTeren = k ;
        }
        int GetPressedItem(){ return selectedItemIndex ;}
        sf::Sprite background ;
        sf::Texture texture ;
       
    private:
        int selectedItemIndex ;
        int izabraniTeren  ;
        sf::Font font ;
        sf::Text menu[MAX_NUMBER_OF_ITEMS] ;
        sf::SoundBuffer sb ;
        sf::Sound intro ; 
        
};