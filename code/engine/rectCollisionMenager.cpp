#include "rectCollisionMenager.hpp"

RectCollisionMenager::RectCollisionMenager()
{

}

RectCollisionMenager::~RectCollisionMenager()
{

}

void RectCollisionMenager::add(sf::RectangleShape* rect)
{
    all.push_back(rect);
}

void RectCollisionMenager::del(sf::RectangleShape* rect)
{
    for (int i = 0; i < all.size(); i++)
    {
        if( all[i] == rect )
        {
            all.erase(all.begin() + i);
            break;
        }
    }
}
