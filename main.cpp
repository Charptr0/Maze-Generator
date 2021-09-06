#include <vector>
#include "config.cpp"
#include "grid.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>

//event grabber SFML boiler code
void grabEvent(sf::RenderWindow &screen)
{
    sf::Event event;
    while(screen.pollEvent(event))
    {
        if(event.type == sf::Event::Closed) screen.close();
    }
}

//draw the maze to screen
void drawBlocks(sf::RenderWindow &screen, const int RESOLUTION[2], const int SIDE_LENGTH, const int WALL_LENGTH, vector<vector<int>>&grid)
{
    int posX = 0;
    int posY = 0;

    for(int i = 0; i < grid.size(); i++)
    {
        posX = 0;

        for(int j = 0; j < grid[i].size(); j++)
        {
            sf::RectangleShape r;

            if(grid[i][j] == 1)
            {
                r.setPosition(sf::Vector2f(posX,posY));
                r.setFillColor(sf::Color::Green);
                r.setSize(sf::Vector2f(SIDE_LENGTH,SIDE_LENGTH));
            }

            else
            {
                r.setPosition(sf::Vector2f(posX,posY));
                r.setFillColor(sf::Color::White);
                r.setSize(sf::Vector2f(SIDE_LENGTH,SIDE_LENGTH));
            }

            screen.draw(r);
            posX += WALL_LENGTH + SIDE_LENGTH;
        }

        posY += WALL_LENGTH + SIDE_LENGTH;
    }
}

int main()
{
    sf::RenderWindow screen;

    const int CURRENT_RESOLUTION[2] = {RESOLUTIONS_V2[Axis::x], RESOLUTIONS_V2[Axis::y]}; //set resolution
    const int SIDE_LENGTH = SIDE_LENGTH_V2; //set side of square
    const int WALL_LENGTH = WALL_LENGTH_V2; //set the side of the wall

    screen.create(sf::VideoMode(CURRENT_RESOLUTION[Axis::x], CURRENT_RESOLUTION[Axis::y]), TITLE);
    screen.setFramerateLimit(MAX_FRAMERATE);

    //create grid for the maze
    vector<vector<int>> grid = generateGrid(CURRENT_RESOLUTION, SIDE_LENGTH, WALL_LENGTH);

    while(screen.isOpen())
    {
        screen.clear();

        grabEvent(screen);

        drawBlocks(screen, CURRENT_RESOLUTION, SIDE_LENGTH, WALL_LENGTH, grid);

        screen.display(); //update the screen
    }
}

