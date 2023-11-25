#include "game.hpp"




int main ()
{


    //Game game;

    //game.update();

    sf::RenderWindow window(sf::VideoMode(800, 600), "first");
    window.setFramerateLimit(60);
    sf::Texture backtex;
    sf::Sprite background;
    sf::Music music;
    sf::Font font;
    sf::Text text;



    if (!backtex.loadFromFile("tree.jpg"))
    {
        std::cout << "image load error" << std::endl;
    }

    background.setTexture(backtex);

    sf::RectangleShape subject(sf::Vector2f(60.f, 150.f));
    subject.setFillColor(sf::Color(100, 250, 0));
    subject.setOrigin(30.f, 75.f);
    subject.setPosition(400, 300);


    if (!music.openFromFile("music.mp3")) std::cout << "error";
    music.play();

    font.loadFromFile("Ubuntu-Bold.ttf");

    text.setFont(font);
    text.setString("Hello");



    sf::Event event;

    std::cout << "in";
    while (window.isOpen())
    {


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)||sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
           background.move(1.0f, 0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            background.move(-1.0f, 0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            background.move(0.0f, 1.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            background.move(0.0f, -1.0f);
        }

        text.setString("Hello World");
        window.clear();
        window.draw(background);
        window.draw(subject);

        window.draw(text);
        window.display();
    }

    return 0;

}
