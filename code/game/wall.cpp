#include "wall.hpp"
#include "../engine/engineData.hpp"
#include "gameScene.hpp"


Wall::Wall(int type )
{
    collision.setSize(sf::Vector2f(128,128));
    collision.setOrigin(sf::Vector2f(64,64));
    collision.setTextureRect(sf::IntRect( type  * 128,0,128,128));
}

void Wall::onStart()
{
    collision.setTexture(EngineData::get().textures.get("structure"));
    dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.add(&collision);
}



Wall::~Wall()
{

}

void Wall::setPosition(sf::Vector2f vec)
{
    collision.setPosition(vec);
}

void Wall::draw()
{
    EngineData::get().window.draw(collision);
}

Floor::Floor()
{
    //collision.setPosition(sf::Vector2f(500,500));

    collision.setSize(sf::Vector2f(128,128));
    collision.setOrigin(sf::Vector2f(64,64));
     collision.setTextureRect(sf::IntRect(0,0,128,128));
}


void Floor::setPosition(sf::Vector2f vec)
{
    collision.setPosition(vec);
}

void Floor::draw()
{
    EngineData::get().window.draw(collision);
}

void Floor::onStart()
{
    //dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.add(&collision);
    collision.setTexture(EngineData::get().textures.get("structure"));
}


