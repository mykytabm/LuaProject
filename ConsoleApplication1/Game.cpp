#include "stdafx.h"
#include "Game.h"



Game* Game::instance = nullptr;

Game::Game(): l(LuaScript()),colliderManager(new CollisionManager())
{
}

void Game::Start()
{
	clock = new sf::Clock();
	l.Initialize();
	_window = new sf::RenderWindow(sf::VideoMode(1280,720),
		"Lua Game", sf::Style::Default);
	
}
Game* Game::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Game();
	}

	return instance;
}

void Game::Update()
{
	_event = new sf::Event;
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Dalelands Uncial.otf");
	sf::Text text;
	_dialogueText = new sf::Text();
	_dialogueText->setFont(font);
	_dialogueText->setCharacterSize(20);
	sf::RectangleShape dialogBackGround(sf::Vector2f(1100, 190));
	dialogBackGround.setFillColor(sf::Color::Black);
	/*text.setFont(font);
	text.setPosition(200, 200);
	text.setCharacterSize(100);
	text.setString("Hello SFML");*/
	_window->setVerticalSyncEnabled(true);
	_window->setFramerateLimit(60); while (_window->isOpen())

	while (_window->isOpen())
	{
		//rendering of sprites and dialogue text
		_window->clear();

		for (int i = 0; i < _spriteList.size(); i++)
		{

			_window->draw(*_spriteList[i]);
		}

		for (int i = 0; i < _objList.size(); i++)
		{
			
			_window->draw(_objList[i]->GetSprite());
		}
		if (showDialogue)
		{
			_dialogueText->setPosition(_window->getView().getCenter() + sf::Vector2f(-400, 200));
			dialogBackGround.setPosition(_dialogueText->getPosition()+sf::Vector2f(-150,0));
			_window->draw(dialogBackGround);
			_window->draw(*_dialogueText);
		}
		_window->display();

		//calling lua update method
		l.Update();

		//handling events
		if (_window->pollEvent(*_event))
		{
			if (_event->type == sf::Event::Closed)
				_window->close();
			if (_event->type == sf::Event::KeyPressed)
			{
				if (_event->key.code == sf::Keyboard::Escape)
				{
					std::cout << "the escape key was pressed" << std::endl;
					_window->close();
				}
			}
			KeyHandler::AddEvent(*_event);
		}


	}
}

sf::RenderWindow * Game::GetWindow()
{
	return _window;
}

sf::Time* Game::GetElapsedTime()
{
	return &clock->getElapsedTime();
}

CollisionManager * Game::GetCollManager()
{
	return colliderManager;
}

std::vector<GameObject*> Game::GetGameObjects()
{
	return _objList;
}

void Game::AddGameObject(GameObject* obj)
{
	_objList.push_back(obj);
}


void Game::AddSprite(sf::Sprite* obj)
{
	_spriteList.push_back(obj);
}

void Game::SetDialogueText(std::string s)
{
	_dialogueText->setString(s);
}

void Game::SetDialogueVisible(bool value)
{
	showDialogue = value;
}

void Game::Checking()
{
	std::cout << "Checking" << std::endl;
}
