#include "enemy.hpp"
#include "../engine/engineData.hpp"
#include "../engine/engine.hpp"
#include "gameScene.hpp"

Enemy::Enemy()
{
    actualAnimation = &animationWalking;
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

    hel.setPosition(sf::Vector2f(100,100));
    hel.setSize(sf::Vector2f(health,1));
    hel.setOrigin(sf::Vector2f(health /2 , 75));
    hel.setFillColor(sf::Color(255,0,0));
    hel.setOutlineColor(sf::Color(255,255,255));
    hel.setOutlineThickness(2.f);



    // AnimationWalking
    animationWalking.speed = 1.f / 5;
    animationWalking.repead = true;
    animationWalking.addFrame(sf::IntRect(0,0,128,128));
    animationWalking.addFrame(sf::IntRect(128,0,128,128));
    animationWalking.addFrame(sf::IntRect(256,0,128,128));
    animationWalking.addFrame(sf::IntRect(385,0,128,128));
    animationWalking.addFrame(sf::IntRect(0,128,128,128));



    //animationAttack
    animationAttack.speed = 1.f / 5;
    animationAttack.addFrame(sf::IntRect(128,128,128,128));
    animationAttack.addFrame(sf::IntRect(256,128,128,128));
    animationAttack.addFrame(sf::IntRect(384,128,128,128));

    //animationDeath
    animationDeath.speed = 1.f / 5;
    animationDeath.addFrame(sf::IntRect(0,256,128,128));
    animationDeath.addFrame(sf::IntRect(128,256,128,128));
    animationDeath.addFrame(sf::IntRect(256,256,128,128));
    animationDeath.addFrame(sf::IntRect(385,256,128,128));
}

void Enemy::onStart()
{
    dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.add(&collision);
    sprite.setTexture(*EngineData::get().textures.get("basicEnemy2"));

        float health = dynamic_cast <GameScene*> (EngineData::get().getScene())->EnemyLife;
        float damage = dynamic_cast <GameScene*> (EngineData::get().getScene())->EnemyDemage;
        double reload = dynamic_cast <GameScene*> (EngineData::get().getScene())->EnemyReload;
}

Enemy::~Enemy()
{

}

void Enemy::update()
{
    if(health < 0)
        {actualAnimation = &animationDeath; death = true; stun = 0;}

    stun -= EngineData::get().deltaTime;
    if(stun < 0) stun = 0;

     if( stun ==  0)
     {
            actualReload -= EngineData::get().deltaTime;
            if(actualReload < 0) actualReload = 0;

            if(actualAnimation->repead == true || actualAnimation->isEnd == true )
            {
                if( actualReload  == 0 && attackbox.getGlobalBounds().intersects(
                    dynamic_cast <GameScene*> (EngineData::get().getScene())->player.hitbox.getGlobalBounds() ) )
                {
                    actualAnimation = &animationAttack;
                    actualReload= reload;
                }
            }

            if(actualAnimation == &animationAttack)
            {
                if( attackbox.getGlobalBounds().intersects(
                    dynamic_cast <GameScene*> (EngineData::get().getScene())->player.hitbox.getGlobalBounds() ) )
                {
                    if(dynamic_cast <GameScene*> (EngineData::get().getScene())->player.actualAnimation != &(
                        dynamic_cast <GameScene*> (EngineData::get().getScene())->player.animationFliping) )
                        dynamic_cast <GameScene*> (EngineData::get().getScene())->player.health -= damage * EngineData::get().deltaTime;
                }
            }


        sf::Vector2f mv;
        mv = dynamic_cast <GameScene*> (EngineData::get().getScene())->player.collision.getPosition();
        mv -= collision.getPosition();
        mv = Engine::normalize(mv);

        displayHealth -= EngineData::get().deltaTime;

         if(isEscape)
         {
            speed = 250;
            mv = -Engine::normalize(mv);
            escape += EngineData::get().deltaTime;
            if(escape > 0.75f)
            {
                escape = 0;
                isEscape = false;
                speed = 100;
            }
         }


        sf::Vector2f vec = sf::Vector2f(0,mv.y);
        move(vec);
        for(int i =0 ; i != dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all.size() ;i++ )
        {
            if(dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all[i] != &collision)
            {
                if(collision.getGlobalBounds().intersects(
                    dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all[i]->getGlobalBounds() ) )
                            {
                            if(dynamic_cast <GameScene*> (EngineData::get().getScene())->player.collision.getGlobalBounds().intersects(
                                 collision.getGlobalBounds() ) )
                                        {isEscape = true;   }
                            move(- vec) ;
                            }
            }
        }

        vec = sf::Vector2f(mv.x,0);
        move(vec);
        for(int i =0 ; i != dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all.size() ;i++ )
        {
            if(dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all[i] != &collision)
            {
                if(collision.getGlobalBounds().intersects(
                    dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all[i]->getGlobalBounds() ) )
                            {
                           if(dynamic_cast <GameScene*> (EngineData::get().getScene())->player.collision.getGlobalBounds().intersects(
                                collision.getGlobalBounds() ) )
                                        {isEscape = true;  }
                            move(- vec) ;
                            }
            }
        }
    }
    else actualAnimation = &animationWalking;

    hel.setSize(sf::Vector2f(health,10));
    hel.setOrigin(sf::Vector2f(health /2 , 75));

    if(stun == 0)
    {
        if(actualAnimation->isEnd == true )
            { actualAnimation->reset() ; actualAnimation= &animationWalking; }

        actualAnimation->update();
        sprite.setTextureRect(actualAnimation->get());
    }

    if(actualAnimation == &animationDeath && actualAnimation->isEnd == true)
    {
        dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.del(&collision);
        dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.del(this);
    }

}

void Enemy::setPosition(sf::Vector2f vec)
{
    sprite.setPosition(vec);
    collision.setPosition(vec);
    hitbox.setPosition(vec);
    attackbox.setPosition(vec);
    hel.setPosition(vec);
}


void Enemy::move(sf::Vector2f vec)
{
    vec = vec * float(speed);

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


void Enemy::draw()
{
    EngineData::get().window.draw(sprite);
    //EngineData::get().window.draw(collision);
    //EngineData::get().window.draw(hitbox);
    //EngineData::get().window.draw(attackbox);
    if(displayHealth > 0.f && !death)
        EngineData::get().window.draw(hel);
}


