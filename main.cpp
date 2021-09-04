#include <iostream>
#include "constants.h"
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(RESOLUTION_X, RESOLUTION_Y), TITLE);

    while(screen.isOpen())
    {
        sf::Event event;
        while(screen.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) screen.close();
        }
    }
}

