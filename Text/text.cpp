#include "text.h"

Text::Text()
{
    if(!font.loadFromFile("./Text/Fonts/Roboto-Black.ttf"))
    {
        printf("Error loading font file\n");
        exit(1);
    }

    this->text.setFont(font);
    this->text.setFillColor(sf::Color::Green);
    this->text.setCharacterSize(this->CHAR_SIZE);
}

Text::Text(const char string[])
{
    if(!font.loadFromFile("./Text/Fonts/Roboto-Black.ttf"))
    {
        printf("Error loading font file\n");
        exit(1);
    }

    this->text.setFont(font);
    this->text.setFillColor(sf::Color::Green);
    this->text.setCharacterSize(this->CHAR_SIZE);
    this->text.setString(string);
}

void Text::updateString(const char string[])
{
    this->text.setString(string);
}

void Text::setPosition(const int posX, const int posY)
{
    this->text.setPosition(sf::Vector2f(posX, posY));
}

sf::Text Text::getText()
{
    return this->text;
}