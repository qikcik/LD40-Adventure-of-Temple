#pragma once

#include "wall.hpp"

class Map
{
    public:
        Map();
        ~Map();

        void onStart();
        void draw();
        void update();

        std::vector <Structure*>  all;
    private:
        int sizeX = 10;
        int sizeY = 10 ;
        std::map < int , std::map < int ,char  >  > world;
        void generate();

};
