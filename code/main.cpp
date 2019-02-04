#include <iostream>
#include <SFML/Graphics.hpp>

#include <cstdlib>
#include <random>


#include "engine/engine.hpp"
#include "engine/engineData.hpp"
#include "game/gameScene.hpp"
#include "menu/menuScene.hpp"



int main()
{


    srand( time( NULL ) );
    Engine engine;
    int x , y;
    std::cout << "Width, Height: " ;
    std::cin >> x >> y;

    EngineData::get().window.create(sf::VideoMode(x, y) , "Adventure in temple");
    EngineData::get().setScene(new MenuScene);
    engine.run();
}
