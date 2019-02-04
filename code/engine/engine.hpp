#pragma once

#include <SFML/Graphics.hpp>


class Engine
{
    public:
        Engine();
        ~Engine();
        void run();

        static sf::Vector2f normalize(const sf::Vector2f& source);

    private:
        sf::Clock clock;

};
