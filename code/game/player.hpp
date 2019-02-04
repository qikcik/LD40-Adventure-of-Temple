#pragma once

#include "SFML/Graphics.hpp"
#include "../engine/animation.hpp"

class Player
{
    public:
        Player();
        ~Player();

        void onStart();
        void update();
        void draw();

        double speed = 140;
        double health = 100;

        double myDamage = 60;
        double myDamage2 = 5;
         double myStun = 5;
         double actualRelode1 =0;
         double actualRelode2 =0;
        double relode1 =  0.3f;
        double relode2 = 1.5f;


        void setPosition(sf::Vector2f vec);
        void move(sf::Vector2f vec);

        sf::RectangleShape collision;
        sf::RectangleShape hitbox;
        sf::RectangleShape attackbox;

        sf::Sprite sprite;
        Animation* actualAnimation;
        Animation* actualMovement;

        Animation animationStay;
        Animation animationWalking;
        Animation animationFliping;
        Animation animationSpeedAttack;
        Animation animationAttack;
        Animation animationDeath;

        enum { Left, Right } flip;
};
