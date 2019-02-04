#include "textureMenager.hpp"
#include <iostream>

TextureManager::TextureManager()
{
 //blank
}

TextureManager::~TextureManager()
{
    sf::Texture *texture;
    std::map<std::string, sf::Texture*>::iterator iter = textures.begin();
    while(iter != textures.end())
    {
        texture = iter->second;
        delete texture;
        iter++;
    }
}

sf::Texture* TextureManager::load(std::string name)
{
    sf::Texture *texture = new sf::Texture();

    if(get(name) == nullptr && texture->loadFromFile(TexturePrefix+name+TextureSubfix))
    {
        textures[name] = texture;
        std::cout << "load Texture [" << TexturePrefix+name+TextureSubfix<< "] \n";
        return textures[name];
    }
    else
    {
        delete texture;
        std::cout << "error witch load Texture [" << TexturePrefix+name+TextureSubfix<< "] \n";
        return nullptr;
    }
}

sf::Texture* TextureManager::get(std::string name)
{
    if(textures.find(name) != textures.end()){
        return textures[name];
    } else {
        return nullptr;
    }
}

void TextureManager::unload(std::string name)
{
    std::map<std::string, sf::Texture*>::iterator it = textures.find(name);
    if(it != textures.end()){
        textures.erase (it);

        std::cout << "unload Texture [" << TexturePrefix+name+TextureSubfix<< "] \n";
    }
}
