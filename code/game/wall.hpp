#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Structure
{
    public:
        Structure() = default;
        ~Structure()= default;

        virtual void onStart() {};
        virtual void draw() {} ;
        virtual void update() {} ;

        virtual void setPosition(sf::Vector2f vec)  {} ;

        sf::RectangleShape collision;
};

class Floor :public Structure
{
    public:
        Floor();
        ~Floor();

        void setPosition(sf::Vector2f vec);
        virtual void onStart();


        void draw();
};


class Wall :public Structure
{
    public:
        Wall( int type = 0 );
        ~Wall();

        void setPosition(sf::Vector2f vec);
        virtual void onStart();


        void draw();
};
