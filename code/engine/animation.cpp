#include "animation.hpp"
#include "engineData.hpp"


Animation::Animation()
{
    reset();
}

Animation::~Animation()
{

}

void Animation::addFrame(sf::IntRect frame)
{
    frames.push_back(frame);
}

void Animation::update()
{
    if(isEnd == true)
        return;
    lastTime += EngineData::get().deltaTime;
    if(lastTime > speed)
    {
        lastTime -= speed;
        actual++;
        if (repead == true && actual == frames.size())
            actual =0;
        else if (repead == false && actual == frames.size())
           {isEnd = true; actual == frames.size() -1; }

    }
}

void Animation::reset()
{
    actual = 0;
    lastTime =0;
    isEnd = false;
}

sf::IntRect Animation::get()
{
    return frames[actual];
}

