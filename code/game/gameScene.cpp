#include "gameScene.hpp"
#include "../engine/engineData.hpp"
#include "../engine/engine.hpp"
#include <iostream>
#include <string>

GameScene::GameScene(int lvl) :player()
{
   EngineData::get().window.setTitle("LD40");
   mainView = EngineData::get().window.getDefaultView();
   myLvl = lvl;
   if( lvl < 10)
        gui.point.setString("  " + std::to_string(lvl));
    else gui.point.setString(std::to_string(lvl));

    MapSize = 8;
    PlayerDamage = 25;
    PlayerStune = 5;
    PlayerReload = 1.f;
    EnemyAmmount = 2;
    EnemyDemage = 10;
    EnemyReload= 5.f;
    EnemyLife = 50;

    if(lvl > 2)
    {
        MapSize = 8;
        PlayerDamage = 25;
        PlayerStune = 5;
        PlayerReload = 1.f;
        EnemyAmmount = 4;
        EnemyDemage = 20;
        EnemyReload= 2.f;
        EnemyLife = 60;
    }
    if(lvl > 4)
    {
        MapSize = 8;
        PlayerDamage = 25;
        PlayerStune = 5;
        PlayerReload = 1.5;
        EnemyAmmount = 6;
        EnemyDemage = 25;
        EnemyReload= 2.f;
        EnemyLife = 70;
    }
    if(lvl > 7)
    {
        MapSize = 10;
        PlayerDamage = 25;
        PlayerStune = 6;
        PlayerReload = 2.f;
        EnemyAmmount = 7;
        EnemyDemage = 25;
        EnemyReload= 1.5f;
        EnemyLife = 100;
    }
    if(lvl > 12)
    {
        MapSize = 15;
        PlayerDamage = 30;
        PlayerStune = 6.5;
        PlayerReload = 2.25f;
        EnemyAmmount = 11;
        EnemyDemage = 25;
        EnemyReload= 1.f;
        EnemyLife = 110;
    }
    if(lvl > 15)
    {
        MapSize = 15;
        PlayerDamage = 30;
        PlayerStune = 6.5;
        PlayerReload = 2.25f;
        EnemyAmmount = 13;
        EnemyDemage = 40;
        EnemyReload= 0.5f;
        EnemyLife = 125;
    }
    if(lvl > 25)
    {
        MapSize = 15;
        PlayerDamage = 40;
        PlayerStune = 6.5;
        PlayerReload = 2.75f;
        EnemyAmmount = 13;
        EnemyDemage = 45;
        EnemyReload= 0.3f;
        EnemyLife = 150;
    }
    if(lvl > 20)
    {
        MapSize = 20;
        PlayerDamage = 40;
        PlayerStune = 7.6;
        PlayerReload = 3.f;
        EnemyAmmount = 18;
        EnemyDemage = 45;
        EnemyReload= 0.3f;
        EnemyLife = 150;
    }
    if(lvl > 25)
    {
        MapSize = 20;
        PlayerDamage = 50;
        PlayerStune = 8.f;
        PlayerReload = 3.f;
        EnemyAmmount = 25;
        EnemyDemage = 45;
        EnemyReload= 0.3f;
        EnemyLife = 150;
    }
    if(lvl > 30)
    {
        MapSize = 25;
        PlayerDamage = 60;
        PlayerStune = 9.f;
        PlayerReload = 2.5f;
        EnemyAmmount = 32;
        EnemyDemage = 45;
        EnemyReload= 0.3f;
        EnemyLife = 150;
    }
    if(lvl > 40)
    {
        MapSize = 25;
        PlayerDamage = 65;
        PlayerStune = 9.f;
        PlayerReload = 2.5f;
        EnemyAmmount = 42;
        EnemyDemage = 50;
        EnemyReload= 0.3f;
        EnemyLife = 200;
    }
    if(lvl > 50)
    {
        MapSize = 30;
        PlayerDamage = 65;
        PlayerStune = 9.f;
        PlayerReload = 2.5f;
        EnemyAmmount = 42;
        EnemyDemage = 50;
        EnemyReload= 0.3f;
        EnemyLife = 200;
    }
}

GameScene::~GameScene()
{
    EngineData::get().textures.unload("basicEnemy2");
    EngineData::get().textures.unload("player");
    EngineData::get().textures.unload("structure");
    EngineData::get().textures.unload("gui");
}

void GameScene::onStart()
{
    EngineData::get().textures.load("player");
    EngineData::get().textures.load("structure");
    EngineData::get().textures.load("basicEnemy2");
    EngineData::get().textures.load("gui");

    world.onStart();
    enemy.onStart();
    player.onStart();
    gui.onStart();
}

void GameScene::onEvent()
{

}

void GameScene::onUpdate()
{
    gui.update();
    world.update();
    enemy.onUpdate();
    player.update();
}

void GameScene::onDraw()
{
    EngineData::get().window.setView(mainView);
    world.draw();
    enemy.onDraw();
    //player.draw();
    //for( auto n: colision.all)
     // EngineData::get().window.draw(*n);
     gui.draw();
}
