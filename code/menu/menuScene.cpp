#include "menuScene.hpp"
#include "../engine/engineData.hpp"
#include "../engine/engine.hpp"
#include <iostream>
#include "../game/gameScene.hpp"

MenuScene::MenuScene()
{
    EngineData::get().textures.load("help");
}

MenuScene::~MenuScene()
{
    EngineData::get().textures.unload("help");
}

void MenuScene::onStart()
{
    score.setFont(EngineData::get().font);
    score.setColor(sf::Color::White);
    score.setPosition(sf::Vector2f(7, 35));
    score.setCharacterSize(50);
    score.setString("Your Score:  14" );

    autor.setFont(EngineData::get().font);
    autor.setColor(sf::Color(100,100,100));
    autor.setPosition(sf::Vector2f(10, 10));
    autor.setCharacterSize(20);
    autor.setString("By Qikcik(Querk) on LD40 , using font Arial" );

    s.setTexture(*EngineData::get().textures.get("help"));
    s.setOrigin(sf::Vector2f(256,256));
    s.setPosition(sf::Vector2f( EngineData::get().window.getSize().x /2 ,EngineData::get().window.getSize().y /2 ));
}

void MenuScene::onEvent()
{

}

void MenuScene::onUpdate()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        EngineData::get().setScene( new GameScene() );
}

void MenuScene::onDraw()
{
    EngineData::get().window.draw(s);
    EngineData::get().window.draw(score);
    EngineData::get().window.draw(autor);
}
