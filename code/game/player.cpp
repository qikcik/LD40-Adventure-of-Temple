#include "player.hpp"
#include "../engine/engineData.hpp"
#include "../menu/menuScene.hpp"
#include "gameScene.hpp"

Player::Player()
{

    actualMovement = &animationStay;
    actualAnimation = &animationStay;
    flip = Right;
    sprite.setPosition(sf::Vector2f(100,100));
    sprite.setOrigin(sf::Vector2f(64,64));

    collision.setPosition(sf::Vector2f(100,100));
    collision.setOrigin(sf::Vector2f(24,-32));
    collision.setSize(sf::Vector2f(48,32));
    collision.setFillColor(sf::Color(255,0,0,150));

    hitbox.setPosition(sf::Vector2f(100,100));
    hitbox.setOrigin(sf::Vector2f(24,50));
    hitbox.setSize(sf::Vector2f(48,110));
    hitbox.setFillColor(sf::Color(125,0,0,60));



    attackbox.setPosition(sf::Vector2f(100,100));
    attackbox.setOrigin(sf::Vector2f(-24,50));
    //attackbox.setOrigin(sf::Vector2f(72,50));
    attackbox.setSize(sf::Vector2f(48,110));
    attackbox.setFillColor(sf::Color(0,128,0,60));


    // AnimationStay
    animationStay.speed = 1.f/ 3;
    animationStay.repead = true;
    animationStay.addFrame(sf::IntRect(0,0,128,128));
    animationStay.addFrame(sf::IntRect(128,0,128,128));
    // AnimationWalking
    animationWalking.speed = 1.f / 7;
    animationWalking.repead = true;
    animationWalking.addFrame(sf::IntRect(256,0,128,128));
    animationWalking.addFrame(sf::IntRect(384,0,128,128));
    animationWalking.addFrame(sf::IntRect(512,0,128,128));
    animationWalking.addFrame(sf::IntRect(640,0,128,128));
    animationWalking.addFrame(sf::IntRect(0,128,128,128));

    //animationFliping
    animationFliping.speed = 1.f / 15;
    animationFliping.addFrame(sf::IntRect(128,128,128,128));
    animationFliping.addFrame(sf::IntRect(256,128,128,128));
    animationFliping.addFrame(sf::IntRect(384,128,128,128));
    animationFliping.addFrame(sf::IntRect(512,128,128,128));
    animationFliping.addFrame(sf::IntRect(640,128,128,128));

    //animationSpeedAttack
    animationSpeedAttack.speed = 1.f / 11;
    animationSpeedAttack.addFrame(sf::IntRect(0,256,128,128));
    animationSpeedAttack.addFrame(sf::IntRect(128,256,128,128));
    animationSpeedAttack.addFrame(sf::IntRect(256,256,128,128));

    //animationAttack
    animationAttack.speed = 1.f / 11;
    animationAttack.addFrame(sf::IntRect(384,256,128,128));
    animationAttack.addFrame(sf::IntRect(512,256,128,128));
    animationAttack.addFrame(sf::IntRect(640,256,128,128));
    animationAttack.addFrame(sf::IntRect(0,384,128,128));
    animationAttack.addFrame(sf::IntRect(128,384,128,128));
    animationAttack.addFrame(sf::IntRect(256,384,128,128));

    //animationDeath
    animationDeath.speed = 1.f / 5;
    animationDeath.addFrame(sf::IntRect(384,384,128,128));
    animationDeath.addFrame(sf::IntRect(512,384,128,128));
    animationDeath.addFrame(sf::IntRect(640,384,128,128));
    animationDeath.addFrame(sf::IntRect(0,512,128,128));
    animationDeath.addFrame(sf::IntRect(128,512,128,128));
    animationDeath.addFrame(sf::IntRect(256,512,128,128));
    animationDeath.addFrame(sf::IntRect(384,512,128,128));
}

void Player::onStart()
{
    dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.add(&collision);
    sprite.setTexture(*EngineData::get().textures.get("player"));

    double myDamage = dynamic_cast <GameScene*> (EngineData::get().getScene())->PlayerDamage;
    double myDamage2 = dynamic_cast <GameScene*> (EngineData::get().getScene())->PlayerDamage /10.f;
     double myStun = dynamic_cast <GameScene*> (EngineData::get().getScene())->PlayerStune;
    double relode2 = dynamic_cast <GameScene*> (EngineData::get().getScene())->PlayerReload;
}

Player::~Player()
{

}

