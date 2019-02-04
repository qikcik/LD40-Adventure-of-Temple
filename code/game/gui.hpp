#pragma once

#include "SFML/Graphics.hpp"


class Gui
{
    public:
        Gui();
        ~Gui();

        void onStart();
        void update();
        void draw();

        sf::View view;
        sf::RectangleShape healtBar;
        sf::RectangleShape skill1;
        sf::RectangleShape skill2;
        sf::RectangleShape skill1use;
        sf::RectangleShape skill2use;

        sf::Text point;

};
