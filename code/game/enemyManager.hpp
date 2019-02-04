#pragma once

#include "enemy.hpp"
#include <vector>

class EnemyManager
{
    public:
        EnemyManager();
        ~EnemyManager();

        void add (Enemy* enemy);
        void del (Enemy* enemy);

        void onStart();
        void onUpdate();
        void onDraw();

        std::vector <Enemy*>  all;


};
