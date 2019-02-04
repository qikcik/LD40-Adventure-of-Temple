#include "engineData.hpp"
#include "scene.hpp"


EngineData::EngineData()
:  textures()
{
    actual = nullptr;
    font.loadFromFile("data/graphics/arial.ttf");

}

EngineData::~EngineData()
{
    if(actual != nullptr)
        delete actual;
}

Scene* EngineData::getScene()
 {
    return actual;
 }

 void EngineData::setScene( Scene* New)
 {
    if(actual != nullptr)
        delete actual;
    actual = New;
    New->onStart();
 }
