#pragma once

#include <SFML/Graphics/Text.hpp>

class Text
{
    private:
        sf::Text text;
        sf::Font font;

    public:
        Text(); //default constructor

        Text(const char string[]);

        void setString(const char string[]);

        sf::Text getText();
};