#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
    public:
        Animation();
        ~Animation();

        double speed = 1.f;
        bool repead = false;
        bool isEnd = false;

        void addFrame(sf::IntRect frame);

        void update();
        void reset();

        sf::IntRect get();

    private:
        std::vector< sf::IntRect > frames;
        int actual =0;
        double lastTime = 0;
};
