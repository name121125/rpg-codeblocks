#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio.hpp>
#include <iostream>



class Game {
	private:


	public:
		Game();
		virtual ~Game() ;
		void initSubjects();
		void update();
		void render();

		void pollEvents();
        //window
		sf::RenderWindow* window;
		sf::Event event;
		void initvariables();
		void initWindow();
		//game subjects
		sf::Texture backtex;
		sf::Sprite background;
		sf::RectangleShape* subject;
		//other stuff
		sf::Music music;
		sf::Font font;
		sf::Text text;








};
#endif

