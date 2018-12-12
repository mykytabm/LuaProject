#pragma once
#include <iostream>
#include <map>
#include <list>
#include "../SFML-2.4.2/SFML-2.4.2/include/SFML/Graphics.hpp"
class KeyHandler
{
public:
	KeyHandler();
	~KeyHandler();

	static bool KeyDown(std::string s);
	static bool KeyUp(std::string s);
	void EventLoop();
	void SetEvent(sf::Event* event);
	static bool KeyPressed(std::string key);
	static void AddEvent(sf::Event event);


private:
	sf::Keyboard::Key GetKey(std::string s);
	sf::RenderWindow* _window;
	sf::Event* _event;
	static std::vector <sf::Event> _eventList;
	static std::map< std::string, sf::Keyboard::Key > _keyMap;
	/*{ { sf::Keyboard::A, "A" }, };*/
};

