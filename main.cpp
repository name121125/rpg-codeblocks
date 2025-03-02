#include "game.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


int main ()
{

    sf::Texture backtex;
    sf::Sprite background;

    if (!backtex.loadFromFile("tree.jpg"))
    {
        std::cout << "image load error" << std::endl;
    }
    background.setTexture(backtex);

    int window_x = 800, window_y = 600;
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), "first");
    window.setFramerateLimit(60);

    std::cout << "test" << "\n";

    sf::Music music;
    sf::Font font;
    sf::Text text;
    int rect_x = 60.0, rect_y = 150;

    srand(time(NULL));
    int x = rand() % ((window_x - (rect_x / 2)) - rect_x / 2 + 1) + rect_x / 2;
    int y = rand() % ((window_y - (rect_y / 2)) - rect_y / 2 + 1) + rect_y / 2;


    sf::RectangleShape subject(sf::Vector2f(rect_x, rect_y));
    subject.setPosition(0, 0);
    subject.setFillColor(sf::Color(100, 250, 0));
    subject.setOrigin(30.f, 75.f);
    subject.setPosition(x, y);
    subject.setPosition(50, 75);


    if (!music.openFromFile("music.mp3")) std::cout << "error";


    font.loadFromFile("Ubuntu-Bold.ttf");

    text.setFont(font);
    text.setString("Hello");

    sf::Event event;
    int score = 0;




    float hor_vel = 1.0;
    float ver_vel = 1.0;

    music.setVolume(50.0);
    music.play();

    while (window.isOpen())
    {


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        sf::Vector2f pos = subject.getPosition();
        sf::SoundSource::Status now = music.getStatus();


        if (now == sf::SoundSource::Status::Stopped) {
            std::cout << "total: " << score << "\n";
            return 0;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
            int mouse_x = mouse_pos.x;
            int mouse_y = mouse_pos.y;

            if (mouse_x - pos.x <= 30.0 && mouse_x - pos.x >= -30.0) {
                if (abs(mouse_y - pos.y ) <= 75.0) {
                    score++;
                    x = rand() % ((window_x - (rect_x / 2)) - rect_x / 2 + 1) + rect_x / 2;
                    y = rand() % ((window_y - (rect_y / 2)) - rect_y / 2 + 1) + rect_y / 2;
                    subject.setPosition(x, y);
                }
            }
        }

        /*if  (pos.x + 30>= 800) {
            hor_vel = -1.0;
        }
        if (pos.x - 30<= 0) {
            hor_vel = 1.0;
        }
        if (pos.y + 75>= 600 ) {
            ver_vel = -1.0;
        }
        if (pos.y - 75 <= 0) {
            ver_vel = 1.0;
        }

        subject.move(hor_vel, ver_vel);*/
        text.setString("Hello World");
        window.clear();

        window.draw(background);
        window.draw(subject);
        window.draw(text);
        window.display();
    }

    return 0;

}
