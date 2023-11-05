#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

int text(){
    sf::Font font;
    font.loadFromFile()

}


int main ()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("tree.jpg"))
    {
        std::cout << "image load error" << std::endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::RectangleShape sprite2(sf::Vector2f(60.f, 150.f));
    sprite2.setFillColor(sf::Color(100, 250, 0));
    sprite2.setOrigin(30.f, 75.f);
    sprite2.setPosition(400, 300);

    sf::Music music;
    if (!music.openFromFile("music.mp3")) std::cout << "error";
    music.play();


    while (window.isOpen())
    {
        sf::Event event;
        window.clear();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }



        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sprite.move(1.0f, 0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sprite.move(-1.0f, 0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sprite.move(0.0f, 1.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite.move(0.0f, -1.0f);
        }



        window.draw(sprite);
        window.draw(sprite2);
        window.display();

    }


    return 0;

}
