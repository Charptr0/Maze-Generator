#include "text.h"

Text::Text()
{
    if(!font.loadFromFile("./Fonts/Roboto-Black.ttf"))
    {
        printf("Error loading font file");
        exit(1);
    }

    this->text.setFont(font);
    this->text.setColor(sf::Color::White);
    this->text.setCharacterSize(24);
}

Text::Text(const char string[])
{
    if(!font.loadFromFile("./Fonts/Roboto-Black.ttf"))
    {
        printf("Error loading font file");
        exit(1);
    }

    this->text.setFont(font);
    this->text.setColor(sf::Color::White);
    this->text.setCharacterSize(24);
    this->text.setString(string);
}

void Text::setString(const char string[])
{
    this->text.setString(string);
}

sf::Text Text::getText()
{
    return this->text;
}