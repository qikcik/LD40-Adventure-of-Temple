#include "engine.hpp"
#include "engineData.hpp"
#include "scene.hpp"
#include <iostream>

Engine::Engine()
{
    // BLANK
}

Engine::~Engine()
{
    // BLANK
}

void Engine::run()
{
    sf::RenderWindow &window = EngineData::get().window;
    sf::Event &event = EngineData::get().event;
    EngineData::get().getScene();
    double last = 0;

    while( window.isOpen() )
    {
        EngineData::get().deltaTime = clock.restart().asSeconds();
        last = (EngineData::get().deltaTime + last) / 2;
        //std::cout <<  1.f / last << " \n";

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

                EngineData::get().getScene()->onEvent();
        }

        EngineData::get().getScene()->onUpdate();

        window.clear(sf::Color(77, 77, 77));
                EngineData::get().getScene()->onDraw();
        window.display();
    }
}

sf::Vector2f Engine::normalize(const sf::Vector2f& source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return sf::Vector2f(source.x / length, source.y / length);
    else
        return source;
}



