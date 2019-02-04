#pragma once

#include "SFML/Graphics.hpp"
#include "../engine/animation.hpp"


class Enemy
{
    public:
        Enemy();
        ~Enemy();

        void onStart();
        void update();
        void draw();

        double speed = 80;
        bool isEscape = false;
        double escape = 0;

        float health = 80;
        float displayHealth = 0;
        bool death = false;
        float damage = 25;

        float stun = 0;

        double reload = 3;
        double actualReload = 0;

        void setPosition(sf::Vector2f vec);
        void move(sf::Vector2f vec);

        sf::RectangleShape collision;
        sf::RectangleShape hitbox;
        sf::RectangleShape attackbox;
        sf::RectangleShape hel;

    private:
        sf::Sprite sprite;

        Animation* actualAnimation;

        Animation animationWalking;
        Animation animationAttack;
        Animation animationDeath;

        enum { Left, Right } flip;

};