void Player::update()
{
        //std::cout <<  health<<" \n";

    if(health < 0)
        actualAnimation = &animationDeath;

    /// skill

    actualRelode1 -= EngineData::get().deltaTime;
        if(actualRelode1  < 0) actualRelode1  = 0;
    actualRelode2 -= EngineData::get().deltaTime;
        if(actualRelode2  < 0) actualRelode2  = 0;


    if(actualAnimation->repead == true || actualAnimation->isEnd == true )
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)  && actualRelode2  == 0 )
            {actualAnimation= &animationAttack; actualRelode2 = relode2;}
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && actualRelode1  == 0  )
            {actualAnimation= &animationSpeedAttack; actualRelode1 = relode1;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {actualAnimation= &animationFliping;  speed = 199;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            actualAnimation= &animationDeath;
    }

    if(actualAnimation== &animationSpeedAttack)
    {
        for(int i =0 ; i != dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all.size() ;i++ )
        {
            if(&dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all[i]->hitbox != &hitbox)
            {
                if(dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all[i]->hitbox.getGlobalBounds().intersects(
                    attackbox.getGlobalBounds() ) )
                    {
                        dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all[i]->health -= myDamage * EngineData::get().deltaTime;
                        dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all[i]->displayHealth = 2;
                    }
            }
        }
    }

    if(actualAnimation== &animationAttack)
    {
        for(int i =0 ; i != dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all.size() ;i++ )
        {
            if(&dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all[i]->hitbox != &hitbox)
            {
                if(dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all[i]->hitbox.getGlobalBounds().intersects(
                    attackbox.getGlobalBounds() ) )
                    {
                        dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all[i]->stun += myStun * EngineData::get().deltaTime;
                        dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all[i]->health -= myDamage2 * EngineData::get().deltaTime;
                        dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all[i]->displayHealth = 2;
                    }
            }
        }
    }

    /// movement up-down
    sf::Vector2f vec = sf::Vector2f(0,0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        vec += sf::Vector2f(0,-1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        vec += sf::Vector2f(0,1);

    move(vec);

    for(int i =0 ; i != dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all.size() ;i++ )
    {
        if(dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all[i] != &collision)
        {
            if(dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all[i]->getGlobalBounds().intersects(
                collision.getGlobalBounds() ) )
                    move(-vec);
        }
    }

    /// movement right-left
    vec = sf::Vector2f(0,0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        vec += sf::Vector2f(1,0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        vec += sf::Vector2f(-1,0);

    move(vec);

    for(int i =0 ; i != dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all.size() ;i++ )
    {
        if(dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all[i] != &collision)
        {
            if(dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all[i]->getGlobalBounds().intersects(
                collision.getGlobalBounds() ) )
                    move(-vec);
        }
    }




    ///animation

    if(actualAnimation->isEnd == true )
        { actualAnimation->reset() ; actualAnimation= actualMovement; speed = 128; }

    if(actualAnimation->repead == true )
        { actualAnimation= actualMovement; }

    actualAnimation->update();
    sprite.setTextureRect(actualAnimation->get());

    dynamic_cast <GameScene*> (EngineData::get().getScene())->mainView.setCenter(hitbox.getPosition());

    if( /*actualAnimation == &animationDeath && actualAnimation->isEnd == true) */ dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all.size() == 0 )
    {
        int lvl = dynamic_cast <GameScene*> (EngineData::get().getScene())->myLvl + 1;
        EngineData::get().setScene (new GameScene( lvl ));
    }

    if( actualAnimation == &animationDeath && actualAnimation->isEnd == true)
    {
        EngineData::get().setScene (new MenuScene( ));
    }

}

void Player::setPosition(sf::Vector2f vec)
{
    sprite.setPosition(vec);
    collision.setPosition(vec);
    hitbox.setPosition(vec);
    attackbox.setPosition(vec);
}

void Player::move(sf::Vector2f vec)
{
    vec = vec * float(speed);
    if(vec.x != 0||vec.y != 0)
       actualMovement = &animationWalking;
    else  actualMovement = &animationStay;

    if( (vec.x > 0 && flip == Left) )
    {
        sprite.scale(-1.f,1.f);
        attackbox.setOrigin(sf::Vector2f(-24,50));
        flip = Right;
    }
    if( vec.x < 0 && flip == Right )
    {
        sprite.scale(-1.f,1.f);
        attackbox.setOrigin(sf::Vector2f(72,50));
        flip = Left;
    }

    setPosition(sprite.getPosition() + vec * float(EngineData::get().deltaTime));
}


void Player::draw()
{
    EngineData::get().window.draw(sprite);
    //EngineData::get().window.draw(collision);
    //EngineData::get().window.draw(hitbox);
    //EngineData::get().window.draw(attackbox);
}

