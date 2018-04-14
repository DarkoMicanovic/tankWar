#include<SFML/Graphics.hpp>
#include "Menu.h"
#include<iostream>
using namespace sf ;

int main () {
    
    

    sf::RenderWindow window(VideoMode(600 , 400), "Tenkici");
     Menu menu(600 , 400);

    //sf::ConvexShape convex ;
    //convex.setPointCount(10);
    //convex.setPoint(0, sf::Vector2f(0, 500));
    //convex.setPoint(1, sf::Vector2f(900, 500));
    //convex.setPoint(2, sf::Vector2f(900, 400));
    //convex.setPoint(3, sf::Vector2f(850, 450));
    //convex.setPoint(4, sf::Vector2f( 750, 350));
    //convex.setPoint(5, sf::Vector2f( 700, 375));
    //convex.setPoint(6, sf::Vector2f( 650, 346));
    //convex.setPoint(7, sf::Vector2f( 600, 300));
    //convex.setPoint(8, sf::Vector2f( 500, 300));
    //convex.setPoint(9, sf::Vector2f( 0, 350));
    //app.setFramerateLimit(30);
    //convex.setFillColor(sf::Color::Green) ;
// define the color of the triangle's points
    menu.play();
    while(window.isOpen()){
        Event e ;
        while (window.pollEvent(e)){
            switch(e.type){
                case Event::Closed:
                    window.close();
            case sf::Event::KeyReleased:
                switch(e.key.code){
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break ;
                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break ;
                    case sf::Keyboard::Right:
                        menu.MoveRight();
                        break ;
                    case sf::Keyboard::Left:
                        menu.MoveLeft();
                        break ;
                    case sf::Keyboard::Return:
                        switch(menu.GetPressedItem()){
                            case 0:
                                std::cout<<"Igrajmo";
                                menu.~Menu();
                                break ;
                            case 1: 
                                std::cout<<"Options";
                                break ;
                            case 2:
                                window.close();
                        }
                        break ;
                    }
            }
        }
        window.clear();
       
        menu.draw(window);
       

        window.display();
    }
    

    
    




    return 0 ;
}