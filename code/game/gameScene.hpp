#pragma once

#include "../engine/scene.hpp"
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "enemy.hpp"
#include "../engine/rectCollisionMenager.hpp"
#include "wall.hpp"
#include "map.hpp"
#include "enemyManager.hpp"
#include "gui.hpp"

class GameScene :public Scene
{
    public:
        GameScene(int lvl = 0);
        ~GameScene();
        virtual void onStart();

        virtual void onEvent();
        virtual void onUpdate();
        virtual void onDraw();

        int myLvl;
        int MapSize;
        double PlayerDamage;
        double PlayerStune;
        double PlayerReload;
        double EnemyAmmount;
        double EnemyDemage;
        double EnemyReload;
        double EnemyLife;



        Gui gui;

        RectCollisionMenager colision;
        sf::View mainView;

        EnemyManager enemy;

        Player player;
        Map world;
};
