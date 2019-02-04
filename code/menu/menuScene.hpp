#pragma once

#include "../engine/scene.hpp"
#include <SFML/Graphics.hpp>


class MenuScene :public Scene
{
    public:
        MenuScene();
        ~MenuScene();
        virtual void onStart();

        virtual void onEvent();
        virtual void onUpdate();
        virtual void onDraw();

        sf::Text score;
        sf::Text autor;

        sf::Sprite s;
};
