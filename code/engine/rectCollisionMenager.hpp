#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class RectCollisionMenager
{
    public:
        RectCollisionMenager();
        ~RectCollisionMenager();

        void add (sf::RectangleShape* rect);
        void del (sf::RectangleShape* rect);

        std::vector <sf::RectangleShape*>  all;


};

