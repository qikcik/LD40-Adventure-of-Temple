#pragma once

#include <SFML/Graphics.hpp>
#include "textureMenager.hpp"

class Scene;

class EngineData
{

    /// CLASS
    public:
         sf::RenderWindow window;
         sf::Event event;
         double deltaTime;

         sf::Font font;

         TextureManager textures;

        Scene* getScene();

        void setScene( Scene* New);



        Scene* actual = nullptr;
     /// SINGLETON
        private:
            EngineData();
        public:
            ~EngineData();
            static EngineData& get() { static EngineData d; return d;}
};
