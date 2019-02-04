#include "gui.hpp"
#include "../engine/engineData.hpp"
#include "gameScene.hpp"



Gui::Gui()
{
    view = EngineData::get().window.getDefaultView();
}
Gui::~Gui()
{

}

void Gui::onStart()
{
    float health = dynamic_cast <GameScene*> (EngineData::get().getScene())->player.health;
    healtBar.setPosition(sf::Vector2f(20,20));
    healtBar.setSize(sf::Vector2f(health * 2 ,40));
    healtBar.setFillColor(sf::Color(255,0,0));
    healtBar.setOutlineColor(sf::Color(255,255,255));
    healtBar.setOutlineThickness(4.f);

    point.setFont(EngineData::get().font);
    point.setColor(sf::Color::Yellow);
    point.setPosition(sf::Vector2f(EngineData::get().window.getSize().x - 60, 10));
    point.setCharacterSize(40);

    skill1.setTexture(EngineData::get().textures.get("gui"));
    skill1.setTextureRect(sf::IntRect(0,0 , 64 ,64));
    skill1.setPosition(sf::Vector2f(16,64));
    skill1.setSize(sf::Vector2f(64,64));

    skill1use.setTextureRect(sf::IntRect(0,0 , 64 ,64));
    skill1use.setPosition(sf::Vector2f(18,66));
    skill1use.setSize(sf::Vector2f(60,60));
    skill1use.setFillColor(sf::Color(255,0,0,80));

    skill2.setTexture(EngineData::get().textures.get("gui"));
    skill2.setTextureRect(sf::IntRect(64,0 , 64 ,64));
    skill2.setPosition(sf::Vector2f(84,64));
    skill2.setSize(sf::Vector2f(64,64));

    skill2use.setTextureRect(sf::IntRect(64,0 , 64 ,64));
    skill2use.setPosition(sf::Vector2f(86,66));
    skill2use.setSize(sf::Vector2f(60,60));
    skill2use.setFillColor(sf::Color(255,0,0,80));

}

void Gui::update()
{
    float health = dynamic_cast <GameScene*> (EngineData::get().getScene())->player.health;
    if(health > 0)
        healtBar.setSize(sf::Vector2f(health * 2 ,30));
    else healtBar.setSize(sf::Vector2f(0.1f ,30));
    if(health > 80) healtBar.setFillColor(sf::Color::Green);
    else if(health > 40) healtBar.setFillColor(sf::Color::Yellow);
    else healtBar.setFillColor(sf::Color(255,0,0));

    skill1use.setSize(sf::Vector2f(( ( 60 / dynamic_cast <GameScene*> (EngineData::get().getScene())->player.relode1 ))
      *  dynamic_cast <GameScene*> (EngineData::get().getScene())->player.actualRelode1, 60) );
   skill2use.setSize(sf::Vector2f(( ( 60 / dynamic_cast <GameScene*> (EngineData::get().getScene())->player.relode2 ))
      *  dynamic_cast <GameScene*> (EngineData::get().getScene())->player.actualRelode2, 60) );
}

void Gui::draw()
{
    EngineData::get().window.setView(view);
    EngineData::get().window.draw(healtBar);
    EngineData::get().window.draw(skill1);
    EngineData::get().window.draw(skill2);
    EngineData::get().window.draw(skill1use);
    EngineData::get().window.draw(skill2use);
    EngineData::get().window.draw(point);
}
