#include <vector>
#include "config.cpp"
#include "grid.cpp"
#include <SFML/Graphics.hpp>

const int CURRENT_RESOLUTION[2] = {RESOLUTIONS_V2[Axis::x], RESOLUTIONS_V2[Axis::y]}; //set resolution
const int SIDE_LENGTH = SIDE_LENGTH_V2; //set side of square
const int WALL_LENGTH = WALL_LENGTH_V2; //set the side of the wall

//event grabber SFML boiler code
void grabEvent(sf::RenderWindow &screen)
{
    sf::Event event;
    while(screen.pollEvent(event))
    {
        if(event.type == sf::Event::Closed) 
        {
            screen.close();
            exit(0);
        }
    }
}

//draw the maze to screen
void draw(sf::RenderWindow &screen, vector<vector<Cell>>&grid)
{
    int posX = 0;
    int posY = 0;

    for(int i = 0; i < grid.size(); i++)
    {
        grabEvent(screen);

        posX = 0;

        for(int j = 0; j < grid[i].size(); j++)
        {
            sf::RectangleShape r;
            r.setPosition(sf::Vector2f(posX,posY));
            r.setSize(sf::Vector2f(SIDE_LENGTH,SIDE_LENGTH));

            if(grid[i][j].cursor) r.setFillColor(sf::Color::Green); //current square that the program is on
            else if(grid[i][j].visited) r.setFillColor(sf::Color::White); //traversed squares
            else r.setFillColor(sf::Color::Black);

            screen.draw(r); //draw the square to screen

            posX += WALL_LENGTH + SIDE_LENGTH; //increase the posX
        }

        screen.display();
        posY += WALL_LENGTH + SIDE_LENGTH;
    }
}

void dfs(sf::RenderWindow &screen, vector<vector<Cell>>&grid, int row = 0, int col = 0)
{
    if(row >= grid.size() || col >= grid[0].size()) return;

    grabEvent(screen);

    grid[row][col].visited = true; //currently visiting the node

    vector<int>freeSpaces = aviliableSpaces(grid, row, col); //add all directions that has not been traversed

    while(!freeSpaces.empty())
    {
        grid[row][col].cursor = true;

        draw(screen, grid);

        grid[row][col].cursor = false;

        int index = randomIndex(freeSpaces.size());
        int direction = freeSpaces[index];

        switch(direction)
        {
            case Directions::UP:
                grid[row][col].upConnected = true;
                dfs(screen, grid, row + 1, col);
                break;

            case Directions::DOWN:
                grid[row][col].downConnected = true;
                dfs(screen, grid, row - 1, col);
                break;

            case Directions::LEFT:
                grid[row][col].leftConnected = true;
                dfs(screen, grid, row, col - 1);
                break;

            case Directions::RIGHT:
                grid[row][col].rightConnected = true;
                dfs(screen, grid, row, col + 1);
                break;
        }

        freeSpaces.erase(freeSpaces.begin() + index);
    }
}

int main()
{
    sf::RenderWindow screen;

    screen.create(sf::VideoMode(CURRENT_RESOLUTION[Axis::x], CURRENT_RESOLUTION[Axis::y]), TITLE);
    screen.setFramerateLimit(MAX_FRAMERATE);

    //create grid for the maze
    vector<vector<Cell>> grid = generateGrid(CURRENT_RESOLUTION, SIDE_LENGTH, WALL_LENGTH);

    while(screen.isOpen())
    {
        screen.clear();

        grabEvent(screen);

        dfs(screen, grid);

        screen.display(); //update the screen
    }
}