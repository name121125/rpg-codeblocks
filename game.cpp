#include "game.hpp"


void Game::initvariables() {
    this->window = nullptr;

}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game");
    this->window->setFramerateLimit(60);
}

void Game::initSubjects() {

    if (!backtex.loadFromFile("tree.jpg"))
    {
        std::cout << "image load error" << std::endl;
    }

    this->background.setTexture(backtex);

    this->subject = new sf::RectangleShape(sf::Vector2f(60.f, 150.f));
    subject->setFillColor(sf::Color(100, 250, 0));
    subject->setOrigin(30.f, 75.f);
    subject->setPosition(400, 300);


    if (!music.openFromFile("music.mp3")) std::cout << "error";
    music.play();

    font.loadFromFile("Ubuntu-Bold.ttf");

    text.setFont(font);
    text.setString("Hello");

}

Game::Game() {
    this->initvariables();
    this->initWindow();
    this->initSubjects();
}

Game::~Game() {
    delete this->window;

}

void Game::pollEvents() {
    sf::Event event;
    this->window->clear();
    while (this->window->isOpen())
    {







        while (this->event.type)
        {
            if (event.type == sf::Event::Closed)
            {
                this->window->close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                this->subject->move(1.0f, 0.0f);
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


        }
        this->text.setString("Hello World");
        this->window->draw(background);
        //this->window->draw(subject);

        //this->window->draw(text);
        this->window->display();
    }
}

void Game::update() {
    this->pollEvents();

}

void Game::render() {


}
