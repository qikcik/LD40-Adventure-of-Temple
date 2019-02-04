#include "map.hpp"
#include <iostream>
#include "../engine/engineData.hpp"
#include "gameScene.hpp"


Map::Map()
{

}

Map::~Map()
{
    for(auto i : all)
        delete i;

    all.clear();

}

void Map::onStart()
{
    generate();

    while(true)
    {
        int posX = rand()%(sizeX);
        int posY = rand()%(sizeY);
        if(world[posX][posY] == ' ')
        {
            dynamic_cast <GameScene*> (EngineData::get().getScene())->player.setPosition(sf::Vector2f( (posX * 128), (posY * 128 )  ));
            break;
        }

        sizeX = sizeY = dynamic_cast <GameScene*> (EngineData::get().getScene())->MapSize;
    }
    int i = 0;
    int maxI = dynamic_cast <GameScene*> (EngineData::get().getScene())->EnemyAmmount;
    bool loop = true;
    while( loop )
    {
        int posX = rand()%(sizeX);
        int posY = rand()%(sizeY);
        if(world[posX][posY] == ' ')
        {
            Enemy *e = new Enemy();
            e->setPosition(sf::Vector2f( (posX * 128), (posY * 128 )  ));
            //dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.add(new Enemy() );
            //dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.all.back()->setPosition(sf::Vector2f( (posX * 128), (posY * 128 )  ));
            bool col = false;
            for(auto i : dynamic_cast <GameScene*> (EngineData::get().getScene())->colision.all )
            {
               if(i->getGlobalBounds().intersects(
                    e->collision.getGlobalBounds() ) )
                            {col= true;  }
            }
            if (dynamic_cast <GameScene*> (EngineData::get().getScene())->player.collision.getGlobalBounds().intersects(
                    e->collision.getGlobalBounds() ) )
                    {col= true;  }

            if(col == false)
            {
                i++;
                dynamic_cast <GameScene*> (EngineData::get().getScene())->enemy.add( e  );
            }
            if(i == maxI) {loop = false; }
        }
    }

        for(auto i : all)
        i->onStart();
}

void Map::draw()
{
    for(Structure* i : all)
        i->draw();

}

void Map::update()
{
    for(auto i : all)
        i->update();
}

void Map::generate()
{
    int roomAmmount =  6 ; // 0 : 1000;
    int roomMaxSize = 5; // 3 : (sizeX - 4)
    int correct = 1; // 0 : 2 // dziwnie działa-
    //char world[sizeX ][sizeY]= {'0'};

    ///clear
    for(int x=0 ; x < sizeX ; x++)
        for(int y = 0 ; y < sizeY ; y++)
            world[x][y] = '0';

    ///alghoritm

    int posX = rand()%(sizeX-4)+2;
    int posY = rand()%(sizeY-4)+2;
    world[posX-1][posY] = ' ';
    world[posX+1][posY] = ' ';
    world[posX][posY] = ' ';
    world[posX][posY-1] = ' ';
    world[posX][posY+1] = ' ';


    for( int i = 0 ; i != roomAmmount ; i++)
    {
        int RoomSizeX = rand()% (roomMaxSize) + correct;
        int RoomSizeY = rand()% (roomMaxSize) + correct;

        int posX = rand()%(sizeX-2 - RoomSizeX) +1;
        int posY = rand()%(sizeY-2 - RoomSizeY)+ 1;

        int connect = 0;

        for(int x = posX ; x!= posX + RoomSizeX ; x++ )
          for(int y = posY ; y!= posY + RoomSizeY ; y++)
                if(world[x][y] == ' ') connect++;

        if(connect > 0 && connect < roomMaxSize)
        {
        for(int x = posX ; x!= posX + RoomSizeX ; x++ )
            for(int y = posY ; y!= posY + RoomSizeY ; y++)
                if( world[x][y] != ' ') world[x][y] = ' ';
        }
        else i--;


    }

    for(int x=0 ; x < sizeX ; x++)
        for(int y = 0 ; y < sizeY ; y++)
        {
            if( (  ' ' == world[x-1][y]||
                    ' ' == world[x+1][y]  ||
                    ' '  == world[x][y-1] ||
                    ' '  == world[x][y+1] ||
                    ' '  == world[x-1][y-1] ||
                    ' '  == world[x-1][y+1] ||
                    ' '  == world[x+1][y+1] ||
                    ' '  == world[x+1][y-1] )&&  world[x][y] == '0')
                    world[x][y] = '#';
    }

        for(int x=sizeX ; x > 0 ; x--)
        for(int y = 0 ; y < sizeY ; y++)
        {
            if( (  ' ' == world[x-1][y]||
                    ' ' == world[x+1][y]  ||
                    ' '  == world[x][y-1] ||
                    ' '  == world[x][y+1] ||
                    ' '  == world[x-1][y-1] ||
                    ' '  == world[x-1][y+1] ||
                    ' '  == world[x+1][y+1] ||
                    ' '  == world[x+1][y-1] )&&  world[x][y] == '0')
                    world[x][y] = '#';
    }

        for(int x=sizeX  ; x >0 ; x--)
        for(int y = sizeY ; y > 0  ; y--)
        {
            if( (  ' ' == world[x-1][y]||
                    ' ' == world[x+1][y]  ||
                    ' '  == world[x][y-1] ||
                    ' '  == world[x][y+1] ||
                    ' '  == world[x-1][y-1] ||
                    ' '  == world[x-1][y+1] ||
                    ' '  == world[x+1][y+1] ||
                    ' '  == world[x+1][y-1] )&&  world[x][y] == '0')
                    world[x][y] = '#';
    }

        for(int x=0 ; x < sizeX ; x++)
        for(int y = sizeY ; y > 0; y--)
        {
            if( (  ' ' == world[x-1][y]||
                    ' ' == world[x+1][y]  ||
                    ' '  == world[x][y-1] ||
                    ' '  == world[x][y+1] ||
                    ' '  == world[x-1][y-1] ||
                    ' '  == world[x-1][y+1] ||
                    ' '  == world[x+1][y+1] ||
                    ' '  == world[x+1][y-1] )&&  world[x][y] == '0')
                    world[x][y] = '#';
    }

        for(int x=0 ; x < sizeX ; x++)
            for(int y = sizeY ; y > 0; y--)
            {
                if( world[x][y] == '0' && (
                (world[x-1][y] == '#' || world[x][y-1] == '#') ||
                (world[x+1][y] == '#' || world[x][y+1] == '#') ||
                (world[x+1][y] == '#' || world[x+1][y] == '#') ||
                (world[x][y+1] == '#' || world[x][y+1] == '#')
                ))
                        world[x][y] = '#';
            }



    for(int x=0 ; x < sizeX ; x++)
    {
        for(int y = 0 ; y < sizeY ; y++)
           std::cout << world[x][y];
        std::cout << std::endl;
    }

    for(int x=0 ; x < sizeX ; x++)
        for(int y = 0 ; y < sizeY ; y++)
        {
            if(world[x][y] == '#')
            {
                int type =1;
                if(world[x][y+1] == ' ')
                    type = 2;
                if (world[x][y-1] == ' ')
                    type = 3;

                all.push_back(new Wall( type) );
                all.back()->setPosition(sf::Vector2f(x * 128 ,  y * 128));
            }
        if(world[x][y] == ' ')
            {
                all.push_back(new Floor() );
                all.back()->setPosition(sf::Vector2f(x * 128 ,  y * 128));
            }
        }



    std::cout << "on start \n";

}
