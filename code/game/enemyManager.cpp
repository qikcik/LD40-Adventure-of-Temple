#include "enemyManager.hpp"
#include "gameScene.hpp"
#include "../engine/engineData.hpp"

EnemyManager::EnemyManager()
{

}

EnemyManager::~EnemyManager()
{
    for (int i = 0; i < all.size(); i++)
    {
        delete all[i];
    }

    all.clear();
}

void EnemyManager::add(Enemy* enemy)
{
    all.push_back(enemy);
    all.back()->onStart();
}

void EnemyManager::del(Enemy* enemy)
{
    for (int i = 0; i < all.size(); i++)
    {
        if( all[i] == enemy )
        {
            delete all[i] ;
            all.erase(all.begin() + i);
            break;
        }
    }
}

void EnemyManager::onStart()
{

}
void EnemyManager::onUpdate()
{
    for( auto i : all)
        i->update();

    std::sort(all.begin(), all.end(), [](const Enemy* lhs, const Enemy* rhs){ return lhs->collision.getPosition().y < rhs->collision.getPosition().y; });
}

void EnemyManager::onDraw()
{
    float lastY = 0;
    bool draw = false;
    for( auto i : all)
    {
        if((i->collision.getPosition().y > dynamic_cast <GameScene*> (EngineData::get().getScene())->player.collision.getPosition().y  &&
            i->collision.getPosition().y >lastY && !draw) || !draw && i  == all.back( ))
                {  dynamic_cast <GameScene*> (EngineData::get().getScene())->player.draw(); draw = true; }
        i->draw();
        lastY = i->collision.getPosition().y ;
    }

}

