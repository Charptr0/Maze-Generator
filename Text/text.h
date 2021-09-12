#pragma once

#include <SFML/Graphics/Text.hpp>

class Text
{
    private:
        sf::Text text;
        sf::Font font;
        const int CHAR_SIZE = 30;

    public:
        Text(); //default constructor

        //constructor with a string parm
        Text(const char string[]);

        void updateString(const char string[]);

        void setPosition(const int posX, const int posY);

        sf::Text getText();
};