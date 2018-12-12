#pragma once
#include "../SFML-2.4.2/SFML-2.4.2/include/SFML/Graphics.hpp"
#include "LuaScript.h"
#include <iostream>
#include "GameObject.h"
#include "KeyHandler.h"
#include "CollisionManager.h"
#include "Collider.h"

class Game
{
public:
	static Game* GetInstance();

	void Start();
	void Update();
	void Checking();
	void AddGameObject(GameObject*);
	void AddSprite(sf::Sprite*);
	void SetDialogueText(std::string s);
	void SetDialogueVisible(bool value);

	sf::RenderWindow* GetWindow();
	sf::Time* GetElapsedTime();
	CollisionManager* GetCollManager();

	std::vector<GameObject*> GetGameObjects();

private:
	Game();
	sf::Text* _dialogueText;
	bool showDialogue;
	sf::Clock* clock;
	sf::Event* _event;
	static Game* instance;
	std::vector<GameObject*> _objList=std::vector<GameObject*>();
	std::vector<sf::Sprite*> _spriteList = std::vector<sf::Sprite*>();
	sf::RenderWindow* _window;
	KeyHandler keyHandler;
	CollisionManager* colliderManager;
	LuaScript l;
};

