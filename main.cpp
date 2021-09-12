#include "config.cpp"
#include "grid.cpp"
#include <SFML/Graphics.hpp>

const int CURRENT_RESOLUTION[2] = {RESOLUTIONS_MEDIUM[Axis::x], RESOLUTIONS_MEDIUM[Axis::y]}; //set resolution
const int SIDE_LENGTH = SIDE_LENGTH_LARGE; //set side of square
const int WALL_LENGTH = WALL_LENGTH_LARGE; //set the side of the wall

bool mazeCompleted = false;

//event grabber SFML boiler code
void grabEvent(sf::RenderWindow &screen, vector<vector<Cell>>&grid)
{
    sf::Event event;
    while(screen.pollEvent(event))
    {
        //close the program
        if(event.type == sf::Event::Closed) 
        {
            screen.close();
            exit(0);
        }

        if(event.type == sf::Event::KeyReleased)
        {
            if(mazeCompleted) 
            {
                grid.clear();
                grid.shrink_to_fit();

                grid = generateGrid(CURRENT_RESOLUTION, SIDE_LENGTH, WALL_LENGTH);

                mazeCompleted = false;
            }
        }
    }
}

//draw the maze to screen
void draw(sf::RenderWindow &screen, vector<vector<Cell>>&grid)
{
    int posX = 0;
    int posY = 0;
    
    //traverse thru the grid
    for(int i = 0; i < grid.size(); i++)
    {
        grabEvent(screen, grid);

        posX = 0; //reset the x position to the far left

        for(int j = 0; j < grid[i].size(); j++)
        {
            //set the cell postion and the size
            sf::RectangleShape square;
            square.setPosition(sf::Vector2f(posX,posY));
            square.setSize(sf::Vector2f(SIDE_LENGTH,SIDE_LENGTH));

            if(grid[i][j].cursor) square.setFillColor(sf::Color::Green); //current square that the program is on
            else if(grid[i][j].visited) square.setFillColor(sf::Color::White); //visited squares
            else square.setFillColor(sf::Color::Red); //untouched squares

            //walls
            sf::RectangleShape right_wall;
            sf::RectangleShape left_wall;
            sf::RectangleShape up_wall;
            sf::RectangleShape down_wall;

            right_wall.setFillColor(sf::Color::White);
            right_wall.setSize(sf::Vector2f(SIDE_LENGTH,SIDE_LENGTH));

            left_wall.setFillColor(sf::Color::White);
            left_wall.setSize(sf::Vector2f(SIDE_LENGTH,SIDE_LENGTH));

            up_wall.setFillColor(sf::Color::White);
            up_wall.setSize(sf::Vector2f(SIDE_LENGTH,SIDE_LENGTH));

            down_wall.setFillColor(sf::Color::White);
            down_wall.setSize(sf::Vector2f(SIDE_LENGTH,SIDE_LENGTH));

            //set the position of those walls based on the connections of the squares
            if(grid[i][j].rightConnected) right_wall.setPosition(sf::Vector2f(posX + WALL_LENGTH,posY));
            if(grid[i][j].leftConnected) left_wall.setPosition(sf::Vector2f(posX - WALL_LENGTH,posY));
            if(grid[i][j].upConnected) up_wall.setPosition(sf::Vector2f(posX,posY + WALL_LENGTH));
            if(grid[i][j].downConnected) down_wall.setPosition(sf::Vector2f(posX ,posY - WALL_LENGTH));

            screen.draw(square); //draw the square to screen
            screen.draw(right_wall); //draw right wall if exist
            screen.draw(left_wall); //draw left wall if exist
            screen.draw(up_wall); //draw up wall if exist
            screen.draw(down_wall); //draw down wall if exist

            posX += WALL_LENGTH + SIDE_LENGTH; //increase the posX
        }

        screen.display(); //update the screen

        posY += WALL_LENGTH + SIDE_LENGTH; //increase the y position
    }
}

void dfs(sf::RenderWindow &screen, vector<vector<Cell>>&grid, int row = 0, int col = 0)
{
    if(row >= grid.size() || col >= grid[0].size()) return; //base case

    grabEvent(screen, grid);

    grid[row][col].visited = true; //mark the cell as visited

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

        freeSpaces = aviliableSpaces(grid, row, col);
    }
}

//depending on the x value of the resolution, make sure the txt is centered
void alignText()
{
    const int X_VALUE = CURRENT_RESOLUTION[Axis::x];

    switch(X_VALUE)
    {
        case 600:
            restartTxt->setPosition(CURRENT_RESOLUTION[Axis::x] * 0.2, CURRENT_RESOLUTION[Axis::y] * 0.4);
            break;

        case 800:
            restartTxt->setPosition(CURRENT_RESOLUTION[Axis::x] * 0.3, CURRENT_RESOLUTION[Axis::y] * 0.4);
            break;

        case 1000:
            restartTxt->setPosition(CURRENT_RESOLUTION[Axis::x] * 0.33, CURRENT_RESOLUTION[Axis::y] * 0.4);
            break;

        default: //unknown resolution, set it to the top left
            restartTxt->setPosition(0, 0);
            break;
    }
}

int main()
{
    sf::RenderWindow screen;

    //create the screen, with resolution, title, and the ability to resize is disabled
    screen.create(sf::VideoMode(CURRENT_RESOLUTION[Axis::x], 
                    CURRENT_RESOLUTION[Axis::y]), 
                    TITLE, 
                    sf::Style::Close);

    screen.setFramerateLimit(MAX_FRAMERATE); //cap the framerate of the program (preferred: 60-100fps)

    alignText();

    //create grid for the maze
    vector<vector<Cell>> grid = generateGrid(CURRENT_RESOLUTION, SIDE_LENGTH, WALL_LENGTH);

    while(screen.isOpen())
    {
        grabEvent(screen, grid);

        if(!mazeCompleted)
        {
            screen.clear();

            dfs(screen, grid);
            draw(screen, grid);

            mazeCompleted = true;
        }

        screen.draw(restartTxt->getText());

        screen.display(); //update the screen
    }
}